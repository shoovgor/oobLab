    #include <iostream>
    #include <cmath>
    #include <string>
    #include "Shape.h"
    #include "Point.h"
    #include "Shape2D.h"
    #include "Circle.h"
    #include "Square.h"
    #include "Triangle.h"
    using namespace std;
    const double PI = acos(-1.0);

    int main() {
        cout << fixed;

        Circle c("C1", {2, 3}, 5);
        Square s("S1", {0, 10}, 4);
        Triangle t("T1", {0, 8}, 6);

        c.printInfo();
        s.printInfo();
        t.printInfo();

        return 0;
    }