#ifndef SQUARE_H
#define SQUARE_H
 
#include "Shape2D.h"
#include "Point.h"
#include <iostream>
using namespace std;
 
class Square : public Shape2D {
private:
    double side;
    Point A, B, C, D;
 
    void calculateVertices() {
        this->A = this->refPoint;
        this->B = {this->refPoint.x + this->side, this->refPoint.y};
        this->C = {this->refPoint.x + this->side, this->refPoint.y - this->side};
        this->D = {this->refPoint.x, this->refPoint.y - this->side};
    }
 
public:
    Square(const string& n, Point topLeft, double s)
        : Shape2D(n, topLeft), side(s) {
        this->calculateVertices();
    }
 
    double area() const override {
        return this->side * this->side;
    }
 
    double perimeter() const override {
        return 4 * this->side;
    }
 
    void printInfo() const override {
        cout << "===== Square =====\n";
        cout << "Ner: " << this->name << "\n";
        cout << "Taliin urt: " << this->side << "\n";
        cout << "Oroinuud:\n";
        cout << "A(" << this->A.x << ", " << this->A.y << ")\n";
        cout << "B(" << this->B.x << ", " << this->B.y << ")\n";
        cout << "C(" << this->C.x << ", " << this->C.y << ")\n";
        cout << "D(" << this->D.x << ", " << this->D.y << ")\n";
        cout << "Talbai: " << this->area() << "\n";
        cout << "Hureenii urt: " << this->perimeter() << "\n\n";
    }
};
 
#endif