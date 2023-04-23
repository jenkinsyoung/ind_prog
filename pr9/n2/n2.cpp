#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;
template<typename T>
void quickSort(T* arr, int left, int right) {
    int i = left, j = right;
    T temp;
    T pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}


int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    int size;
    cout << "Введите размер массива с целыми числами: ";
    cin >> size;
    int* int_arr = new int[size];
    cout << "Массив до сортировки: ";
    for (int i = 0; i < size; i++) {
        int_arr[i] = rand() % 25 + 1;
        cout << int_arr[i] << ", ";
    }
    cout << "\nПосле сортировки: ";
    quickSort(int_arr, 0, size-1);
    for (int i = 0; i < size; i++) {
        cout << int_arr[i] << ", ";
    }
    cout << endl << endl;

    cout << "Массив(double) до сортировки: ";
    double double_arr[5] = {14.21, 1.333, 0.45, 28.3, 3.845};
    for (int i = 0; i < 5; i++) {
        cout<< double_arr[i] <<", ";
    }
    quickSort(double_arr, 0, 4);
    cout << "\nПосле сортировки: ";
    for (int i = 0; i < 5; i++) {
        cout << double_arr[i] << ", ";
    }
    cout << endl << endl;

    cout << "Массив из строк до сортировки:\n";
    string string_arr[] = { "Daniel Defoe", "Emily Bronte", "Lewis Carroll", "Agatha Christie", "Leo Tolstoy" };
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ") " << string_arr[i] << "\n";
    }
    cout << endl;
    quickSort(string_arr, 0, 4);
    cout << "После сортировки:\n";
    for (int i = 0; i < 5; i++) {
        cout <<i+1<<") "<< string_arr[i] << "\n";
    }
    cout << endl;

    return 0;
}
