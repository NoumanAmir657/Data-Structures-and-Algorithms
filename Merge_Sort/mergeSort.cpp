#include <iostream>
using namespace std;

void merge_sort(int *, int, int);
void merge(int *, int, int, int);
void print_array(int *, int);

int main() {
    int array[] = {54,26,93,17,77,31,44,55,20};
    int size = sizeof(array)/sizeof(array[0]);

    print_array(array, size);
    merge_sort(array, 0, size-1);
    print_array(array, size);
}

void merge_sort(int *array, int first, int last) {
  if (first < last) {
    int midpoint = first + (last - first) / 2;
    merge_sort(array, first, midpoint);
    merge_sort(array, midpoint+1, last);
    merge(array, first, midpoint, last);
  }
}

void merge(int *array, int const left, int const mid, int const right) {
  auto const subArray1 = mid - left + 1;
  auto const subArray2 = right - mid;

  auto *leftArray = new int [subArray1];
  auto *rightArray = new int [subArray2];

  for (auto i = 0; i < subArray1; i++) {
    leftArray[i] = array[left+i];
  }
  for (auto j = 0; j < subArray2; j++) {
    rightArray[j] = array[mid+1+j];
  }

  auto index1 = 0, index2 = 0;
  int mergeIndex = left;

  while(index1 < subArray1 && index2 < subArray2) {
    if (leftArray[index1] <= rightArray[index2]){
      array[mergeIndex] = leftArray[index1];
      index1++;
    }
    else {
      array[mergeIndex] = rightArray[index2];
      index2++;
    }
    mergeIndex++;
  }

  while (index1 < subArray1) {
    array[mergeIndex] = leftArray[index1];
    ++index1;
    ++mergeIndex;
  }

  while (index2 < subArray2) {
    array[mergeIndex] = rightArray[index2];
    ++index2;
    ++mergeIndex;
  }
}

void print_array(int *array, int size) {
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << '\n';
}