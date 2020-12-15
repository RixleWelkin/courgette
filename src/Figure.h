#ifndef FIGURE_H
#define FIGURE_H
class Figure {
public:
  Figure(const int width, const int height);

  ~Figure();

  void draw() const;
  void drawPoint(const Point &point, const float thickness);
  void drawSegment(const Segment &segment, const float thickness);

protected:
  bool setPoint(const int col, const int line);
  bool clearPoint(const int col, const int line);
  void clearBuffer();
  bool drawVertLine(const int col);
  bool drawHorLine(const int line);

protected:
  int *buffer;
  int width;
  int height;
};

#endif /* FIGURE_H */