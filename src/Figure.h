#ifndef DRAWING_H
#define DRAWING_H

#include <string>
#include <vector>

class Point
{
    public:
        Point(float x0, float y0)
        {
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

class Figure : public Drawing
{
    public:
        Figure(const int width, const int height);
        ~Figure();
    
        void setPoint();

    private:
        const int width;
        const int height;

    protected:
        void clearImage();
}

#endif /* DRAWIN_H */