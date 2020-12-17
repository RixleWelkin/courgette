#ifndef TRIANGLE_H
#define TRIANGLE_H
class Triangle : public Figure {
public:
  Triangle(const int largeur, const int hauteur);

  void draw() const {
    Figure::draw();
  }
};

  #endif /* TRIANGLE_H */