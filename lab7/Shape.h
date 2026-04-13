#ifndef SHAPE_H
#define SHAPE_H

#include <string>
using namespace std;

class Shape {
protected:
    string name;

public:
    Shape(const string& n = "") {
        name = n;
    }

    string getName() const {
        return name;
    }

    virtual ~Shape() {}
};

#endif