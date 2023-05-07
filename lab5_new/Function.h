//
// Created by lishc on 4/20/2023.
//

#ifndef LAB5_FUNCTION_H
#define LAB5_FU2
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <random>

// create a class Function;
// create methods to increase, decrease each coefficient by the given number
// create a method that calculates the function value at the specific point

// create two child classes: Quadratic Function and Linear function





using namespace std;

namespace lib{
    class Function {
    private:

        int length;

    public:
        double* coeffs;
        Function(int num_coeffs) {

            this->length = num_coeffs;
            this->coeffs = new double[num_coeffs];

            std::random_device rd;
            std::default_random_engine generator(rd()); // rd() provides a random seed
            std::uniform_real_distribution<double> distribution(-10,10);


            for (int i = 0; i < num_coeffs; i++) {
                double number = distribution(generator);
                coeffs[i] = round(number*10)/10.0;
            }
        }

        ~Function() {
            delete[] coeffs;
        }

        virtual double evaluate(double x) = 0;

        void set_coeffs(int index, double value) {
            if (index >= 0 && index < length) {
                coeffs[index] = value;
            }
        }

        double get_coeffs(int index) {
            if (index >= 0 && index < length) {
                return coeffs[index];
            }
            return 0;
        }

        int get_length() {
            return length;
        }

        void increase_coeffs(double value) {
            for (int i = 0; i < length; i++) {
                coeffs[i] += value;
            }
        }

        bool decrease_coeffs(double value) {
            for (int i = 0; i < length; i++) {
                coeffs[i] -= value;
            }
            return true;
        }
    };
}

#endif //LAB5_FUNCTION_H
