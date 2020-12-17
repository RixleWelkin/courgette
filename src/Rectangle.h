#ifndef RECTANGLE_H
#define RECTANGLE_H
class Rectangle : public Figure {
public:
  Rectangle(const int largeur, const int hauteur);

  void draw() const {
    Figure::draw();
  }
};

  #endif /* RECTANGLE_H */