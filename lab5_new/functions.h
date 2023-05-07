//
// Created by lishc on 4/20/2023.
//


#ifndef LAB5_FUNCTIONS_H
#define LAB5_FUNCTIONS_H
#include "string"
#include "iostream"
#include "sstream"
#include "QuadraticFunction.h"


int getInt(string prompt){
    string line;
    int input;

    while(1){
        cout << prompt << endl;
        getline(cin,line);
        stringstream ss(line);
        if(ss >> input && ss.eof()){
            return input;
        }
        cout << "Invalid input. Enter again" << endl;
    }
}

void subtract(QuadraticFunction** quadraticFunctions, int length){
    for (int i = 0; i < length; ++i) {
        quadraticFunctions[i]->decrease_coeffs(2);

    }
}
//
void add(LinearFunction** linearFunctions, int length){
    for (int i = 0; i < length; ++i) {
        linearFunctions[i] -> increase_coeffs(3);
    }
}

void print_lin(LinearFunction** linearFunctions, int length, int point){
    for (int i = 0; i < length; i++) {
        printf("%d linear function is as follows: %.1lf * x + %.1lf = %.1lf",
               i+1,linearFunctions[i] -> get_coeffs(0),linearFunctions[i] -> get_coeffs(1),linearFunctions[i] -> evaluate(point));
        cout << endl;
    }
}

void print_quad(QuadraticFunction** quadraticFunctions, int length, int point){
    for (int i = 0; i < length; i++) {
        printf("%d quadratic function is as follows: %.1lf * x**2 + %.1lf * x + %.1lf = %.1lf",
               i+1,quadraticFunctions[i]->get_coeffs(0),quadraticFunctions[i]->get_coeffs(1),quadraticFunctions[i]->get_coeffs(2),quadraticFunctions[i]->evaluate(point));
        cout << endl;
    }
}

void find_biggest(LinearFunction** linearFunctions, int length_lin, int point, QuadraticFunction** quadraticFunctions, int length_quad){
    double maxElem = linearFunctions[0]->evaluate(point);
    int maxElemIndex = 0;
    int maxElemArrayNum = 1;

    // Find the maximum element in arr1
    for (int i = 1; i < length_lin; i++) {
        double res = linearFunctions[i]->evaluate(point);
        if (res > maxElem) {
            maxElem = res;
            maxElemIndex = i;
            maxElemArrayNum = 1;
        }
    }

    // Find the maximum element in arr2
    for (int i = 0; i < length_quad; i++) {
        double res = quadraticFunctions[i]->evaluate(point);
        if (res > maxElem) {
            maxElem = res;
            maxElemIndex = i;
            maxElemArrayNum = 2;
        }
    }
    if (maxElemArrayNum == 1){
        printf("The biggest function is %d linear function: %.1lf * x + %.1lf = %.1lf",maxElemIndex+1,linearFunctions[maxElemIndex]->get_coeffs(0),linearFunctions[maxElemIndex]->get_coeffs(1),maxElem);
    }
    else{
        printf("The biggest function is %d quadratic function: %.1lf * x**2 + %.1lf * x + %.1lf = %.1lf",
               maxElemIndex+1,quadraticFunctions[maxElemIndex]->get_coeffs(0),
               quadraticFunctions[maxElemIndex]->get_coeffs(1),quadraticFunctions[maxElemIndex]->get_coeffs(2),maxElem);
    }
}

#endif //LAB5_FUNCTIONS_H
