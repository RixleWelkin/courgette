#ifndef FIGURE_H
#define FIGURE_H
#include <string>
#include <vector>
#include "Point.h"
#include "Segment.h"
#include "Drawing.h"
class Figure : public Drawing{
public:
  Figure(const int largeur, const int hauteur);
  ~Figure();
  const int largeur;
  const int hauteur;
  void draw() const;
 void drawPoint(const Point &point, const float thickness);
 void drawSegment(const Segment &segment, const float thickness);

protected:
  bool setPoint(const int col, const int line);
  bool clearPoint(const int col, const int line);
  void clearBuffer();
  bool drawVertLine(const int col);
  bool drawHorLine(const int line);

public : 
  std::vector<char> figure;
private:
  Drawing *FigureMember;
};

#endif /* FIGURE_H */