#include <iostream>
#include <string>
#include "Drawing.h"
#include "Figure.h"
#include "Croix.h"
#include "Rectangle.h"
#include "Carre.h"


// __  __        _       
//|  \/  | __ _ (_) _ _  
//| |\/| |/ _` || || ' \ 
//|_|  |_|\__/_||_||_||_|
//
int main(int argc, char **argv)
{
  
  const int width = 500;
  const int height = 500;
  //Croix cross(50, 50);
  //cross.draw();

   Rectangle rectangle(200, 300);
  //rectangle.draw();

  //Carre carre(300);
  //carre.draw();

  //Point point(width / 2, height / 2);

  //Figure figPoint(width, height);
  //figPoint.drawPoint(point, 5);
  //figPoint.draw();

  Drawing draw(width, height);
 
  draw.DrawCanva(rectangle.figure,rectangle.hauteur,rectangle.largeur,50,100);
  draw.save(std::string("test_image.bmp"));

  return 0;
}