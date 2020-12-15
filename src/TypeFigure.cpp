#include <iostream>
#include "Point.h"
#include "Segment.h"
#include "Croix.h"
#include "Rectangle.h"
#include "Carre.h"

Rectangle::Rectangle(const int width, const int height){
    Point pointHautGauche(0, 0);
    Point pointHautDroit(width - 1, 0);
    Point pointBasGauche(0, height - 1);
    Point pointBasDroit(width - 1, height - 1);

    drawSegment(Segment(pointHautGauche, pointHautDroit));
    drawSegment(Segment(pointHautDroit, pointBasDroit));
    drawSegment(Segment(pointBasDroit, pointBasGauche));
    drawSegment(Segment(pointBasGauche, pointHautGauche));
  }

  Cross::Cross(const int width, const int height){
    drawSegment(Segment(Point(width / 2, 0), Point(width / 2, height - 1)));
    drawSegment(Segment(Point(0, height / 2), Point(width - 1, height / 2)));
  }