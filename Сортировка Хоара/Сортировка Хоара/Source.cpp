#include <iostream>
#include <clocale>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int part(int arr[], int low, int high) {
    int p = arr[high]; 
    int i = low - 1;       

    for (int j = low; j <= high - 1; j++) {
        
        if (arr[j] <= p) {
            i++; 
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1; 
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
       
        int pi = part(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Ru");
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Исходный массив: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Отсортированный массив: ";
    printArray(arr, n);

    return 0;
}