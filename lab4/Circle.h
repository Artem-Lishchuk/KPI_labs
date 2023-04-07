//
// Created by lishc on 4/7/2023.
//
#include <cmath>
#include "iostream"

#ifndef LAB4_CIRCLE_H
#define LAB4_CIRCLE_H
using namespace std;

class Circle{
private:
    double radius;
    double x, y;
public:
    // Constructors
    Circle(){this->radius = 1, this->x=0, this->y=0;};
    Circle(double _radius){
        this->radius = _radius;
        this->y = 0;
        this->x = 0;
    }
    Circle(double _radius, double _x, double _y){
        this->radius= _radius;
        this->x=_x;
        this->y = _y;
    }


    // Getters
    double getRadius() const {
        return radius;
    }

    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

    // auxiliary
    double length(){
        return 2*M_PI*radius;
    }

    void printCircle(){
        fflush(stdin);
        cout << "This object is a circle with center in the coordinates( " << x << ", " << y<< ") and with radius " << radius << endl;
    }

    //overloading of operators
    void operator++() {
        this->x++;
    }

    void operator++(int _y) {
        this->y++;
    }

    void operator*(int n) {
        this->radius *= n;
    }

};

#endif //LAB4_CIRCLE_H
