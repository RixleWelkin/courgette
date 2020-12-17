#ifndef SEGMENT_H
#define SEGMENT_H
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
#endif /* SEGMENT_H */
