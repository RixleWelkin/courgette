#ifndef CROIX_H
#define CROIX_H
class Cross : public Figure {
public:
  Cross(const int width, const int height);

  void draw() const {
    std::cout << "Affichage d'une croix : " << std::endl << std::endl;
    Figure::draw();
  }
};
#endif /* CROIX_H */