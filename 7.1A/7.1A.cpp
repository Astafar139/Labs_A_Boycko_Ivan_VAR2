#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string.h>
#include <math.h>




int min_int_id = 0;
int max_int_id = 0;
int result_array_size;
using namespace std;
//создаёт массив в динамической памяти
int* arrayCreator(int ar_size) {
	int* a = new int[ar_size];
	return a;
}
//удаляет массив
void arrayDestroyer(int* a) {
	delete[] a;
}
//ищем максимальное число
void max_int_finder(int* a, int size) {
	int temp = a[0];
	for (int i = 1; i < size; i++) {
		if (a[i] > temp) {
			temp = a[i];
			max_int_id = i;
		}
	}
}
//ищет минимальное число
void min_int_finder(int* a, int size) {
	int temp = a[0];
	for (int i = 1; i < size; i++) {
		if (a[i] < temp) {
			temp = a[i];
			min_int_id = i;
		}
	}
}
//меняет числа местами
void replacer(int* a, int min_id, int max_id) {
	swap(a[min_id], a[max_id]);
}
//делает из двух массивов один
int* array_combo(int* a, int* b, int size_a,int size_b) {
	int* c = new int[size_a + size_b];
	for (int i = 0; i < size_a; i++) {
		c[i] = a[i];
	}
	for (int i = 0; i < size_b; i++) {
		c[size_a + i] = b[i];
	}
	result_array_size = size_a + size_b;
	arrayDestroyer(a);
	arrayDestroyer(b);
	return c;
}
//выводит массив
void array_out(int* a, int size) {
	cout << "Array -->" << endl;
	for (int i = 0; i < size; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
//даёт массиву рандомные значения
void array_randomizer(int* a, int size) {
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		a[i] =10+ rand() % 90;//двухзначные цифры для адекватного размера
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	int size = 10; //All Array size
	int* mas_one = arrayCreator(size);
	int* mas_two = arrayCreator(size);
	int min, max;
	array_randomizer(mas_one, size);
	array_randomizer(mas_two, size);
	cout << "Начальные массивы: ";
	array_out(mas_one, size); array_out(mas_two, size);
	int* result_array = array_combo(mas_one, mas_two, size, size);
	cout << "Совмещённый массив: ";
	array_out(result_array,result_array_size);
	min_int_finder(result_array, result_array_size);
	max_int_finder(result_array, result_array_size);
	replacer(result_array, min_int_id, max_int_id);
	cout << "Массив после условия задачи: ";
	array_out(result_array, result_array_size);
	arrayDestroyer(result_array);
}