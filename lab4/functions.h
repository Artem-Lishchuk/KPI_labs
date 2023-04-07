//
// Created by lishc on 4/7/2023.
//
#include "Circle.h"

#ifndef LAB4_FUNCTIONS_H
#define LAB4_FUNCTIONS_H

#include <regex>

using namespace std;

namespace mylib{

    double get_valid_input(string prompt) {
        string input;
        regex pattern("^[0-9]*\\.?[0-9]+([eE][-+]?[0-9]+)?$"); // шаблон для перевірки дійсного числа
        fflush(stdin);
        while (true) {
            cout << prompt << endl;
            fflush(stdin);
            getline(cin, input);
            if (regex_match(input, pattern) and input[0] != '-') { // перевірка на дійсне число
                break;
            } else {
                cout << "Invalid input. Please enter a valid number." << endl;
            }
        }
        return stod(input); // перетворення рядка на дійсне число
    }

    Circle initialisePoint(){
        double x, y, radius;
        fflush(stdin);
        x = get_valid_input("Enter x coordinate: ");

        y = get_valid_input("Enter y coordinate: ");

        radius = get_valid_input("Enter radius ");

        fflush(stdin);
        Circle circle(x,y,radius);
        return circle;
    }

    void determineTheLongestCircle(Circle c1,Circle c2,Circle c3){
        if(c1.length() > c2.length() and c3.length()){
            cout << "Circle 1 is the biggest with the length " << c1.length() << endl;
        }
        else if(c2.length() > c3.length() and c2.length() > c1.length()){
            cout << "Circle 2 is the biggest with the length " << c2.length() << endl;
        } else{
            cout << "Circle 3 is the biggest with the length " << c3.length() <<endl;
        }
    }
}
#endif //LAB4_FUNCTIONS_H
