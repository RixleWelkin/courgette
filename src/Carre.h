class Carre : public Rect {
public:
  Carre(const int size) : Rect(size, size) {}

  void draw() const {
    std::cout << "Affichage d'un carrÃ© : " << std::endl << std::endl;
    Figure::draw();
  }
};