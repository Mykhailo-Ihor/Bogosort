#include <iostream>
#include <random>
#include <Windows.h>
#include <chrono>
using namespace std;
bool is_sorted(int arr[], int size) 
{
    for (int i = 1; i < size; ++i) 
    {
        if (arr[i] < arr[i - 1]) 
        {
            return false; 
        }
    }
    return true; 
}

void Shuffle(int* arr, int size) 
{
    random_device rd;
    mt19937 g(rd());
    shuffle(arr, arr + size, g);
}

int bogosort(int arr[], int size) 
{
    int counter = 0;
    while (!is_sorted(arr, size)) 
    {
        Shuffle(arr, size);
        ++counter;
    }
    return counter;
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 10,9 };
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Масив до сортування: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    auto start_time = chrono::steady_clock::now();
    int counter = bogosort(arr, size);
    auto end_time = chrono::steady_clock::now();
    cout << "Масив після сортування: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    chrono::duration<double> elapsed_time = end_time - start_time;
    cout << "Час виконання програми: " << elapsed_time.count() << " секунд" << std::endl;
    cout << "Кількість ітерацій: " << counter;
    return 0;
}