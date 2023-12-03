#include <iostream>
#include <cmath>

using namespace std;

void fillArray(double*& arr, int n) {
    arr = new double[n];
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }
}

void printArray(const double* arr, int n) {
    cout << "Array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int findMaxAbsIndex(const double* arr, int n) {
    int maxIndex = 0;
    for (int i = 1; i < n; ++i) {
        if (abs(arr[i]) > abs(arr[maxIndex])) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

double sumAfterFirstPositive(const double* arr, int n) {
    bool foundPositive = false;
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        if (foundPositive) {
            sum += arr[i];
        }
        else if (arr[i] > 0) {
            foundPositive = true;
        }
    }
    return sum;
}

void rearrangeArray(double*& arr, int n, double a, double b) {
    int i = 0, j = n - 1;
    while (i < j) {
        while (i < j && static_cast<int>(arr[i]) >= a && static_cast<int>(arr[i]) <= b) {
            ++i;
        }
        while (i < j && (static_cast<int>(arr[j]) < a || static_cast<int>(arr[j]) > b)) {
            --j;
        }
        if (i < j) {
            std::swap(arr[i], arr[j]);
            ++i;
            --j;
        }
    }
}

int main() {
    int n;
    double a, b;

    cout << "Enter the size of the array (n): ";
    cin >> n;

    double* arr;
    fillArray(arr, n);
    printArray(arr, n);

    int maxAbsIndex = findMaxAbsIndex(arr, n);
    cout << "1.1. Index of the maximum absolute element: " << maxAbsIndex << "\n";

    double sumAfterPositive = sumAfterFirstPositive(arr, n);
    cout << "1.2. Sum of elements after the first positive element: " << sumAfterPositive << "\n";

    cout << "Enter the values of a and b: ";
    cin >> a >> b;

    rearrangeArray(arr, n, a, b);

    printArray(arr, n);

    delete[] arr;
    return 0;
}