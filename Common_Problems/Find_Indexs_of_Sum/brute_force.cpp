#include <iostream>

int* findIndexes(int*, int*, int, int);

int main() {
    int array[] = {1, 3, 7, 9, 2};
    const int target = 11;
    int result[] = {-1,-1};
    int length = sizeof(array)/sizeof(array[0]);
    
    findIndexes(array, result, length, target);

    std::cin.get();

    return 1;
}

int* findIndexes(int *array, int* result, int length, int target){
    for (int i = 0; i < length; ++i){
        int numberToFind = target - array[i];

        for (int j = i+1; j < length; ++j){
            if (array[j] == numberToFind){
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return result;
}