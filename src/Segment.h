class Segment {
public:
  Segment(const Point &a, const Point &b);
  void translation(const Point &nouvOrg);
  void afficher() const;

  Point getOrigin() const;
  Point getDest() const;

private:
  Point org, ext;
};


Segment::Segment(const Point &a, const Point &b)
    : org(a.getX(), a.getY()), ext(b.getX(), b.getY())

{}

void Segment::translation(const Point &nouvOrg) {

  float dx = nouvOrg.getX() - org.getX();
  float dy = nouvOrg.getY() - org.getY();

  org.setX(nouvOrg.getX());
  org.setY(nouvOrg.getY());

  ext.setX(ext.getX() + dx);
  ext.setY(ext.getY() + dy);
}

void Segment::afficher() const {
  std::cout << "origine(" << org.getX() << "," << org.getY() << ")"
            << ", extremite(" << ext.getX() << "," << ext.getY() << ")"
            << std::endl;
}

Point Segment::getOrigin() const { return org; }

Point Segment::getDest() const { return ext; }
