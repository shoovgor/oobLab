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

int main() {
    cout << "Suuri classuud amjilttai uuslee." << endl;
    return 0;
}