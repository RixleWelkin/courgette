#ifndef POINT_H
#define POINT_H
class Point {
public:
  Point(float x0, float y0);

  float getX() const { return x; }
  float getY() const { return y; }

  void setX(float nx) { x = nx; }
  void setY(float ny) { y = ny; }

private:
  float x, y;
};
#endif /* POINT_H */

