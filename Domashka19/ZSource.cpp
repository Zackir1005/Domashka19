#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

int n,m;

//Задача 1
int nod(int a, int b);
//Задача 2
int resurveNumber(int number);
//Задача 3
size_t func(int* arr, size_t sz, int n);
void coutArr(int* arr, size_t sz);
int* createArr(size_t sz);

int main() {
	setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    //Задача 1
    cout << "Задача 1.\n";
    cout  << nod(n, m);
    cout << "\n\n";

    //Задача 2
    cout << "Задача 2.\nВведите число: ";
    cin >> n;
    resurveNumber(n);
    cout << endl;

    //Задача 3
    int Q = 0;
    size_t sz = 0;
    cout << "Задача 3.\nВведите длину массива: ";
    cin >> sz;
    cout << "Изначальный массив:\n";

    int* arr = createArr(sz);
    coutArr(arr, sz);

    int n = 0;
    cout << "\n";
    cout << "Выберите число из массива: ";
    cin >> n;

    size_t posN = func(arr, sz, n);
    cout << "Позиция числа в массива: " << posN << "\nИтоговый массив:\n";
    coutArr(arr, sz);
        
    delete[] arr;

	return 0;
}
//Задача 1
int nod(int a, int b) {
    cout << "Введите 2 числа: ";
    int nod = 1;
    cin >> a >> b;
    for (int i = a; i > 0; i--) {
        if (a % i == 0 && b % i == 0) {
            nod = i;
            break;
        }
    }
    cout << "Hаибольший общий делитель: ";

    return nod;
}
//Задача 2
int resurveNumber(int number){
    int n = 0;
    while (number)
    {
        n = 10 * n + number % 10;
        number /= 10;
    }
    cout <<"Введённое число в отражённом виде: " << n << endl;
    return n;
}
//Задача 3
size_t func(int* arr, size_t sz, int n) {
    size_t posN = sz;
    for (size_t i = 0; i < sz; ++i) {
        if (arr[i] == n) {
            posN = i;
            break;
        }
    }
    if (posN == sz) return sz;
    sort(&arr[posN + 1], &arr[sz]);
    return posN;
}

void coutArr(int* arr, size_t sz) {
    for (size_t i = 0; i < sz; ++i) {
        cout << arr[i] << " ";
    } cout << "\n";
}

int* createArr(size_t sz) {
    int* arr = new int[sz];
    for (size_t i = 0; i < sz; ++i) {
        arr[i] = rand() % 20 - 10;
    } return arr;
}
