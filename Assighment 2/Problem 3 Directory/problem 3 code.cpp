#include <iostream>
#include <stdio.h>

using namespace std;


struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void printlist(){

}




int main() {
    struct Node *a = NULL;
    push(&a, 5);
    push(&a, 20);
    push(&a, 4);
    push(&a, 3);
    push(&a, 30);

    printlist();


}
