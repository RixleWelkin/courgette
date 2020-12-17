#include <iostream>
#include "Drawing.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>
#include <stdexcept>
class Figure;
//            _    _  _                     _    _           _
//  ___  _ _ | |_ | |<_> ___  ._ _ _  ___ _| |_ | |_  ___  _| | ___
// | . \| | || . \| || |/ | ' | ' ' |/ ._> | |  | . |/ . \/ . |<_-<
// |  _/`___||___/|_||_|\_|_. |_|_|_|\___. |_|  |_|_|\___/\___|/__/
// |_|

Drawing::Drawing(const int width, const int height)
    : width(width), height(height)
{
  image.resize(width * height);
  clearBuffer();
}

Drawing::~Drawing() {}

/* Save image to file "filename" */
void Drawing::save(std::string filename)
{
  if (filename.substr(filename.find_last_of(".") + 1) != "bmp")
  {
    throw std::runtime_error("Drawing ne supporte que l'enregistrement d'images au format bmp");
  }
  stbi_write_bmp(filename.c_str(), width, height, 1, image.data());
}
void Drawing::DrawCanva(std::vector<char> figure,int hauteur, int largeur, int posx, int posy)
{
    for (int j = 0; j < hauteur; j++)
  {
    for (int i = 0; i < largeur; i++)
    {
    if(figure[j*largeur+i]==1)
     image[(j+posy)*width+(i+posx)]=figure[j*largeur+i];
    }
  }
}
/*void Drawing::AjoutCanva(Figure f,int x, int y){
figures[pos]=f;
coords[pos]=x;
coords[pos+1]=y;
pos++;
}*/
//            _             _                      _    _           _
//  ___  _ _ <_> _ _  ___ _| |_ ___  ._ _ _  ___ _| |_ | |_  ___  _| | ___
// | . \| '_>| || | |<_> | | | / ._> | ' ' |/ ._> | |  | . |/ . \/ . |<_-<
// |  _/|_|  |_||__/ <___| |_| \___. |_|_|_|\___. |_|  |_|_|\___/\___|/__/
// |_|

/* Set every point of the image to 0 */
void Drawing::clearImage()
{
  for (std::vector<char>::iterator it = image.begin(); it != image.end();it++)
  {
    *it = 0;
  }
}

/* Set image to test */
void Drawing::createTestImage()
{
  for (int j = 0; j < height; j++)
  {
    for (int i = 0; i < width; i++)
    {
      image[j * width + i] = (i + j) % 256;
    }
  }
}

void Drawing::createFigureImage()
{
  for (int j = 0; j < height; j++)
  {
    for (int i = 0; i < width; i++)
    {
      image[j * width + i] = (i + j) % 256;
    }
  }
}


  void Drawing::clearBuffer() {
    for (int line = 0; line < height; line++) {
      for (int col = 0; col < width; col++) {
        image[line * width + col] = 255;
      }
    }
  }