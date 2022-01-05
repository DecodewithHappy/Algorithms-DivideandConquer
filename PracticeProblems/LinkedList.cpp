#include <iostream>
using namespace std;

typedef struct Node{
    int data;
    struct node* next;
}Node;

int main(){
    Node * start = NULL;
    int ch;
    while(1){
        cout << "1:Prepend\t\t2:Append\t\t3:After a value\n";

        cout<<"4:Display\t\t5:Search\t\t6:Delete\n";
        cin >> ch;
        switch(ch){
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            default: cout << "Wrong Input";
        }
        
    }
}