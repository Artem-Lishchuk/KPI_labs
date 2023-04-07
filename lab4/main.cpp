#include <iostream>
#include "functions.h"
#include "Circle.h"

using namespace std;
using namespace mylib;

int main() {
    Circle circle1 = initialisePoint();
    Circle circle2 = initialisePoint();
    Circle circle3 = initialisePoint();

    cout << "1st operation - prefix(++Circle) for Circle1. It will increment x by 1. Below you see circle before operations" << endl;
    circle1.printCircle();
    ++circle1;
    cout<<"Circle 1 after operation: "<<endl;
    circle1.printCircle();

    cout<<endl;

    cout << "2nd operation - postfix(Circle++) for Circle2. It will increment y by 1. Below you see circle before operations" << endl;
    circle2.printCircle();
    circle2++;
    cout<<"Circle 2 after operation: "<<endl;
    circle2.printCircle();

    cout<<endl;

    cout << "3rd operation - multiplication(Circle*3) for Circle3. It will multiplicate radius by 3. Below you see circle before operations" << endl;
    circle3.printCircle();
    circle3*3;
    cout<<"Circle 3 after operation: "<<endl;
    circle3.printCircle();

    cout << endl;
    determineTheLongestCircle(circle1,circle2,circle3);
}
