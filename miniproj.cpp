#include <iostream>
#include <string>
#include "Drawing.h"
#include "Point.h"
#include "Segment.h"
#include "Figure.h"
#include "Croix.h"
#include "Rectangle.h"
#include "Carre.h"


const int width = 500;
const int height = 100;
// __  __        _       
//|  \/  | __ _ (_) _ _  
//| |\/| |/ _` || || ' \ 
//|_|  |_|\__/_||_||_||_|
//
int main(int argc, char **argv)
{
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

  Drawing draw(width, height);

  draw.save(std::string("test_image.bmp"));

  return 0;
}