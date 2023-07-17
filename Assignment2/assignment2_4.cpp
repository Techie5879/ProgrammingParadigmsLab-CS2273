// Aritra Bandyopadhyay 2021CSB107
// Assignment2_4 Generic Sorting

#include <iostream>

using namespace std;

const int ARR_SIZE = 5;

struct MyStruct {
    int data1;
    int data2;
};

// comparator function for struct
bool myStructComparator(const MyStruct &a, const MyStruct &b) {
    return a.data1 > b.data1;
}


// overloaded insertion sort function passing comparator function to sort structs also
template <typename T>
void insertionSort(T arr[], int size, bool (*compare)(const T &a, const T &b)) {
    for (int i = 1; i < size; i++) {
        T key = arr[i];
        int j = i - 1;

        while (j >= 0 && compare(arr[j], key)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


template <typename T>
void insertionSort(T arr[], int n) {
    for (int i = 1; i < n; i++) {
        T key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

template <typename T>
void printArray(T* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// overloaded function for struct
void printArray(MyStruct *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << "MyStruct[" << i << "]: data1 = " << arr[i].data1 << ", data2 = " << arr[i].data2 << endl;
    }
}

template <typename T>
void getArrayInput(T* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Enter element arr[" << i << "]: ";
        cin >> arr[i];
    }
}




int main() {
    int intArr[ARR_SIZE];
    short shortArr[ARR_SIZE];
    float floatArr[ARR_SIZE];
    double doubleArr[ARR_SIZE];

    cout << "\nFill Integer array: " << endl;
    getArrayInput(intArr, ARR_SIZE);
    cout << "\nInitially: ";
    printArray(intArr, ARR_SIZE);
    insertionSort(intArr, ARR_SIZE);
    cout << "After sorting: ";
    printArray(intArr, ARR_SIZE);

    cout << "\nFill Short array: " << endl;
    getArrayInput(shortArr, ARR_SIZE);
    cout << "\nInitially: ";
    printArray(shortArr, ARR_SIZE);
    insertionSort(shortArr, ARR_SIZE);
    cout << "After sorting: ";
    printArray(shortArr, ARR_SIZE);

    cout << "\nFill Float array: " << endl;
    getArrayInput(floatArr, ARR_SIZE);
    cout << "\nInitially: ";
    printArray(floatArr, ARR_SIZE);
    insertionSort(floatArr, ARR_SIZE);
    cout << "After sorting: ";
    printArray(floatArr, ARR_SIZE);

    cout << "\nFill Double array: " << endl;
    getArrayInput(doubleArr, ARR_SIZE);
    cout << "\nInitially: ";
    printArray(doubleArr, ARR_SIZE);
    insertionSort(doubleArr, ARR_SIZE);
    insertionSort(doubleArr, ARR_SIZE);
    cout << "After sorting: ";
    printArray(doubleArr, ARR_SIZE);



    MyStruct structArr[ARR_SIZE];
    cout << endl;

    // Inputting data into the struct array
    for (int i = 0; i < ARR_SIZE; i++) {
        cout << "Enter data for structArr[" << i << "]: " << endl;
        cout << "data1: ";
        cin >> structArr[i].data1;
        cout << "data2: ";
        cin >> structArr[i].data2;
    }
    cout << endl << "Initially: " << endl;
    printArray(structArr, ARR_SIZE);
    insertionSort(structArr, ARR_SIZE, myStructComparator);
    cout << endl << "After sorting: " << endl;
    printArray(structArr, ARR_SIZE);

}