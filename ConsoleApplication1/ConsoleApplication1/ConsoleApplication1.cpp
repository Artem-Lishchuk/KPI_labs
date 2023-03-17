#include <iostream>
#include "library.h"
using namespace std;
using namespace mylib;


int main() {
    setlocale(LC_ALL, ".866");
    string filename = promptUser();
    cout << filename << endl;
    addEmployee(filename);
    splitFile(filename);
    cout << "\nPeople who are younger than 40 are: " << endl;
    return 0;
}