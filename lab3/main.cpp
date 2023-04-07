#include <iostream>
#include "Point.h"
#include "functions.h"

using namespace std;
using namespace mylib;

int main() {
    int numberOfPoints;
    double time;
    cout << "Enter a number of points: " << endl;
    cin >> numberOfPoints;
    Point *points = new Point[numberOfPoints];
    formArray(points,numberOfPoints);
    cout << "Enter a time: " << endl;
    cin >> time;
    printPointsInFirstOctant(points,numberOfPoints,time);

    return 0;
}
