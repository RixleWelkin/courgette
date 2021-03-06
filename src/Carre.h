#ifndef CARRE_H
#define CARRE_H
class Carre : public Rectangle { // Un carre est un rectangle de meme cotes, carre herite donc de rectangle
public:
  Carre(const int size) : Rectangle(size, size) {}

  void draw() const {
    Figure::draw();
  }
};
#endif /* CARRE_H */