#include <iostream>
#include "Figure.h"
#include "Point.h"
#include "Segment.h"
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

void Segment::afficher() const {
  std::cout << "origine(" << org.getX() << "," << org.getY() << ")"
            << ", extremite(" << ext.getX() << "," << ext.getY() << ")"
            << std::endl;
}

Point Segment::getOrigin() const { return org; }

Point Segment::getDest() const { return ext; }

Figure::~Figure(){
  if (buffer != nullptr) {
      delete buffer;
    }
}

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
