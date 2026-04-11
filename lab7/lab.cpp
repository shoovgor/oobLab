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
        Shape(const string& n = "") : name(n) {}
        ~Shape() {}
    };

    // 2 хэмжээст дүрсийн ерөнхий класс
    class Shape2D : public Shape {
    protected:
        Point refPoint;

    public:
        Shape2D(const string& n, Point p) : Shape(n), refPoint(p) {}
    };

    // PI тогтмол
    const double PI = acos(-1.0);

    // Тойргийн класс
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

    // Квадратын класс
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

    // Гурвалжин класс
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