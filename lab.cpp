#include <iostream>
#include <cmath>
#include <string>
using namespace std;
 
// Координат хадгалах бүтэц
struct Point {
    double x, y;
};
 
// Дүрсийн ерөнхий класс
class Shape {
protected:
    string name;
 
public:
    Shape(const string& n = "") : name(n) {}   // байгуулагч функц
    virtual ~Shape() {}   // virtual устгагч, хүүхэд классууд зөв устахад хэрэгтэй
};
 
// 2 хэмжээст дүрсийн ерөнхий хийсвэр класс
class Shape2D : public Shape {
protected:
    Point refPoint;   // дүрсийн ерөнхий нэг цэг хадгална
 
public:
    Shape2D(const string& n, Point p) : Shape(n), refPoint(p) {}   // байгуулагч функц
 
    // Эдгээр функцыг зөвхөн хүүхэд классууд хэрэгжүүлнэ
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void printInfo() const = 0;
};
 
// PI тогтмол
const double PI = acos(-1.0);
 
// Тойргийн класс
class Circle : public Shape2D {
private:
    double radius;
 
public:
    Circle(const string& n, Point center, double r)
        : Shape2D(n, center), radius(r) {}   // n-нэр, center-төв цэг, r-радиус
 
    double area() const override {
        return PI * radius * radius;
    }
 
    double perimeter() const override {
        return 2 * PI * radius;
    }
 
    void printInfo() const override {
        cout << "===== Circle =====\n";
        cout << "Ner: " << name << "\n";
        cout << "Tuv: (" << refPoint.x << ", " << refPoint.y << ")\n";
        cout << "Radius: " << radius << "\n";
        cout << "Talbai: " << area() << "\n";
        cout << "Hureenii urt: " << perimeter() << "\n\n";
    }
};
 
// Квадратын класс
class Square : public Shape2D {
private:
    double side;
    Point A, B, C, D;
 
    void calculateVertices() {   // оройнуудыг тооцоолох туслах функц
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
 
    double area() const override {
        return side * side;
    }
 
    double perimeter() const override {
        return 4 * side;
    }
 
    void printInfo() const override {
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
 // Гурвалжин класс
class Triangle : public Shape2D {
private:
    double side;
    Point A, B, C;

    void calculateVertices() { // tuslah function
        double h = sqrt(3.0) / 2.0 * side;
        A = refPoint; // oroin tseg
        B = {refPoint.x - side / 2.0, refPoint.y - h};
        C = {refPoint.x + side / 2.0, refPoint.y - h};
    }

public:
    Triangle(const string& n, Point oroinTseg, double s)
            : Shape2D(n, oroinTseg), side(s) {
        calculateVertices();
    }

    double area() const override {
        return sqrt(3.0) / 4.0 * side * side;
    }

    double perimeter() const override {
        return 3 * side;
    }

    void printInfo() const override {
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

int main() {
    cout << fixed;

    Circle c("C1", {2, 3}, 5);
    Square s("S1", {0, 10}, 4);
    Triangle t("T1", {0, 8}, 6);

    Shape2D* shapes[3];
    shapes[0] = &c;
    shapes[1] = &s;
    shapes[2] = &t;

    // buh dursiin medeelliig hevleh
    for (int i = 0; i < 3; i++) {
        shapes[i]->printInfo();
    }

    return 0;
}