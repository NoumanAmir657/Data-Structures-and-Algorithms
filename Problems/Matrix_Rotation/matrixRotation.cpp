#include <iostream>
#include<vector>
using namespace std;

void matrix_rotation_2(vector<vector<int>>, int);

int main () {
    vector<vector<int>> vect
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    matrix_rotation_2(vect, 1);


}


void matrix_rotation_2(vector<vector<int>> matrix, int r){
    // if size is zero then no need to perform further operations
    if (matrix.size() == 0){
        return;
    }
    int number_of_rows = matrix.size(); // number of rows
    int number_of_cols = matrix[0].size(); // number of cols
    // layers found using the question statement that "minimum of m and n is even", so number of layers is minimum of m and n divided by 2
    int number_of_layers = number_of_rows < number_of_cols ? number_of_rows/2 : number_of_cols/2; //number of layers
    int p; // count variable for the 1D-Array
    int *array; // 1D-Array

    // loop that keeps track of layers
    for (int layer_counter = 0; layer_counter < number_of_layers; ++layer_counter){
        int number_of_elements = 2*number_of_rows + 2*number_of_cols - 4 - 8*layer_counter; // number of elements in a layer
        array = new int[number_of_elements]; // allocating memory to 1D-Array
        p = 0; // counter of 1D-Array initialiazed to zero

        // get the elements from the top row of the layer
        for (int j = layer_counter; j < number_of_cols-layer_counter; ++j){
            array[p] = matrix[layer_counter][j];
            ++p;
        }

        // get the elements from the last column of the layer
        for (int j = layer_counter+1; j < number_of_rows-layer_counter; ++j){
            array[p] = matrix[j][number_of_cols-1-layer_counter];
            ++p;
        }

        // get the elements from last row of the layer
        for (int j = number_of_cols-2-layer_counter; j >= layer_counter; j--){
            array[p] = matrix[number_of_rows-1-layer_counter][j];
            ++p;
        }

        // get the elements from the first column of the layer
        for (int j = number_of_rows-2-layer_counter; j > layer_counter; j--){
            array[p] = matrix[j][layer_counter];
            ++p;
        }

        int position = r % p; // position calculated by using the modulo operator

        // starting changing values if the position is greater than zero
        if (position > 0){
            // change the elements in the top row of layer
            for (int j = layer_counter; j < number_of_cols-layer_counter; ++j){
                matrix[layer_counter][j] = array[position];
                position = (position+1) % p; // get next position using modulo 
            }

            // change the elements in the last column of layer
            for (int j = layer_counter+1; j < number_of_rows-layer_counter; ++j){
                matrix[j][number_of_cols-1-layer_counter] = array[position];
                position = (position+1) % p; // get next position using modulo
            }

            // change the elements in the botton row of layer
            for (int j = number_of_cols-2-layer_counter; j >= layer_counter; j--){
                matrix[number_of_rows-1-layer_counter][j] = array[position];
                position = (position+1) % p; // get next position using modulo
            }

            // change the elements in the first column of layer
            for (int j = number_of_rows-2-layer_counter; j > layer_counter; j--){
                matrix[j][layer_counter] = array[position];
                position = (position+1) % p; // get next position using modulo
            }
        }
    }

    // print the element in the rotated matrix
    for (int i = 0; i < number_of_rows; ++i){
        for (int j = 0; j < number_of_cols; ++j){
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
}