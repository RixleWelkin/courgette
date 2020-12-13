#include <iostream>
#include "Point.h"
#include "Segment.h"
#include "Figure.h"

inline float min(float x, float y) { return (x < y) ? x : y; }
inline float max(float x, float y) { return (x >= y) ? x : y; }
//            _    _  _                     _    _           _
//  ___  _ _ | |_ | |<_> ___  ._ _ _  ___ _| |_ | |_  ___  _| | ___
// | . \| | || . \| || |/ | ' | ' ' |/ ._> | |  | . |/ . \/ . |<_-<
// |  _/`___||___/|_||_|\_|_. |_|_|_|\___. |_|  |_|_|\___/\___|/__/
// |_|
Figure::Figure(const int width, const int height) : width(width), height(height) {
    buffer = new int[width * height];
    clearBuffer();
  }

Figure::~Figure() {
    if (buffer != nullptr) {
      delete buffer;
    }
  }

void Figure::draw() const {
    for (int line = 0; line < height; line++) {
      for (int col = 0; col < width; col++) {
        std::cout << buffer[line * width + col] << " ";
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
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

//Classes derivees utilisant drawSegment
#include "Croix.h"
#include "Rectangle.h"
#include "Carre.h"
// ___            _             _            _        __  __       _    _             _     
//| _ \ _ _  ___ | |_  ___  __ | |_  ___  __| |      |  \/  | ___ | |_ | |_   ___  __| | ___
//|  _/| '_|/ _ \|  _|/ -_)/ _||  _|/ -_)/ _` |      | |\/| |/ -_)|  _||   \ / _ \/ _` |(_-/
//|_|  |_|  \___/ \__|\___|\__| \__|\___|\__/_|      |_|  |_|\___| \__||_||_|\___/\__/_|/__/

 bool Figure::setPoint(const int col, const int line) {
    if (col < 0 || col >= width || line < 0 || line >= height) {
      return false;
    }
    buffer[line * width + col] = 1;
    return true;
  }

    bool Figure::clearPoint(const int col, const int line) {
    if (col < 0 || col >= width || line < 0 || line >= height) {
      return false;
    }
    buffer[line * width + col] = 0;
    return true;
  }

    void Figure::clearBuffer() {
    for (int line = 0; line < height; line++) {
      for (int col = 0; col < width; col++) {
        buffer[line * width + col] = 0;
      }
    }
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
// __  __        _       
//|  \/  | __ _ (_) _ _  
//| |\/| |/ _` || || ' \ 
//|_|  |_|\__/_||_||_||_|

int main(int, char **) {
  const int width = 11;
  const int height = 15;

  Cross cross(width, height);
  cross.draw();

  Rectangle rectangle(width, height);
  rectangle.draw();

  Carre carre(height);
  carre.draw();

  Point point(width / 2, height / 2);

  Figure figPoint(width, height);
  figPoint.drawPoint(point, 5);
  figPoint.draw();

  return 0;
}