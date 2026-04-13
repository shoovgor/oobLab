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
            A = refPoint;
            B = {refPoint.x + side, refPoint.y};
            C = {refPoint.x + side, refPoint.y - side};
            D = {refPoint.x, refPoint.y - side};
        }

    public:
        Square(const string& n, Point topLeft, double s)
                : Shape2D(n, topLeft), side(s) {
            calculateVertices();
        }

        double area() const {
            return side * side;
        }

        double perimeter() const {
            return 4 * side;
        }

        void printInfo() const {
            cout << "===== Square =====\n";
            cout << "Ner: " << name << "\n";
            cout << "Taliin urt: " << side << "\n";
            cout << "Oroinuud:\n";
            cout << "A(" << A.x << ", " << A.y << ")\n";
            cout << "B(" << B.x << ", " << B.y << ")\n";
            cout << "C(" << C.x << ", " << C.y << ")\n";
            cout << "D(" << D.x << ", " << D.y << ")\n";
            cout << "Talbai: " << area() << "\n";
            cout << "Hureenii urt: " << perimeter() << "\n\n";
        }
    };

#endif