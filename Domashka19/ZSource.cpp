#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

int n,m;

//������ 1
int nod(int a, int b);
//������ 2
int resurveNumber(int number);
//������ 3
size_t func(int* arr, size_t sz, int n);
void coutArr(int* arr, size_t sz);
int* createArr(size_t sz);

int main() {
	setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    //������ 1
    cout << "������ 1.\n";
    cout  << nod(n, m);
    cout << "\n\n";

    //������ 2
    cout << "������ 2.\n������� �����: ";
    cin >> n;
    resurveNumber(n);
    cout << endl;

    //������ 3
    int Q = 0;
    size_t sz = 0;
    cout << "������ 3.\n������� ����� �������: ";
    cin >> sz;
    cout << "����������� ������:\n";

    int* arr = createArr(sz);
    coutArr(arr, sz);

    int n = 0;
    cout << "\n";
    cout << "�������� ����� �� �������: ";
    cin >> n;

    size_t posN = func(arr, sz, n);
    cout << "������� ����� � �������: " << posN << "\n�������� ������:\n";
    coutArr(arr, sz);
        
    delete[] arr;

	return 0;
}
//������ 1
int nod(int a, int b) {
    cout << "������� 2 �����: ";
    int nod = 1;
    cin >> a >> b;
    for (int i = a; i > 0; i--) {
        if (a % i == 0 && b % i == 0) {
            nod = i;
            break;
        }
    }
    cout << "H��������� ����� ��������: ";

    return nod;
}
//������ 2
int resurveNumber(int number){
    int n = 0;
    while (number)
    {
        n = 10 * n + number % 10;
        number /= 10;
    }
    cout <<"�������� ����� � ��������� ����: " << n << endl;
    return n;
}
//������ 3
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
