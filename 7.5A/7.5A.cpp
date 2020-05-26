#include <iostream>
#include <stdlib.h>
#include <queue>
#include <stdio.h>
#include <string>
#include <fstream>

using namespace std;

queue <string*> bsev;
int tempint;
class Files {
	ifstream in;
	ofstream out;
public:
	//Создаёт файл  с текстом
	void File_gen() {
		out.open("Text.txt");
		out << "Magna copiosae apeirian ius at Per in illud petentium iudicabit integre sententiae pro no Ceteros assentior omittantur cum ad Eu eam dolores lobortis percipitur quo te equidem deleniti disputando Tation delenit percipitur at vix An eos iusto solet id mel dico habemus Tation delenit percipitur at vix Nec labore cetero theophrastus no ei vero facer veritus nec Postulant assueverit ea his Eu eam dolores lobortis percipitur quo te equidem deleniti disputando Odio contentiones sed cu usu commodo prompta prodesset id";
		out.close();
	}
	void FileOpen(string FileName) {
		in.open(FileName);
	}
	void FileClose(string FileName) {
		out.close();
	}
	//открывает файл и выводит стек на экран
	void FileOpenAndOut(int size, string* str) {
		in.open("Text.txt");
		for (int i = 0; i < size && str[i] != " "; i++) {
			in >> str[i];
			bsev.push(&str[i]);
			//str = new string;
			tempint = i;
		}
		
		for (int i = 0; i < size && bsev.empty() == false; i++) {
			string b = *bsev.front();
			if (b.at(0) == 'a')
			cout << b << " ";
			bsev.pop();
		}
	}
};

int main() {
	Files RandomData;
	const int mas_size = 80;
	string temp[mas_size];
	RandomData.File_gen();
	RandomData.FileOpenAndOut(mas_size, temp);
}