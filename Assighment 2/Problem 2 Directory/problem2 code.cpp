#include <iostream>
using namespace std;


void mergeSort(int array[], int arraySize){
    int fronthalf;
    int backhalf;
    if(arraySize % 2 == 0){
        fronthalf = arraySize/2;
        backhalf = arraySize/2;
    }else {
        fronthalf = arraySize/2 + 1;
        backhalf =arraySize/2;
    }

    int array1[fronthalf];
    int array2[backhalf];
    for(int i=0; i < fronthalf; i++){
        array1[i] = array[i];
    }
    for (int i = fronthalf; i < arraySize; i++){
        array2[i] =array[i];
    }

    int min1;
    int Index1;
    for(int i = 0; i < fronthalf; i++){
        min1 = array1[i];
        for (int j = i+1; j < fronthalf; j++){
            if(array1[j] < min1){
                min1 = array1[j];
                Index1 = j;
            }
        }
        array[Index1] = array[i];
        array[i] = min1;
    }

    int min2;
    int Index2;
    for(int i = fronthalf; i<backhalf; i++){
        min2 = array2[i];
        for (int j = i+1; j < fronthalf; j++){
            if(array2[j] < min2){
                min2 = array2[j];
                Index2 = j;
            }
        }
        array[Index2] = array[i];
        array[i] = min2;
    }

    int i1 = 0;
    int i2 = 0;
    for (int i=0; i < arraySize; i++){
        if (array1[i1] <= array2[i2] && i1<fronthalf){
            array[i] = array1[i1];
            i1++;
        }else if (i2<backhalf){
            array[i] = array2[i2];
            i2++;
        }
    }
}


void print(int array[], int arraySize) {
    for (int a = 0; a < arraySize; a++) {
        cout << array[a] <<endl;
    }
}

int main() {
    int arraySize;
    cout << "enter array size: ";
    cin >> arraySize;
    int h;
    h = arraySize;
    int array[h] = {0};
    for (int i = 0; i < arraySize; i++) {
        cout << "enter " << i + 1 << " number:";
        cin >> array[i];
    }
    mergeSort(array, arraySize);
    print(array, arraySize);
    return 0;
}

