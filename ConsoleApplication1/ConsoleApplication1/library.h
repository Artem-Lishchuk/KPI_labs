//
// Created by lishc on 3/15/2023.
//

#ifndef LAB2_LIBRARY_H
#define LAB2_LIBRARY_H

#include <iostream>
#include <fstream>
#include <string>


using namespace std;

namespace mylib {

    struct Person {
        string name;
        string dob;
        string id;
        string gender;
        int age() const {
            int day, month, year;
            sscanf_s(dob.c_str(), "%d/%d/%d", &day, &month, &year);
            time_t t;
            time(&t);
            tm now;
            localtime_s(&now, &t);
            int currentYear = now.tm_year + 1900;
            int currentMonth = now.tm_mon + 1;
            int currentDay = now.tm_mday;

            int age = currentYear - year;
            if (currentMonth < month || (currentMonth == month && currentDay < day)) {
                age--;
            }
            return age;
        }
    };

    bool validateInput(string input, string fieldType) {
        bool isValid = true;
        if (fieldType == "name") {
            for (char c : input) {
                if (!isalpha(c) && c != ' ') {
                    isValid = false;
                    break;
                }
            }
        }
        else if (fieldType == "dateOfBirth") {
            Person person;
            person.dob = input;
            int age = person.age();
            if (age < 18 || age > 80) {
                isValid = false;
            }
        }
        else if (fieldType == "gender") {
            if (input != "man" && input != "woman") {
                isValid = false;
            }
        }
        else if (fieldType == "id") {
            if (input.length() != 9 || !isdigit(input[0])) {
                isValid = false;
            }
        }
        return isValid;
    }

    string promptUser() {
        string fileName;
        cout << "Enter the name of the file: " << endl;
        getline(std::cin, fileName);

        fileName.append(".txt");
        ofstream file(fileName, ios::binary);

        if (file.is_open()) {
            cout << "File opened successfully." << endl;
            file.close();
        }
        else {
            cout << "Error opening file." << endl;
        }
        file.close();
        return fileName;
    }


    void readBinaryFile(string fileName) {
        ifstream fIn(fileName, ios::binary);
        Person person;
        while (fIn.read((char*)&person, sizeof(Person))) {
            cout << endl;
            cout << "Id: " << person.id << ' ' << "Name: " << person.name << ' ' << "DoB: " << person.dob << ' ' << "Age: " << person.age() << ' ' << "Gender: " << person.gender << endl;
        }
        fIn.close();
        return;
    }

    void addEmployee(string fileName) {
        ofstream fOut(fileName, ios::binary);
        Person person;
        int n;
        cout << "How many employees do you want to add?" << endl;
        cin >> n;
        cin.ignore();

        if (fOut.is_open()) {
            for (int i = 0; i < n; i++) {
                cout << "Enter the name of the employee: ";
                getline(cin, person.name);
                while (!validateInput(person.name, "name")) {
                    cout << "Invalid input. Please enter a name using only English letters and spaces: ";
                    getline(cin, person.name);
                }
                cout << "Enter the date of birth (DD/MM/YYYY): ";
                getline(cin, person.dob);
                while (!validateInput(person.dob, "dateOfBirth")) {
                    cout << "Invalid input. Please enter a valid date of birth (age between 18 and 80): ";
                    getline(cin, person.dob);
                }
                cout << "Enter the gender (man/woman): ";
                getline(cin, person.gender);
                while (!validateInput(person.gender, "gender")) {
                    cout << "Invalid input. Please enter either 'man' or 'woman': ";
                    getline(cin, person.gender);
                }
                cout << "Enter the ID number (9 digits): ";
                getline(cin, person.id);
                while (!validateInput(person.id, "id")) {
                    cout << "Invalid input. Please enter a 9-digit number starting with a digit: ";
                    getline(cin, person.id);
                }
                fOut.write((char*)&person, sizeof(Person));
            }
            fOut.close();
            cout << "Data written to file successfully.";
        }
        else {
            cout << "Error opening file." << endl;
        }
    }

    void splitFile(string fileName) {
        ifstream inFile(fileName, ios::binary);
        ofstream fileLessForty("people40-.txt", ios::binary);
        ofstream filePlusForty("people40+.txt", ios::binary);
        Person person;
        while (inFile.read((char*)&person, sizeof(Person))) {
            if (person.age() > 40) {
                filePlusForty.write((char*)&person, sizeof(Person));
            }
            else {             
                fileLessForty.write((char*)&person, sizeof(Person));
            }
        }
        inFile.close();
        fileLessForty.close();
        filePlusForty.close();
    }

}
#endif //LAB2_LIBRARY_H
#pragma once