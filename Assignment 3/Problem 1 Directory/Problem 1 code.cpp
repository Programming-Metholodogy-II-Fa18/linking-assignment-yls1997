#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class DaryHeap
{
private:
    int d;
    int heapSize;
    int size;
    int *heap;
public:
    DaryHeap(int size, int childrenNum)
    {
        heapSize = 0;
        d = childrenNum;
        heap = new int[10];
        for (int i = 0 ; i < 10; i++)
            heap[i] = -1;
        int j = 0;
        while (heap[j] != -1)
            j++;
        heapSize = j;
        this->heap = heap;
        this->d = childrenNum;
        buildHeap();
    }
    void insert(int k){
        if(isFull()){
            doubleArray();
        }
        heap[heapSize] = k;
        heapSize++;
        swim(heapSize-1);
    }
    }
}
    bool isEmpty()
    {
        return heapSize == 0;
    }

    bool isFull()
    {
        return heapSize == size;
    }

    void makeEmpty( )
    {
        heapSize = 0;
    }

    int parent(int i)
    {
        return (i - 1) / d;
    }

    int kthChild(int i, int k)
    {
        return d * i + k;
    }

    void insert(int x)
    {
        if (isFull())
        {
            cout<<"Array Out of Bounds"<<endl;
            return;
        }
        int hole = heapSize;
        heapSize++;
        heap[hole] = x;
        percolateUp(hole);
    }

    int findMin()
    {
        if (isEmpty())
        {
            cout<<"Array Underflow"<<endl;
            return 0;
        }
        return heap[0];
    }
    /*
     * Function to delete element at an index
     */
    int Delete(int hole)
    {
        if (isEmpty())
        {
            cout<<"Array Underflow"<<endl;
            return 0;
        }
        int keyItem = heap[hole];
        heap[hole] = heap[heapSize - 1];
        heapSize--;
        percolateDown( hole );
        return keyItem;
    }

    void buildHeap()
    {
        for (int i = heapSize - 1 ; i >= 0; i--)
            percolateDown(i);
    }

    /*
     * Function percolateDown
     */
    void percolateDown(int hole)
    {
        int child;
        int tmp = heap[hole];
        for ( ; kthChild(hole, 1) < heapSize; hole = child)
        {
            child = smallestChild( hole );
            if (heap[child] < tmp)
                heap[hole] = heap[child];
            else
                break;
        }
        heap[hole] = tmp;
    }

    int smallestChild(int hole)
    {
        int bestChildYet = kthChild(hole, 1);
        int k = 2;
        int candidateChild = kthChild(hole, k);
        while ((k <= d) && (candidateChild < heapSize))
        {
            if (heap[candidateChild] < heap[bestChildYet])
                bestChildYet = candidateChild;
            k++;
            candidateChild = kthChild(hole, k);
        }
        return bestChildYet;
    }


    void percolateUp(int hole)
    {
        int tmp = heap[hole];
        for (; hole > 0 && tmp < heap[parent(hole)]; hole = parent(hole))
            heap[hole] = heap[ parent(hole) ];
        heap[hole] = tmp;
    }


    void printHeap()
    {
        cout<<"\nHeap = ";
        for (int i = 0; i < heapSize; i++)
            cout<<heap[i]<<"   ";
        cout<<endl;
    }
};

int main()
{
