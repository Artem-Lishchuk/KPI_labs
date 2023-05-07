//
// Created by lishc on 4/20/2023.
//


#ifndef LAB5_LINEARFUNCTION_H
#define LAB5_LINEARFUNCTION_H
#include "Function.h"
using namespace std;



class LinearFunction : public lib::Function {
public:
    LinearFunction() : lib::Function(2) {}

    double evaluate(double x) override {
        return get_coeffs(0) * x + get_coeffs(1);
    }
};


#endif //LAB5_LINEARFUNCTION_H
