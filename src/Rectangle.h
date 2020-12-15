#ifndef RECTANGLE_H
#define RECTANGLE_H
class Rectangle : public Figure {
public:
  Rectangle(const int width, const int height);

  void draw() const {
    Figure::draw();
  }
};

  #endif /* RECTANGLE_H */