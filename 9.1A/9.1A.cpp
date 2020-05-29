#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include <string.h>

using namespace std;
int min_int_id = 0;
int max_int_id = 0;

template <class T> void swap(T& a, T& b)
{
    T c(a); a = b; b = c;
}

void max_int_finder(vector <int> a, int size) {
    int temp = a[0];
    for (int i = 1; i < size; i++) {
        if (a.at(i) > temp) {
            temp = a.at(i);
            max_int_id = i;
        }
    }
}
//ищет минимальное число
void min_int_finder(vector <int> a, int size) {
    int temp = a[0];
    for (int i = 1; i < size; i++) {
        if (a.at(i) < temp) {
            temp = a.at(i);
            min_int_id = temp;
        }
    }
}
//меняет числа местами




int main()
{
    setlocale(LC_ALL, "rus");
    int n, k;
    srand(time(0));//рандом
    cout << "Введите количество элементов:";
    cin >> n;
    vector <int> v1;// Вектор для чисел
    vector <int> v2;// Вектор для чисел
    vector <int> res;// Вектор из двух других векторов
    //заполение двух векторов числами
    for (int j = 0; j < n; ++j) {
        v1.push_back(j);
    }
    srand(time(0));
    for (int j = 0; j < n; ++j) {
        v2.push_back(j+n);
    }
    //определение рез. вектора
    for (int i = 0; i < n; i++) {
        res.push_back(v1.at(i));
    }
    for (int i = 0; i < n; i++) {
        res.push_back(v2.at(i));
    }

    cout << "\nНачальный вектор 1 : " << endl;
    for (int i = 0; i < n; ++i) {
        cout << v1.at(i) << " ";
    }
    cout << "\nНачальный вектор 2 : " << endl;
    for (int i = 0; i < n; ++i) {
        cout << v2.at(i) << " ";
    }
    //получение номеров элементов с самым большим и самым маленьким значением
    min_int_finder(res, 2*n);
    max_int_finder(res, 2*n);
    //меняем местами числа
    int temp = res.at(max_int_id); res.at(max_int_id) = res.at(min_int_id); res.at(min_int_id) = temp;
   // delete &temp;

    cout << endl << "итоговый вектор: " << endl;
    for (int i = 0; i < 2*n; ++i) {
        cout << res.at(i) << " ";
    }
    return 0;
}
