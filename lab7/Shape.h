#ifndef SHAPE_H
#define SHAPE_H

#include <string>
using namespace std;

class Shape {
protected:
    string name;

private:
    static int objectCount;  

public:
    Shape(const string& n = "") {
        this->name = n;      
        objectCount++;        
    }

    string getName() const {
        return this->name;  
    }

    static int getObjectCount() {
        return objectCount;
    }

    static void setObjectCount(int count) {
        objectCount = count;
    }

    virtual ~Shape() {}
};

#endif