class Point  {
public:
  Point(float x0, float y0) {
    x = x0;
    y = y0;
  }

  float getX() const { return x; }
  float getY() const { return y; }

  void setX(float nx) { x = nx; }
  void setY(float ny) { y = ny; }

void drawPoint(const Point &point, const float thickness = 1) : Figure(width, height) {
    for (int line = 0; line < height; line++) {
      for (int col = 0; col < width; col++) {


        float squaredVertDistance =
            (line - point.getY()) * (line - point.getY());
        float squaredHorDistance = (col - point.getX()) * (col - point.getX());



        if (squaredVertDistance + squaredHorDistance < thickness * thickness) {
          setPoint(col, line);
        }
      }
    }
  }
private:
  float x, y;
};

  