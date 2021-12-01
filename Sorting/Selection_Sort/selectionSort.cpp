#include <iostream>

using namespace std;

void selection_sort(int *, int);
void print_array(int *, int);

int main() {
    int array[] = {54,26,93,17,77,31,44,55,20};
    int size = sizeof(array)/sizeof(array[0]);

    print_array(array, size);
    selection_sort(array, size);
    print_array(array, size);
}

void selection_sort(int *array, int size){
    for (int i = size-1; i >= 0; --i) {
        int max = i;
        for (int j = 0; j < i; ++j) {
            if (array[j] > array[max]) {
                max = j;
            }
        }
        int temp = array[i];
        array[i] = array[max];
        array[max] = temp;
    } 
}

void print_array(int *array, int size) {
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << '\n';
}