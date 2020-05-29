#include <iostream>
#include <ctime>
#include <vector>

using namespace std;
int max_int = 0;
void print_matrix(int, vector<int>, vector<vector<int>>);//Функция отображения векторов
int norma_Finder(vector<vector <int>> A, int size);
int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    int n;
    cout << "Введите число ";
    cin >> n;
    vector <vector<int>> A(n);//вектор векторов
    for (int i = 0; i < n; i++)
        A[i].reserve(n);
    vector<int> B;//вектор
    B.reserve(n * n);

    //Заполнение векторов
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i].push_back(10 + rand() % 90);
            B.push_back(10 + rand() % 90);
        }
    }
    cout << "исходная матрица" << endl;
    print_matrix(n, B, A);

    //Переменные для хранения информации о максимальных числах в векторах
    /*int i_a_max = 0;
    int i_b_max = 0;
    int j_a_max = 0;
    int max_a = A[0][0];
    int max_b = B[0];*/

    //Нахождение максимальных значений в векторах
    /*for (int i = 0; i < n; ++i) {
        if (A[i][i] > max_a) {
            max_a = A[i][i];
            j_a_max = i;
            i_a_max = i;
        }
        if (A[n - 1 - i][i] > max_a) {
            max_a = A[n - 1 - i][i];
            j_a_max = i;
            i_a_max = n - 1 - i;
        }
        if (B[i * n + i] > max_b) {
            max_b = B[i * n + i];
            i_b_max = i * n + i;
        }
        if (B[(n - 1) * (n - i)] > max_b) {
            max_b = B[(n - 1) * (n - i)];
            i_b_max = (n - 1) * (n - i);
        }
    }*/

    //Норма матрицы
    cout << "Norma is " << norma_Finder(A,n) << endl;

    /*cout << "Конечная матрица" << endl;
    print_matrix(n, B, A);

    return 0;*/
}

void print_matrix(int n, vector<int> B, vector<vector<int>> A) {
    cout << "A: " << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << A[i][j] << "\t";
        }
        cout << "\n\n";
    }
   /* cout << "B: " << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << B[i * n + j] << "\t";
        }
        cout << "\n\n";
    }*/
}

int max_int_finder(vector <int> a, int size) {
    int temp = a[0];
    for (int i = 1; i < size; i++) {
        if (a.at(i) > temp) {
            temp = a.at(i);
            max_int = i;
        }
    }
    return temp;
}
int norma_Finder(vector<vector <int>> A, int size) {
    vector <int> resar(size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            resar.at(i) += abs(A[i][j]);
        }
    }
    return max_int_finder(resar, size);
}