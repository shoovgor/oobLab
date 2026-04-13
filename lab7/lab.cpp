#include <iostream>
#include <vector>
#include <algorithm>

#include "Point.h"
#include "Shape.h"
#include "Shape2D.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
#include "PI.h"

using namespace std;

int main() {
    vector<Shape2D*> shapes;

    shapes.push_back(new Circle("C1", {2, 3}, 5));
    shapes.push_back(new Circle("C2", {0, 0}, 2));

    shapes.push_back(new Square("S1", {0, 10}, 4));
    shapes.push_back(new Square("S2", {5, 5}, 3));

    shapes.push_back(new Triangle("T1", {0, 8}, 6));
    shapes.push_back(new Triangle("T2", {2, 7}, 4));

    cout << "=== Talbaigaar erembelsen ===\n\n";
    for (int i = 0; i < shapes.size(); i++) {
        cout << i + 1 << ". "
            << shapes[i]->getName()
            << " - Talbai: " << shapes[i]->area() << "\n";
    }

    sort(shapes.begin(), shapes.end(), [](Shape2D* a, Shape2D* b) {
        return a->area() < b->area();
    });

    for (Shape2D* s : shapes) {
        delete s;
    }

    return 0;
}