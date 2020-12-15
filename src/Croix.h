#ifndef CROIX_H
#define CROIX_H
class Croix : public Figure {
public:
  Croix(const int width, const int height);

  void draw() const {
    Figure::draw();
  }
};
#endif /* CROIX_H */