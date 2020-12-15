#include <iostream>
#include "Drawing.h"
#include "Point.h"
#include "Segment.h"
#include "Figure.h"
#include "Croix.h"
#include "Rectangle.h"
#include "Carre.h"
inline float min(float x, float y) { return (x < y) ? x : y; }
inline float max(float x, float y) { return (x >= y) ? x : y; }
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

 Point::Point(float x0, float y0) {
    x = x0;
    y = y0;
  }

void Segment::afficher() const {
  std::cout << "origine(" << org.getX() << "," << org.getY() << ")"
            << ", extremite(" << ext.getX() << "," << ext.getY() << ")"
            << std::endl;
}

Point Segment::getOrigin() const { return org; }

Point Segment::getDest() const { return ext; }
//            _    _  _                     _    _           _
//  ___  _ _ | |_ | |<_> ___  ._ _ _  ___ _| |_ | |_  ___  _| | ___
// | . \| | || . \| || |/ | ' | ' ' |/ ._> | |  | . |/ . \/ . |<_-<
// |  _/`___||___/|_||_|\_|_. |_|_|_|\___. |_|  |_|_|\___/\___|/__/
// |_|
Figure::Figure(const int width, const int height) : width(width), height(height) {
    figure.resize(width * height);
  }

Figure::~Figure() {}

void Figure::draw() const {
    for (int line = 0; line < height; line++) {
      for (int col = 0; col < width; col++) {
        //figure[line * width + col]=(line+col) % 256;
      }
    }
  }

void Figure::drawPoint(const Point &point, const float thickness = 1) {
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
void Figure::drawSegment(const Segment &segment, const float thickness = 1.f) {

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

// ___            _             _            _        __  __       _    _             _     
//| _ \ _ _  ___ | |_  ___  __ | |_  ___  __| |      |  \/  | ___ | |_ | |_   ___  __| | ___
//|  _/| '_|/ _ \|  _|/ -_)/ _||  _|/ -_)/ _` |      | |\/| |/ -_)|  _||   \ / _ \/ _` |(_-/
//|_|  |_|  \___/ \__|\___|\__| \__|\___|\__/_|      |_|  |_|\___| \__||_||_|\___/\__/_|/__/

 bool Figure::setPoint(const int col, const int line) {
    if (col < 0 || col >= width || line < 0 || line >= height) {
      return false;
    }
    figure[line * width + col] = 255;
    return true;
  }

    bool Figure::clearPoint(const int col, const int line) {
    if (col < 0 || col >= width || line < 0 || line >= height) {
      return false;
    }
    figure[line * width + col] = 0;
    return true;
  }


    bool Figure::drawVertLine(const int col) {
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

    bool Figure::drawHorLine(const int line) {
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

//Classes derivees utilisant drawSegment
//  ___  _                               ___             _                    
// / __|| | __ _  ___ ___ ___  ___      |   \  ___  _ _ (_)__ __ ___  ___  ___
//| (__ | |/ _` |(_-/(_-// -_)(_-/      | |) |/ -_)| '_|| |\ V // -_)/ -_)(_-/
 //\___||_|\__/_|/__//__/\___|/__/      |___/ \___||_|  |_| \_/ \___|\___|/__/

Rectangle::Rectangle(const int width, const int height): Figure(width, height){
    Point pointHautGauche(0, 0);
    Point pointHautDroit(width - 1, 0);
    Point pointBasGauche(0, height - 1);
    Point pointBasDroit(width - 1, height - 1);

    drawSegment(Segment(pointHautGauche, pointHautDroit));
    drawSegment(Segment(pointHautDroit, pointBasDroit));
    drawSegment(Segment(pointBasDroit, pointBasGauche));
    drawSegment(Segment(pointBasGauche, pointHautGauche));
  }

  Croix::Croix(const int width, const int height): Figure(width, height){
    drawSegment(Segment(Point(width / 2, 0), Point(width / 2, height - 1)));
    drawSegment(Segment(Point(0, height / 2), Point(width - 1, height / 2)));
  }