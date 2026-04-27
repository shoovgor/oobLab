#ifndef CIRCLE_H
#define CIRCLE_H
 
#include "PI.h"
#include "Shape2D.h"
#include "Point.h"
#include <iostream>
using namespace std;
 
class Circle : public Shape2D {
private:
    double radius;
 
public:
    Circle(const string& n, Point center, double r)
        : Shape2D(n, center), radius(r) {}
 
    double area() const override {
        return PI * this->radius * this->radius;
    }
 
    double perimeter() const override {
        return 2 * PI * this->radius;
    }
 
    void printInfo() const override {
        cout << "===== Circle =====\n";
        cout << "Ner: " << this->name << "\n";
        cout << "Tuv: (" << this->refPoint.x << ", " << this->refPoint.y << ")\n";
        cout << "Radius: " << this->radius << "\n";
        cout << "Talbai: " << this->area() << "\n";
        cout << "Hureenii urt: " << this->perimeter() << "\n\n";
    }
};
 
#endif