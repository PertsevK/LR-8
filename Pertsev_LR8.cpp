#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int N = 20, M = 20;

void Array81(); // Дан масив розміру N і ціле число K (1 ≤ K <N). Здійснити зрушення елементів
// масиву вправо на K позицій(при цьому A1 перейде в AK + 1, A2 - в AK + 2, ..., AN - K- в AN,
// а початкове значення K останніх елементів буде втрачено).Перші K
// елементів отриманого масиву покласти рівними 0.

void Matrix42(); // Дана матриця розміру M × N. Знайти кількість її рядків, елементи яких
// впорядковані за зростанням.

bool get_Task3(char* filename, double a[N], int& n); // Шейкерна - Зростання - Дійсний
void show_Task3();

bool get_mas81(char* filename, int a[N], int& n); // Функція введення масиву з файла
void calc81(int a[N], int&n); // Функція розрахунку
void show_mas81(char* filename, int a[N], int& n); // Функція запису масива в файл та виведення його в консоль
bool get_mat42(char* filename, int a[M][N], int& n, int& m); // Функція введення масиву з файла
int calc42(int a[M][N], int& n, int& m); // Функція розрахунку
void show_mat42(char* filename, int res); // Функція запису результату в файл та виведення його в консоль


bool cor_main(int); // Допоміжнi функції

int main()
{ // Перемикання між завданнями
    setlocale(LC_ALL, "Ukrainian");
    int num; // Оголошення
    do
    {
        cout << "Введiть номер завдання (вихiд - 4)\n";
        cin >> num; // Введення даних
        if (cor_main(num))
        {
            switch (num)
            {
            case 1: Array81(); break; // Завдання 1
            case 2: Matrix42(); break; // Завдання 2
            case 3: show_Task3(); break; // Завдання 3
            case 4: cout << "Вихiд..."; break;
            }
        }
        else cout << "Помилка. Потрiбно ввести 1, 2, 3\n"; // Повідомлення про помилку
    } while (num != 4);
}

bool cor_main(int n) // Допоміжна
{
    if (n == 1 || n == 2 || n == 3 || n == 4) return true;
    else return false;
}

void Array81()
{
    int a[N]; // Оголошення масиву
    int n; // Реальний розмір масиву
    char filename[100]; // Оголошення імені файла
    ofstream fout(filename);
    cout << "Введiть назву файлу (array_in_5.txt)\n";
    cin >> filename; // Введення ім'я файла
    if (get_mas81(filename, a, n))
    {
        calc81(a, n); // Функція розрахунку
        show_mas81(filename, a, n); // Функція виведення
    }
}

bool get_mas81(char* filename, int a[N], int& n)
{
    ifstream fin(filename);
    if (!fin.is_open()) // Перевірка на коректність даних
    {
        cout << "Помилка" << endl;
        return false;
    }
    else {
        fin >> n;
        for (int i = 0; i < n; i++) { // Введення елементів масива з файлу
            fin >> a[i];
        }
    }
    fin.close();
    return true;
}

void calc81(int a[N], int& n)
{
    int K; // Оголошення К
    cout << "Введiть число K\n";
    cin >> K; // Введення К
    if (K > 0)
    {
        cout << "Елементи масиву пiсля зрушення:\n";
        for (int k = n - 1;k >= 0;k--) // Цикл зрушення елементів
        {
            if (k >= K) a[k] = a[k - K]; // Елементи до К замінюютьсяна 0
            if (k < K) a[k] = 0; // Елементи після - k-K
        }
    }
    else cout << "Помилка" << endl; // Сповіщення про помилку
}

void show_mas81(char* filename, int a[N], int& n)
{
    for (int k = 0;k < n;k++) cout << a[k] << " "; // Вивід елементів а
    cout << "\nКуди записати? (array_out_5.txt)\n";
    cin >> filename;
    ofstream fout(filename, ios_base::out);
    for (int i = 0; i < n; i++) {
        fout << a[i] << " ";
    }
    fout.close();
}

void Matrix42()
{
    int a[M][N]; // Оголошення матриці
    int m, n, res; // Оголошення реальних розмірів
    char filename[100];
    ofstream fout(filename);
    cout << "Введiть назву файлу (matr_in_5.txt)\n";
    cin >> filename; // Введення назви файла
    if (get_mat42(filename, a, m, n))
    {
        res = calc42(a, n, m); // Функція розрахунку
        show_mat42(filename, res); // Функція запису результату в файл та виведення його в консоль
    }
}

bool get_mat42(char* filename, int a[M][N], int& n, int& m)
{
    ifstream fin(filename);
    if (!fin.is_open()) { // Перевірка даних на коректність
        cout << "Error! Can't open file!" << endl;
        return false;
    }
    else {
        fin >> m; // Введення розміру матриці
        fin >> n;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                fin >> a[i][j]; // Введення елементів матриці
            }
        }
    }
    fin.close();
    return true;
}

int calc42(int a[M][N], int& n, int& m)
{
    int num = 0; // Змінна, яка потрібна для підрахунку рядків
    for (int k = 0; k < m; k++)
    {
        int count = 0; // Змінна, яка потрібна для підрахунку елементів в рядку, які впорядковані за зростанням
        for (int p = 0;p < n - 1; p++)
        {
            if (a[k][p] < a[k][p + 1]) count++;
        }
        if (count == n - 1) num++; // Перевірка, чи дорівнює кількість підрахованих елементів загальної кількості елементів у рядку
    }
    return num;
}

void show_mat42(char* filename, int res)
{
    cout << "Кiлькiсть рядкiв матрицi елементи яких впорядкованi за зростанням - " << res << endl; // Виведення відповіді
    ofstream fout(filename, ios_base::app);
    fout << "\nКiлькiсть рядкiв матрицi елементи яких впорядкованi за зростанням - " << res << endl;
    fout.close();
}

bool get_Task3(char* filename, double a[N], int& n)
{
    ifstream fin(filename);
    if (!fin.is_open()) // Перевірка даних
    {
        cout << "Помилка" << endl;
        return false;
    }
    else { // Отримання даних з файла
        fin >> n; 
        for (int i = 0; i < n; i++) {
            fin >> a[i]; // Введення елементів масиву
        }
    }
    fin.close();
    return true;
}

void show_Task3()
{
    double a[N]; // Оголошення масиву
    int n; // Оголошення реального розміру масиву
    char filename[100];
    ofstream fout(filename);
    cout << "Введiть назву файлу (task3_in_5.txt)\n";
    cin >> filename; // Введення назви файла
    if (get_Task3(filename, a, n)) // Шейкерне сортування
    {
        int left, right, i;
        left = 0;
        right = n - 1;
        while (left <= right)
        {
            for (i = right; i >= left; i--) {
                if (a[i - 1] > a[i]) {
                    swap(a[i - 1], a[i]);
                }
            }
            left++;
            for (i = left; i <= right; i++) {
                if (a[i - 1] > a[i]) {
                    swap(a[i - 1], a[i]);
                }
            }
            right--;
        }
        cout << "Масив пiсля сортування -> ";
        for (int k = 0; k < n; k++) cout << a[k] << " ";
        cout << endl;
    }
}