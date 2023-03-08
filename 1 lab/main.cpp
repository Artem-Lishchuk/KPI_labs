#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>

#define initFileName "test.txt"
#define outFileName "result.txt"
#define numberOfSymbols 1000
using namespace std;


int insertText(ofstream&);
int writeIntoFile(ofstream&,const string&);
void promptUser();
void insertLineBreaks();
void deleteTextInBrackets();
void findTheLongestWord();
string reverseTheLongestWord(string);
void executeProgram(int option);
void insertLineBreaksPointer();
void deleteTextInBracketsPointer();
void findTheLongestWordPointer();
char* reverseLongestWord(char* str);

int main() {
    int option;
    promptUser(); // ask user to write 1 to use existing test and 2 to input their own text. Writes into a file named initFileName
    cout << "Choose an option: 1 for program with file stream, 2 for program with file pointers" << endl;
    cin >> option;
    executeProgram(option);

    return 0;
}

void executeProgram(int option){
    if(option == 1){
        insertLineBreaks();

        deleteTextInBrackets();

        findTheLongestWord();
    }
    else if(option == 2){
        insertLineBreaksPointer();
        deleteTextInBracketsPointer();
        findTheLongestWordPointer();
    }
    else{
        cout << "Invalid option." << endl;
    }
}


int writeIntoFile(ofstream& file,const string& text){
    if (!file.is_open()) {
        cout << "Error creating file!" << endl;
        return 1;
    }
    file << text << endl;
    file.close();
    return 0;
}

int insertText(ofstream& file){
    string text;
    cout << "Please enter some text (up to "<< numberOfSymbols <<"characters): ";
    getline(cin, text);
    writeIntoFile(file,text);
    return 0;
}

void promptUser() {
    string input;
    int choice = 0;

    cout << "Press 1 to use existing text or 2 to write your own: " <<endl;
    getline(cin, input);

    try {
        choice = stoi(input);
    } catch (...) {
        cout << "Invalid input! Please enter a number." << endl;
        promptUser();
        return;
    }

    if (choice == 1) {
        cout << "You chose to use preset text." << endl;
        return;
    } else if (choice == 2) {
        cout << "You chose to write your own text." << endl;
        ofstream outInitFile(initFileName);
        insertText(outInitFile);
        outInitFile.close();
        return;
    } else {
        cout << "Invalid input! Please enter 1 or 2." << endl;
        promptUser();
        return;
    }
}

void insertLineBreaksPointer(){
    char cnt[1001];
    FILE *temp = fopen("temp_file.txt", "w");
    FILE *file  = fopen(initFileName, "r");
    while (fgets(cnt, 1001, file)) {
        for (int i = 0; i < strlen(cnt); ++i) {
            if (cnt[i] == '.') {
                for (int j = strlen(cnt); j >= i + 1; j--) {
                    cnt[j + 1] = cnt[j];
                }
                cnt[i+1] = '\n';
            }
        }
        fputs(cnt, temp);
    }
    fclose(file);
    fclose(temp);
    rename("temp_file.txt",outFileName);
    fclose(temp);
}

void deleteTextInBracketsPointer(){
    char cnt[1001];
    FILE *temp = fopen("temp_file.txt", "w");
    FILE *file  = fopen(outFileName, "r");

    int bracketCount = 0;

    while (fgets(cnt, numberOfSymbols, file) != nullptr) {
        for (int i = 0; cnt[i] != '\0'; i++) {
            if (cnt[i] == '(') {
                bracketCount++;
            }
            else if (cnt[i] == ')') {
                bracketCount--;
            }
            else if (bracketCount == 0) {
                fputc(cnt[i], temp);
            }
        }
    }

    fclose(file);
    fclose(temp);
    if (remove(outFileName) != 0)
        perror("Unable to delete the file");
    rename("temp_file.txt",outFileName);
    fclose(temp);
}

char* reverseLongestWord(char* str) {
    // Find the length of the input string
    size_t len = strlen(str);

    // Initialize variables to keep track of the longest word and its length
    char* longest_word = nullptr;
    size_t longest_length = 0;

    // Initialize variables to keep track of the current word and its length
    char* current_word = nullptr;
    size_t current_length = 0;

    // Iterate over the input string, character by character
    for (size_t i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            // If the current character is a letter, it's part of a word
            if (current_word == nullptr) {
                // If we're not currently tracking a word, set the current word
                current_word = &str[i];
                current_length = 1;
            } else {
                // If we're already tracking a word, increment the length
                current_length++;
            }
        } else {
            // If the current character is not a letter, it's a word boundary
            if (current_word != nullptr && current_length > longest_length) {

                // set it as the new longest word
                longest_word = current_word;
                longest_length = current_length;
            }
            // Reset the current word and length
            current_word = nullptr;
            current_length = 0;
        }
    }

    // Handle the case where the longest word is at the end of the string
    if (current_word != nullptr && current_length > longest_length) {
        longest_word = current_word;
        longest_length = current_length;
    }

    if (longest_word == nullptr) {
        // If no words were found, return the original string
        return str;
    } else {
        // Reverse the longest word in place
        std::reverse(longest_word, longest_word + longest_length);

        // Allocate a new buffer for the result string
        char* result = new char[len + 1];

        // Copy the input string to the result buffer, replacing the longest word with its reversed version
        memcpy(result, str, longest_word - str);
        memcpy(result + (longest_word - str), longest_word, longest_length);
        memcpy(result + (longest_word - str) + longest_length, longest_word + longest_length, len - (longest_word - str) - longest_length + 1);

        return result;
    }
}

void findTheLongestWordPointer() {
    FILE* file = fopen(outFileName, "r");
    FILE* temp = fopen("temp_file.txt", "w");

    char cnt[1001];
    while (fgets(cnt, numberOfSymbols, file) != nullptr) {
        char * newSentence = reverseLongestWord(cnt);
        fputs(newSentence, temp);
    }
    fclose(file);
    fclose(temp);
    if (remove(outFileName) != 0)
        perror("Unable to delete the file");
    rename("temp_file.txt",outFileName);
    fclose(temp);}
