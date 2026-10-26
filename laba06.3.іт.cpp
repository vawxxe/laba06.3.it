
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Прототип звичайної функції
int CountOdd(int* a, const int size);

// Прототип шаблонної функції
template <typename T>
int CountOdd(T* a, const int size);

int main()
{
    const int n = 10;

    srand(static_cast<unsigned int>(time(nullptr)));

    // Масив цілих чисел
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 101 - 50;
    }

    cout << "Integer array:" << endl;
    for (int i = 0; i < n; i++)
        cout << setw(5) << a[i];
    cout << endl;

    // 1. Звичайна функція
    int result1 = CountOdd(a, n);
    cout << "CountOdd(a, n) = " << result1 << endl;

    // 2. Шаблонна функція для int
    int result2 = CountOdd<int>(a, n);
    cout << "CountOdd<int>(a, n) = " << result2 << endl;

    // Масив типу long
    long b[n];
    for (int i = 0; i < n; i++)
    {
        b[i] = rand() % 101 - 50;
    }

    cout << endl << "Long array:" << endl;
    for (int i = 0; i < n; i++)
        cout << setw(5) << b[i];
    cout << endl;

    // Шаблонна функція для long
    int result3 = CountOdd<long>(b, n);
    cout << "CountOdd<long>(b, n) = " << result3 << endl;

    return 0;
}

// Реалізація звичайної функції
int CountOdd(int* a, const int size)
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (a[i] % 2 != 0)
            count++;
    }

    return count;
}

// Реалізація шаблонної функції
template <typename T>
int CountOdd(T* a, const int size)
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (a[i] % 2 != 0)
            count++;
    }

    return count;
}
