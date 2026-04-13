    #include <iostream>
    #include <cmath>
    #include <string>
    #include "Shape.h"
    #include "Point.h"
    #include "Shape2D.h"
    #include "Circle.h"
    #include "Square.h"
    #include "Triangle.h"
    #include "PI.h"
    using namespace std;

int main() {
    cout << "\n";
    Circle c1("C1", {2, 3}, 5);
    Circle c2("C2", {0, 0}, 2);

    Square s1("S1", {0, 10}, 4);
    Square s2("S2", {5, 5}, 3);

    Triangle t1("T1", {0, 8}, 6);
    Triangle t2("T2", {2, 7}, 4);

    c1.printInfo();
    c2.printInfo();

    s1.printInfo();
    s2.printInfo();

    t1.printInfo();
    t2.printInfo();
return 0;
}