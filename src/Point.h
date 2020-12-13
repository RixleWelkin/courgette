class Point {
public:
  Point(float x0, float y0) {
    x = x0;
    y = y0;
  }

  float getX() const { return x; }
  float getY() const { return y; }

  void setX(float nx) { x = nx; }
  void setY(float ny) { y = ny; }

private:
  float x, y;
};