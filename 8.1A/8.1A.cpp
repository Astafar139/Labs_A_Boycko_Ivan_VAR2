#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;
//конмтрукторы всех типов указаны номерами;
class Word {
public:
    string word;
    Word() { //1
        word = "";
    };
    Word(const char* w) {//2
        word = w;
    };
    Word(string w) {//2(через string)
        word = w;
    };
    Word(char c, int n) {//3
        for (int i = 0; i < n; ++i) {
            word += c;
        }
    };
    Word(const Word& w, int n) {//4
        if (w.word.length() <= 1) {
            word = w.word;
        }
        else {
            word = w.word.substr(0, n) + w.word.substr(w.word.length() - n, n);
        }
    };
    Word(const Word& w) { //5
        word = w.word;
    };

    void set_word() {    //Ввод с клавиатуры
        cout << "Введи слово " << endl;
        getline(cin, word);
    }
    void print_word() { //Печать
        cout << word << endl;
    }

    string make_word() {
        string temp;
        int count = 0;
        const char a[26] = { 'a','b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v','w','x','y','z' };
        for (int i = 0; i < 26; i++) {
            count = 0;
            for (int j = 0; j < word.length(); j++) {
                if(word.at(j) == a[i])
                count++;
                if (count == 2) {
                    temp.push_back(a[i]);
                    count++;
                }
            }
        }
        return temp;
    }
};


int main() {
    setlocale(LC_ALL, "Russian");
    Word w_1;
    Word w_2 = "Pneumonoultramicroscopicsilicovolcanoconiosis";
    Word w_3 = Word('c', 3);
    Word w_4 = Word(w_2, 2);
    Word w_5 = w_3;
    w_2.print_word();
    cout << endl << "Результат: " << endl;
    Word w_res = Word(w_2.make_word());
    //w_2.make_word();
    w_res.print_word();
    return 0;
}
