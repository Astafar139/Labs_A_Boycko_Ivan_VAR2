#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <ctime>

using namespace std;
//Out
void mat_out(int* a, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = i * size; j < (i + 1) * size; j++) {
			cout << a[j] << " ";
		}
		cout << endl;
	}
}
//Создание квадратной матрицы
//int** matrixPTR(int size) {
//	for (int i = 0; i < size * size; i++) {
//
//	}
//}
int* matrixCreate(int size) {
	int* a = new int[pow(size, 2)];
	return a;
}
//Заполняет матрицу случайными числами
void matrixRandom(int* a, int size) {
	srand(time(0));
	for (int i = 0; i < pow(size, 2); i++) {
		a[i] = (rand() % 100) - 50;
	}
}
//
int max_int_finder(int* a, int size) {
	int temp = a[0];
	for (int i = 1; i < size; i++) {
		if (a[i] > temp) {
			temp = a[i];
		}
	}
	return temp;
}
int norma_Finder(int* a, int size) {
	int* resar = new int[size];
	for (int i = 0; i < size; i++) resar[i] = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			resar[i] += abs(a[(j * size)+i]);
		}
	}
	return max_int_finder(resar, size);
}

int main() {
	int size = 8;
	int* matrix = matrixCreate(size);
	matrixRandom(matrix, size);
	cout << "Original matrix is: " << endl;
	mat_out(matrix, size);
	cout << "Norma is " << norma_Finder(matrix, size);
	return 0;
}