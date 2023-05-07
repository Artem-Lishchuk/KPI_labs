#include <iostream>
#include <vector>
#include "LinearFunction.h"
#include "functions.h"
#include "QuadraticFunction.h"

// Create n linear and m quadratic functions, by creating random coefficients
// coefficient of each linear function multiplicate by 3
// Coefficients of each quadratic function divide by 2


//Find function that has the biggest value at a given point

using namespace std;

int main() {
    int numberLinearFunctions = getInt("Enter a number of linear functions:");
    int numberQuadraticFunctions = getInt("Enter a number of quadratic functions");
    int point = getInt("Enter a point, where you want to evaluate functions");

    LinearFunction* linearFunctions[numberLinearFunctions];
    QuadraticFunction* quadraticFunctions[numberQuadraticFunctions];


    for (int i = 0; i < numberQuadraticFunctions; ++i) {
        quadraticFunctions[i] = new QuadraticFunction();
    }

    for (int i = 0; i < numberLinearFunctions; ++i) {
        linearFunctions[i] = new LinearFunction();
    }

    print_lin(linearFunctions,numberLinearFunctions,point);
    cout << endl;
    add(linearFunctions,numberLinearFunctions);
    print_lin(linearFunctions,numberLinearFunctions,point);

    cout << endl;

    print_quad(quadraticFunctions,numberQuadraticFunctions,point);
    cout << endl;
    subtract(quadraticFunctions,numberQuadraticFunctions);
    print_quad(quadraticFunctions,numberQuadraticFunctions,point);

    cout << endl;

    find_biggest(linearFunctions,numberLinearFunctions,point, quadraticFunctions, numberQuadraticFunctions);

}