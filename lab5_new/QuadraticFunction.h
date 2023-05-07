//
// Created by lishc on 4/20/2023.
//


#ifndef LAB5_QUADRATICFUNCTION_H
#define LAB5_QUADRATICFUNCTION_H
using namespace std;

class QuadraticFunction : public lib::Function {
public:
    QuadraticFunction() : lib::Function(3) {}

    double evaluate(double x) override {
        return get_coeffs(0) * x * x + get_coeffs(1) * x + get_coeffs(2);
    }
};


#endif //LAB5_QUADRATICFUNCTION_H
