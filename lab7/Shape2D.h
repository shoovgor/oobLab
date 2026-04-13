#ifndef SHAPE2D_H
#define SHAPE2D_H  
#include "Shape.h"
#include "Point.h"

class Shape2D : public Shape {
protected:
    Point refPoint;

public:
    Shape2D(const string& n, Point p) : Shape(n), refPoint(p) {}
};
#endif