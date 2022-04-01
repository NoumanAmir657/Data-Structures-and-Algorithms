#include <iostream>
using namespace std;

void bubble_sort(int *, int);
void print_array(int *, int);

int main() {
    int array[] = {54,26,93,17,77,31,44,55,20};
    int size = sizeof(array)/sizeof(array[0]);

    print_array(array, size);
    bubble_sort(array, size);
    print_array(array, size);
}

void bubble_sort(int *array, int size) {
    for (int i = 0; i < size-1; ++i) {
        for (int j = 0; j < size-1-i; ++j){
            if (array[j] > array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

void print_array(int *array, int size) {
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << '\n';
}