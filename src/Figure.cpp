#include <iostream>
#include "Figure.h"
#include "Point.h"
#include "Segment.h"
#include "Croix.h"
#include "Rectangle.h"
#include "Carre.h"

inline float min(float x, float y) { return (x < y) ? x : y; }
inline float max(float x, float y) { return (x >= y) ? x : y; }

class Point {
public:
  Point(float x0, float y0) {
    x = x0;
    y = y0;
  }

  float getX() const { return x; }
  float getY() const { return y; }

  void setX(float nx) { x = nx; }
  void setY(float ny) { y = ny; }

private:
  float x, y;
};

class Segment {
public:
  Segment(const Point &a, const Point &b);
  void translation(const Point &nouvOrg);
  void afficher() const;

  Point getOrigin() const;
  Point getDest() const;

private:
  Point org, ext;
};






Segment::Segment(const Point &a, const Point &b)
    : org(a.getX(), a.getY()), ext(b.getX(), b.getY())

{}

void Segment::translation(const Point &nouvOrg) {

  float dx = nouvOrg.getX() - org.getX();
  float dy = nouvOrg.getY() - org.getY();

  org.setX(nouvOrg.getX());
  org.setY(nouvOrg.getY());

  ext.setX(ext.getX() + dx);
  ext.setY(ext.getY() + dy);







}

void Segment::afficher() const {
  std::cout << "origine(" << org.getX() << "," << org.getY() << ")"
            << ", extremite(" << ext.getX() << "," << ext.getY() << ")"
            << std::endl;
}

Point Segment::getOrigin() const { return org; }

Point Segment::getDest() const { return ext; }

class Figure {
public:
  Figure(const int width, const int height) : width(width), height(height) {
    buffer = new int[width * height];
    clearBuffer();
  }

  ~Figure() {
    if (buffer != nullptr) {
      delete buffer;
    }
  }

  void draw() const {
    for (int line = 0; line < height; line++) {
      for (int col = 0; col < width; col++) {
        std::cout << buffer[line * width + col] << " ";
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }

  void drawPoint(const Point &point, const float thickness = 1) {
    for (int line = 0; line < height; line++) {
      for (int col = 0; col < width; col++) {


        float squaredVertDistance =
            (line - point.getY()) * (line - point.getY());
        float squaredHorDistance = (col - point.getX()) * (col - point.getX());



        if (squaredVertDistance + squaredHorDistance < thickness * thickness) {
          setPoint(col, line);
        }
      }
    }
  }

  void drawSegment(const Segment &segment, const float thickness = 1.f) {


    Point point1 = (segment.getDest().getX() < segment.getOrigin().getX())
                       ? segment.getDest()
                       : segment.getOrigin();


    Point point2 = (point1.getX() == segment.getDest().getX())
                       ? segment.getOrigin()
                       : segment.getDest();


    float dx = point1.getX() - point2.getX();
    float dy = point1.getY() - point2.getY();


    for (int x = point1.getX(); x <= point2.getX(); x++) {

      for (int y = 0; y < height; y++) {
        float dist;




        if ((dx == 0) ||
            (labs((float)y - (float)segment.getOrigin().getY() +
                  (float)dy * (float)(x - segment.getDest().getX()) /
                      (float)dx) < 1)) {
          drawPoint(Point(x, y), thickness);
        }
      }
    }
  }

protected:
  bool setPoint(const int col, const int line) {
    if (col < 0 || col >= width || line < 0 || line >= height) {
      return false;
    }
    buffer[line * width + col] = 1;
    return true;
  }

  bool clearPoint(const int col, const int line) {
    if (col < 0 || col >= width || line < 0 || line >= height) {
      return false;
    }
    buffer[line * width + col] = 0;
    return true;
  }

  void clearBuffer() {
    for (int line = 0; line < height; line++) {
      for (int col = 0; col < width; col++) {
        buffer[line * width + col] = 0;
      }
    }
  }

  bool drawVertLine(const int col) {
    if (col < 0 || col >= width) {
      return false;
    }

    for (int counter = 0; counter < height; counter++) {
      if (!setPoint(col, counter)) {
        std::cout << "Unable to set point : [" << col << ", " << counter << "]"
                  << std::endl;
      }
    }
    return true;
  }

  bool drawHorLine(const int line) {
    if (line < 0 || line >= height) {
      return false;
    }

    for (int counter = 0; counter < width; counter++) {
      if (!setPoint(counter, line)) {
        std::cout << "Unable to set point : [" << counter << ", " << line << "]"
                  << std::endl;
      }
    }
    return true;
  }

protected:
  int *buffer;

  int width;
  int height;
};

class Cross : public Figure {
public:
  Cross(const int width, const int height) : Figure(width, height) {
    drawSegment(Segment(Point(width / 2, 0), Point(width / 2, height - 1)));
    drawSegment(Segment(Point(0, height / 2), Point(width - 1, height / 2)));
  }

  void draw() const {
    std::cout << "Affichage d'une croix : " << std::endl << std::endl;
    Figure::draw();
  }
};

class Rect : public Figure {
public:
  Rect(const int width, const int height) : Figure(width, height) {
    Point pointHautGauche(0, 0);
    Point pointHautDroit(width - 1, 0);
    Point pointBasGauche(0, height - 1);
    Point pointBasDroit(width - 1, height - 1);

    drawSegment(Segment(pointHautGauche, pointHautDroit));
    drawSegment(Segment(pointHautDroit, pointBasDroit));
    drawSegment(Segment(pointBasDroit, pointBasGauche));
    drawSegment(Segment(pointBasGauche, pointHautGauche));
  }

  void draw() const {
    std::cout << "Affichage d'un rectangle : " << std::endl << std::endl;
    Figure::draw();
  }
};

class Carre : public Rect {
public:
  Carre(const int size) : Rect(size, size) {}

  void draw() const {
    std::cout << "Affichage d'un carrÃ© : " << std::endl << std::endl;
    Figure::draw();
  }
};

int main(int, char **) {
  const int width = 11;
  const int height = 15;

  Cross cross(width, height);
  cross.draw();

  Rect rect(width, height);
  rect.draw();

  Carre carre(height);
  carre.draw();

  Point point(width / 2, height / 2);

  Figure figPoint(width, height);
  figPoint.drawPoint(point, 5);
  figPoint.draw();

  return 0;
}