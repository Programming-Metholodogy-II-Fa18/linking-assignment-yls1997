#include <iostream>
#include <iomanip>
using namespace std;

void Problem4A(int array[], int arraySize){
    int hold;
    for (int i =0; i<arraySize-1; i++)
    {
        for(int j = 0 ; j < arraySize-1; j++)
        {
            if (array[j]>array[j+1])
            {   hold=array[j+1];
                array[j+1]=array[j];
                array[j]=hold;
            }
        }
    }
}

void print(int array[], int arraySize) {
    for (int a = 0; a < arraySize; a++) {
        cout << array[a] <<"  ";
    }
}

int main() {
    int arraySize;
    cout << "enter array size: ";
    cin >> arraySize;
    int h = arraySize;
    int array[h] = {0};
    for (int i = 0; i < arraySize; i++) {
        cout << "enter " << i + 1 << " number:";
        cin >> array[i];
    }
    Problem4A(array, arraySize);
    print(array, arraySize);
    return 0;
}