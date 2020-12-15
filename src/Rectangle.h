#ifndef RECTANGLE_H
#define RECTANGLE_H
class Rectangle : public Figure {
public:
  Rectangle(const int width, const int height);

  void draw() const {
    std::cout << "Affichage d'un rectangle : " << std::endl << std::endl;
    Figure::draw();
  }
};

  #endif /* RECTANGLE_H */