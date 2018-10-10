#include<iostream>

using namespace std;


int maximum(int array[], int arraySize) {
    int max = 0;
    for (int i = 0; i < arraySize; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

/*void sort(int array[], int arraySize, int exp) {
    int output[arraySize];
    int bucket[10];
    for (int i = 0; i < 10; i++) {
        bucket[i] = 0;
    }
    for (int i = 0; i < arraySize; i++) {
        bucket[(array[i]%exp)]++;
    }
    for (int i = 0; i < 10; i++) {
        bucket[i] = bucket[i] + bucket[i - 1];
    }
    for  (int i = 0; i <arraySize; i++) {
        output[bucket[(array[i] / exp) % 10] + 1] = array[i];
    }
    for  (int i = 0; i <arraySize; i++) {
         bucket[(array[i] % exp) % 10]++;
     }
    for (int i = 0; i < arraySize; i++) {
        array[i] = output[i];
    }
}*/

void sort(int array[], int arraySize, int exp)
{
    int output[arraySize];
    int bucket[10] = {0};
    for (int i = 0; i < arraySize; i++)
        bucket[ (array[i]/exp)%10 ]++;
    for (int i = 0; i < 9; i++)
        bucket[i+1] = bucket[i] + bucket[i+1];
    for (int i = 0; i <arraySize; i++)
    {
        output[bucket[(array[i]/exp)%10]-1]=array[i];
        bucket[ (array[i]/exp)%10 ]--;
    }
    for (int i = 0; i < arraySize; i++)
        array[i] = output[i];
}

void Problem1Sort(int array[], int arraySize){
    int M = maximum(array, arraySize);
    for (int exp = 1; M/exp > 0; exp = exp*10)
        sort(array, arraySize, exp);
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
    Problem1Sort(array, arraySize);
    print(array, arraySize);
    return 0;
}
