#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>

#define initFileName "test.txt"
#define outFileName "result.txt"
#define numberOfSymbols 1000
using namespace std;

void insertLineBreaks();
void deleteTextInBrackets();
void findTheLongestWord();
string reverseTheLongestWord(string);
void insertLineBreaksPointer();
void deleteTextInBracketsPointer();
void findTheLongestWordPointer();
char* reverseLongestWord(char* str);

int main(int argc, char* argv[]){
    if (argc != 3){
        cout << "Invalid count of arguments!" << endl;
        cout << argc << endl;
        return 0;
    }

    if (strcmp(argv[1], "-mode") != 0){
        cout << "Invalid argument" << endl;
        return 0;
    }
    if(strcmp(argv[2], "FileStream") ==0){
        cout << "You chose File Stream" << endl;
        insertLineBreaks();

        deleteTextInBrackets();

        findTheLongestWord();
    }
    else if(strcmp(argv[2], "FilePointer") == 0 ) {
        if (remove(outFileName) != 0)
            perror("Unable to delete the file");
        cout << "You chose File Pointer" << endl;
        insertLineBreaksPointer();
        deleteTextInBracketsPointer();
        findTheLongestWordPointer();
    }
    else{
        cout << "Invalid mode" << endl;
        return 0;
    }
    return 0;
}


void findTheLongestWord(){
    ifstream inFile(outFileName);
    if (!inFile) {
        cout << "Error: could not open input file." << endl;
        return;
    }
    string outFileNameOut = outFileName;
    outFileNameOut.append(".out");
    ofstream outFile(outFileNameOut);
    if (!outFile) {
        cout << "Error: could not open output file." << endl;
        inFile.close();
        return;
    }
    string sentence;
    while (getline(inFile,sentence)){
        string longest_word = "";
        int start = - 1;
        string word;
        stringstream ss(sentence);
        while (ss >> word){
            if (word.length() > longest_word.length()){
                longest_word = word;
                start = sentence.find(longest_word);
            }
        }
        if (start >= 0){
            char last_char = longest_word[longest_word.length() - 1];
            if (ispunct(last_char)){
                string word_without_punct = longest_word.substr(0, longest_word.length() - 1);
                string reversed = reverseTheLongestWord(word_without_punct);
                sentence.replace(start,word_without_punct.length(), reversed);
            }
            else{
                string reversed = reverseTheLongestWord(longest_word);
                sentence.replace(start,longest_word.length(), reversed);
            }
        }
        if (!sentence.empty() && sentence[0] == ' ') {
            sentence.erase(0, 1);
        }
        outFile << sentence << endl;
    }

    inFile.close();
    outFile.close();
    if (remove(string(outFileName).c_str()) != 0) {
        cout << "Error: could not delete original file." << endl;
    }
    if (rename(outFileNameOut.c_str(), string(outFileName).c_str()) != 0) {
        cout << "Error: could not rename output file." << endl;
    }
}

string reverseTheLongestWord(string s){
    reverse(s.begin(), s.end());
    return s;
}

void deleteTextInBrackets() {
    string line;
    ifstream inFile(outFileName);
    if (!inFile) {
        cout << "Error: could not open input file." << endl;
        return;
    }
    // create output filename by appending ".out" to the input filename
    string outFileNameOut = outFileName;
    outFileNameOut.append(".out");
    ofstream outFile(outFileNameOut);
    if (!outFile) {
        cout << "Error: could not open output file." << endl;
        inFile.close();
        return;
    }
    string temp;
    while (getline(inFile,temp)) {
        int start = -1, end = -1,nested_level = 0;
        for (int i = 0; i < temp.length(); ++i) {
            if (temp[i] == '(') {
                if (start == -1){
                    start = i;
                }
                nested_level ++;
            }
            if (temp[i] == ')') {
                nested_level --;
                end = i;
                if (nested_level == 0 && start >= 0 && start < end) {
                    temp.erase(start,end-start+1);
                    i = start - 1;
                    start = -1;
                    end = -1;
                }
            }
        }
        outFile << temp << endl;
    }
    inFile.close();
    outFile.close();
    if (remove(string(outFileName).c_str()) != 0) {
        cout << "Error: could not delete original file." << endl;
    }
    if (rename(outFileNameOut.c_str(), string(outFileName).c_str()) != 0) {
        cout << "Error: could not rename output file." << endl;
    }
}

void insertLineBreaks(){
    string temp;
    ifstream inFile(initFileName);
    ofstream outFile(outFileName);
    if (!inFile) {
        cout << "Error: could not open input file." << endl;
        return;
    }

    if (!outFile) {
        cout << "Error: could not open output file." << endl;
        inFile.close();
        return;
    }
    while(!inFile.eof()){
        getline(inFile,temp);
        for (int i = 0; i < temp.length(); ++i) {
            if (temp[i] == '.'){
                temp.insert(i+1,"\n");
            }
        }
        outFile << temp << endl;
    }
    inFile.close();
    outFile.close();
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
        reverse(longest_word, longest_word + longest_length);

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
    fclose(temp);
}


