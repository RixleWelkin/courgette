class Segment : public Figure {
public:
  Segment(const Point &a, const Point &b);
  void translation(const Point &nouvOrg);
  void afficher() const;

  Point getOrigin() const;
  Point getDest() const;
void Segment::drawSegment(const Segment &segment, const float thickness = 1.f) {

    Point point1 = (segment.getDest().getX() < segment.getOrigin().getX())
                       ? segment.getDest()
                       : segment.getOrigin();


    Point point2 = (point1.getX() == segment.getDest().getX())
                       ? segment.getOrigin()
                       : segment.getDest();


    float dx = point1.getX() - point2.getX();
    float dy = point1.getY() - point2.getY();


    for (int x = point1.getX(); x <= point2.getX(); x++) {

      for (int y = 0; y < height; y++) {
        float dist;




        if ((dx == 0) ||
            (labs((float)y - (float)segment.getOrigin().getY() +
                  (float)dy * (float)(x - segment.getDest().getX()) /
                      (float)dx) < 1)) {
          drawPoint(Point(x, y), thickness);
        }
      }
    }
  }
private:
  Point org, ext;
};