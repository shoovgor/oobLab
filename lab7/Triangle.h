#ifndef TRIANGLE_H
#define TRIANGLE_H
 
#include "Shape2D.h"
#include "Point.h"
#include <iostream>
#include <cmath>
using namespace std;
 
class Triangle : public Shape2D {
private:
    double side;
    Point A, B, C;
 
    void calculateVertices() {
        double h = sqrt(3.0) / 2.0 * this->side;
        this->A = this->refPoint;
        this->B = {this->refPoint.x - this->side / 2.0, this->refPoint.y - h};
        this->C = {this->refPoint.x + this->side / 2.0, this->refPoint.y - h};
    }
 
public:
    Triangle(const string& n, Point oroinTseg, double s)
        : Shape2D(n, oroinTseg), side(s) {
        this->calculateVertices();
    }
 
    double area() const override {
        return sqrt(3.0) / 4.0 * this->side * this->side;
    }
 
    double perimeter() const override {
        return 3 * this->side;
    }
 
    void printInfo() const override {
        cout << "===== Zuv Gurvaljin =====\n";
        cout << "Ner: " << this->name << "\n";
        cout << "Taliin urt: " << this->side << "\n";
        cout << "Oroinuud:\n";
        cout << "A(" << this->A.x << ", " << this->A.y << ")\n";
        cout << "B(" << this->B.x << ", " << this->B.y << ")\n";
        cout << "C(" << this->C.x << ", " << this->C.y << ")\n";
        cout << "Talbai: " << this->area() << "\n";
        cout << "Hureenii urt: " << this->perimeter() << "\n\n";
    }
};
 
#endif