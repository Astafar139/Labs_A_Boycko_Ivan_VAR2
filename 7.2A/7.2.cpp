#include <iostream>
#include <fstream>
#include <ctime>
//Программа создаёт отпределённое кол-во студентов случайном образом, итог программы находиться в файле Out.txt в папке с проектом
//Советую не вводить слишком много цифр
using namespace std;

class Students {
	ifstream fin;
	ofstream fout;
public:
	void RandomDataLineCreate(int count_of_Lines, string FilenameOne, string FilenameTwo, string FilenameThree, string FilenameFour) {
		string Names[10] = { "Alex","Andrey","Hanry","John","Jakob","Rina","Nana","Mariko","Lucy","Elizabeth" };
		string VorNames[10] = { "Mint","Carter","May","Jones","Williams","Evans","Miller","Parker","Wood","Bennet" };
		string DateOneKurs[10] = { "17","18","19","18","17","18","19","19","18","18" };
		string DateTwoKurs[10] = { "19","20","20","20","19","20","21","21","20","20" };
		string DateThreeKurs[10] = { "21","21","22","21","20","21","22","22","21","21" };
		string DateFourKurs[10] = { "22","23","24","23","22","23","24","22","23","23" };
		string Result[10] = { "10","9","8","7","6","5","3","1","4","2" };
		fout.open(FilenameOne);
		srand(time(0));
		fout << "Kurs one\n";
		for (int i = 0; i <= count_of_Lines; i++) {
			fout << Names[(rand() % 10)];
			fout << " " << VorNames[(rand() % 10)];
			fout << " " << DateOneKurs[(rand() % 10)] << " " << "Years";
			fout << " " << Result[(rand() % 10)];
			if (Names[i] == "Rina" || Names[i] == "Nana" || Names[i] == "Mariko" || Names[i] == "Lucy" || Names[i] == "Elizabeth") fout << " Female";
			else fout << " Male";
			fout << "\n";
		}
		fout.close();
		fout.open(FilenameTwo);
		srand(time(0));
		fout << "Kurs two\n";
		for (int i = 0; i <= count_of_Lines; i++) {
			fout << Names[(rand() % 10)];
			fout << " " << VorNames[(rand() % 10)];
			fout << " " << DateTwoKurs[(rand() % 10)] << " " << "Years";
			fout << " " << Result[(rand() % 10)];
			if (Names[i] == "Rina" || Names[i] == "Nana" || Names[i] == "Mariko" || Names[i] == "Lucy" || Names[i] == "Elizabeth") fout << " Female";
			else fout << " Male";
			fout << "\n";
		}
		fout.close();
		fout.open(FilenameThree);
		srand(time(0));
		fout << "Kurs three\n";
		for (int i = 0; i <= count_of_Lines; i++) {
			fout << Names[(rand() % 10)];
			fout << " " << VorNames[(rand() % 10)];
			fout << " " << DateThreeKurs[(rand() % 10)] << " " << "Years";
			fout << " " << Result[(rand() % 10)];
			if (Names[i] == "Rina" || Names[i] == "Nana" || Names[i] == "Mariko" || Names[i] == "Lucy" || Names[i] == "Elizabeth") fout << " Female";
			else fout << " Male";
			fout << "\n";
		}
		fout.close();
		fout.open(FilenameFour);
		srand(time(0));
		fout << "Kurs four\n";
		for (int i = 0; i <= count_of_Lines; i++) {
			fout << Names[(rand() % 10)];
			fout << " " << VorNames[(rand() % 10)];
			fout << " " << DateFourKurs[(rand() % 10)] << " " << "Years";
			fout << " " << Result[(rand() % 10)];
			if (Names[i] == "Rina" || Names[i] == "Nana" || Names[i] == "Mariko" || Names[i] == "Lucy" || Names[i] == "Elizabeth") fout << " Female";
			else fout << " Male";
			fout << "\n";
		}

		fout.close();
	}
	void MaxYearsSearch(int count_of_Lines, string FilenameIn1, string FilenameIn2, string FilenameIn3, string FilenameIn4, string FilenameOut) {
		string* Names = new string[count_of_Lines];
		string* VorNames = new string[count_of_Lines];
		string* Sex = new string[count_of_Lines];
		int* Date = new int[count_of_Lines];
		string Temp;
		string* Result = new string[count_of_Lines];
		int prof = 0;
		fin.open(FilenameIn1);
		fin >> Temp >> Temp;
		fout.open(FilenameOut);
		for (int i = 0; i < count_of_Lines; i++) {
			fin >> Names[i] >> VorNames[i] >> Date[i] >> Temp >> Result[i] >> Sex[i];
		}
		cout << endl << "In One kurs older students is: \n";
		fout << endl << "In One kurs older students is: \n";
		for (int i = 0; i < count_of_Lines; i++) {
			prof = 0;
			for (int j = 0; j < count_of_Lines; j++) {
				if (Date[i] >= Date[j]) prof++;
			}
			if (prof == count_of_Lines) {
				cout << Names[i] << " " << VorNames[i] << " " << Date[i] << " Years " << Result[i] << " " << Sex[i] << "\n";
				fout << Names[i] << " " << VorNames[i] << " " << Date[i] << " Years " << Result[i] << " " << Sex[i] << "\n";
			}
		}
		fin.close();
		fin.open(FilenameIn2);
		fin >> Temp >> Temp;
		for (int i = 0; i < count_of_Lines; i++) {
			fin >> Names[i] >> VorNames[i] >> Date[i] >> Temp >> Result[i] >> Sex[i];
		}
		cout << endl << "In Two kurs older students is: \n";
		fout << endl << "In Two kurs older students is: \n";
		for (int i = 0; i < count_of_Lines; i++) {
			prof = 0;
			for (int j = 0; j < count_of_Lines; j++) {
				if (Date[i] >= Date[j]) prof++;
			}
			if (prof == count_of_Lines) {
				cout << Names[i] << " " << VorNames[i] << " " << Date[i] << " Years " << Result[i] << " " << Sex[i] << "\n";
				fout << Names[i] << " " << VorNames[i] << " " << Date[i] << " Years " << Result[i] << " " << Sex[i] << "\n";
			}
		}
		fin.close();
		fin.open(FilenameIn3);
		fin >> Temp >> Temp;
		for (int i = 0; i < count_of_Lines; i++) {
			fin >> Names[i] >> VorNames[i] >> Date[i] >> Temp >> Result[i] >> Sex[i];
		}
		cout << endl << "In Three kurs older students is: \n";
		fout << endl << "In Three kurs older students is: \n";
		for (int i = 0; i < count_of_Lines; i++) {
			prof = 0;
			for (int j = 0; j < count_of_Lines; j++) {
				if (Date[i] >= Date[j]) prof++;
			}
			if (prof == count_of_Lines) {
				cout << Names[i] << " " << VorNames[i] << " " << Date[i] << " Years " << Result[i] << " " << Sex[i] << "\n";
				fout << Names[i] << " " << VorNames[i] << " " << Date[i] << " Years " << Result[i] << " " << Sex[i] << "\n";
			}
		}
		fin.close();
		fin.open(FilenameIn4);
		fin >> Temp >> Temp;
		for (int i = 0; i < count_of_Lines; i++) {
			fin >> Names[i] >> VorNames[i] >> Date[i] >> Temp >> Result[i] >> Sex[i];
		}
		cout << endl << "In Four kurs older students is: \n";
		fout << endl << "In Four kurs older students is: \n";
		for (int i = 0; i < count_of_Lines; i++) {
			prof = 0;
			for (int j = 0; j < count_of_Lines; j++) {
				if (Date[i] >= Date[j]) prof++;
			}
			if (prof == count_of_Lines) {
				cout << Names[i] << " " << VorNames[i] << " " << Date[i] << " Years " << Result[i] << " " << Sex[i] << "\n";
				fout << Names[i] << " " << VorNames[i] << " " << Date[i] << " Years " << Result[i] << " " << Sex[i] << "\n";
			}
		}
		fin.close();
		fout.close();
	}
};



int main() {
	//переменная, отвечающая за количество студентов
	int count;
	Students Table;
	cout << "Enter Students count please ->> ";
	cin >> count; cout << endl;
	Table.RandomDataLineCreate(count, "StudentsLinesK_one.txt", "StudentsLinesK_two.txt", "StudentsLinesK_three.txt", "StudentsLinesK_four.txt");
	Table.MaxYearsSearch(count, "StudentsLinesK_one.txt", "StudentsLinesK_two.txt", "StudentsLinesK_three.txt", "StudentsLinesK_four.txt", "Out.txt");
}
