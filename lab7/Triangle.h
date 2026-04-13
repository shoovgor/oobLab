#ifndef TRIANGLE_H
#define TRIENGLE_H

#include "Shape2D.h"
#include "Point.h"
#include <iostream>
using namespace std;

class Triangle : public Shape2D {
private:
    double side;
    Point A, B, C;

    void calculateVertices() {
        double h = sqrt(3.0) / 2.0 * side;
        A = refPoint;
        B = {refPoint.x - side / 2.0, refPoint.y - h};
        C = {refPoint.x + side / 2.0, refPoint.y - h};
    }

public:
    Triangle(const string& n, Point oroinTseg, double s)
            : Shape2D(n, oroinTseg), side(s) {
        calculateVertices();
    }
    double area() const {
        return sqrt(3.0) / 4.0 * side * side;
    }

    double perimeter() const {
        return 3 * side;
    }

    void printInfo() const {
        cout << "===== Zuv Gurvaljin =====\n";
        cout << "Ner: " << name << "\n";
        cout << "Taliin urt: " << side << "\n";
        cout << "Oroinuud:\n";
        cout << "A(" << A.x << ", " << A.y << ")\n";
        cout << "B(" << B.x << ", " << B.y << ")\n";
        cout << "C(" << C.x << ", " << C.y << ")\n";
        cout << "Talbai: " << area() << "\n";
        cout << "Hureenii urt: " << perimeter() << "\n\n";
    }
};

#endif