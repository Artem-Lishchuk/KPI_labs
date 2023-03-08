//
// Created by lishc on 3/8/2023.
//

#ifndef INC_1_LAB_FILESTREAM_H
#define INC_1_LAB_FILESTREAM_H
namespace fls{
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

}
#endif //INC_1_LAB_FILESTREAM_H
