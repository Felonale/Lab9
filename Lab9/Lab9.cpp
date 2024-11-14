#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int fillarray(int* array, int arraysize) {
    srand(time(NULL));
    for (size_t i = 0; i < arraysize; i++){
        array[i] = rand() % 99 + 1;
        printf("%d\t",array[i]);
    }
    cout << endl;
    return 0;
}

int printarray(int* array, int arraysize) {
    for (size_t i = 0; i < arraysize; i++) {
        printf("%d\t", array[i]);
    }
    cout << endl;
    return 0;
}

int main(){
    int arraysize = 8;

    cout << "Set array size: ";
    cin >> arraysize;

    int *array = new int[arraysize];

    fillarray(array, arraysize);
    printarray(array, arraysize);

    int index, shift;

    cout << "How much do you want to shift array to the left: ";
    cin >> shift;
    shift = shift % arraysize;

    int* temparray = new int[arraysize];

    for (size_t i = 0; i < arraysize; i++){
        index = i - shift;
        if (index < 0){
            index = arraysize + index;
            temparray[index] = array[i];
        }else{
            temparray[index] = array[i];
        }
    }
    delete[] array;
    array = temparray;

    printarray(array, arraysize);

    delete [] array;
    return 0;
}