#ifndef DRAWING_H
#define DRAWING_H
#include <string>
#include <vector>
class Figure;
class Drawing
{
  public:
    Drawing(const int width, const int height);
    ~Drawing();
    void save(std::string filename);
    void DrawCanva(std::vector<char> figure,int hauteur, int largeur,int posx, int posy);
    //void virtual AjoutCanva(Figure f,int x, int y);
    void clearImage();
  private:
    
    void createTestImage();
    void createFigureImage();
    void clearBuffer();
  public:
    const int width;
    const int height;
  
  private:
    std::vector<char> image;
    Figure *DrawingMember;
    Figure *figures[10];
    int coords[20];
    int pos=0;
};

#endif /* DRAWIN_H */