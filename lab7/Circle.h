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

    double area() const {
        return PI * radius * radius;
    }

    double perimeter() const {
           return 2 * PI * radius;
    }

    void printInfo() const {
        cout << "===== Circle =====\n";
        cout << "Ner: " << name << "\n";
        cout << "Tuv: (" << refPoint.x << ", " << refPoint.y << ")\n";
        cout << "Radius: " << radius << "\n";
           cout << "Talbai: " << area() << "\n";
        cout << "Hureenii urt: " << perimeter() << "\n\n";
    }
};
#endif