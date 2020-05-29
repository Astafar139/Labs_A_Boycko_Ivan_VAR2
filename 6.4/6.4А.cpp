#include <iostream>
#include <math.h>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <stdlib.h>
#include <conio.h>

//UNCOMPLETED
using namespace std;

class Files {
	ifstream in;
	ofstream out;
public:
	//open file
	void FileOpen(string FileName) {
		in.open(FileName);
	}
	//close file
	void FileClose(string FileName) {
		out.close();
	}
	//sort file
	void FileSort_and_out(string FileNameIN, string FileNameOUT, int size, int numbers[]) {
		FileOpen(FileNameIN);
		for (int i = 0; i < size; i++) {
			in >> numbers[i];
		}
		in.close();
		out.open(FileNameOUT);
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (numbers[i] > numbers[j]) swap(numbers[i], numbers[j]);
			}
		}
		for (int i = 0; i < size; i++) {
			out << numbers[i] << "\0" << " ";
		}
		out.close();
	}
	//out and close
	void FileScript_SaveExit(string FileName, int numbers[], int size) {
		out.open(FileName);
		for (int i = 0; i < size; i++) {
			out << numbers[i] << "\0" << " ";
		}
		out.close();
	}
	void DataCreate(int numbers[], int size) {
		for (int i = 0; i < size; i++) {
			srand(time(0));
			if (i % 5 == 0) system("ping -n 0.5 127.0.0.1 > nul");//это не имеет особого значения...
			//numbers[i] = ((rand() % 48) * pow(-1, size - i) - (rand() % 64) * pow(-1, i+1));
			numbers[i] = (rand() % 100) - 70 + i;
			if (numbers[i] > (-10) && numbers[i] < 10) {
				numbers[i] = 15 * pow((-1), i);
			}
			srand(time(0));
		}
	}
};

int main() {
	Files RandomData;
	ifstream fin;
	ofstream fout;
	for (int i = 0; i < 10; i++) {
		int mas_size = 100000000;
		int* numbers = new int[mas_size];
		//int size = 0;
		//cout << "Array size ( < 32368) ->>";
		//cin >> size;


		//txt
		RandomData.DataCreate(numbers, mas_size);//Создаёт массив чисел
		RandomData.FileScript_SaveExit("B62TextIN.txt", numbers, mas_size);//Заполняет и закрывает файл
		RandomData.FileSort_and_out("B62TextIN.txt", "B62TextOUT.txt", mas_size, numbers);


		//bin
		srand(time(0));
		RandomData.DataCreate(numbers, mas_size);//Создаёт массив чисел
		RandomData.FileScript_SaveExit("B62TextIN.bin", numbers, mas_size);//Заполняет и закрывает файл
		RandomData.FileSort_and_out("B62TextIN.bin", "B62TextOUT.bin", mas_size, numbers);
		//Сортирует данные из файла 1 и записыват их в файл 2
		delete[] numbers;
	}
}