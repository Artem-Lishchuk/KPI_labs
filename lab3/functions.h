//
// Created by lishc on 3/31/2023.
//
#include <regex>
#include "iostream"
#ifndef LAB3_FUNCTIONS_H
#define LAB3_FUNCTIONS_H

using namespace std;

namespace mylib{

    double get_valid_input(string prompt) {
        string input;
        regex pattern("^[-+]?[0-9]*\\.?[0-9]+([eE][-+]?[0-9]+)?$"); // шаблон для перевірки дійсного числа
        while (true) {
            cout << prompt << endl;
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            getline(cin, input);
            if (regex_match(input, pattern)) { // перевірка на дійсне число
                break;
            } else {
                cout << "Invalid input. Please enter a valid number." << endl;
            }
        }
        return stod(input); // перетворення рядка на дійсне число
    }

    Point initialisePoint(){
        double x, y, z, vx, vy, vz;
        fflush(stdin);
        x = get_valid_input("Enter x coordinate: ");
        fflush(stdin);
        y = get_valid_input("Enter y coordinate: ");
        fflush(stdin);
        z = get_valid_input("Enter z coordinate: ");
        fflush(stdin);
        vx = get_valid_input("Enter x velocity: ");
        fflush(stdin);
        vy = get_valid_input("Enter y velocity: ");
        fflush(stdin);
        vz = get_valid_input("Enter z velocity: ");
        fflush(stdin);
        Point point(x,y,z,vx,vy,vz);
        return point;
    }

    void formArray(Point* points, int numberOfPoints){
        for (int i = 0; i < numberOfPoints; ++i) {
            Point point = initialisePoint();
            points[i] = point;
        }
    }

    void printAllPoints(Point* points, int size) {
        for (int i = 0; i < size; i++) {
            fflush(stdin);
            points[i].printPoint();
        }
    }

    void printPointsInFirstOctant(Point* points, int size, double t) {
        for (int i = 0; i < size; i++) {
            double x = points[i].getX() + points[i].getVx() * t;
            double y = points[i].getY() + points[i].getVy() * t;
            double z = points[i].getZ() + points[i].getVz() * t;
            if (x >= 0 && y >= 0 && z >= 0) {
                cout << "Point " << i+1 << " is in the first octant at time " << t << endl;
            }
        }
    }

}
#endif //LAB3_FUNCTIONS_H
