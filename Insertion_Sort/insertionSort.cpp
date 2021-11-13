#include <iostream>
using namespace std;

void insertion_sort(int *, int);
void print_array(int *, int);

int main() {
    int array[] = {54,26,93,17,77,31,44,55,20};
    int size = sizeof(array)/sizeof(array[0]);

    print_array(array, size);
    insertion_sort(array, size);
    print_array(array, size);
}

void insertion_sort(int *array, int size) {
    for (int i = 1; i < size; ++i) {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j+1] = array[j];
            j = j -1;
        }
        array[j+1] = key;
    }
}

void print_array(int *array, int size) {
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << '\n';
}
