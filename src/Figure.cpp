#include "Figure.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>
#include <stdexcept>

Figure::Figure(const int width, const int height)
    : width(width), height(height)
{
  image.resize(width * height);
}

Figure::~Figure() {}

