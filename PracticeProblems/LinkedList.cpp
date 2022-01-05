#include <iostream>
using namespace std;

typedef struct Node{
    int data;
    struct Node *next;
}Node;

int main(){
    void prepend(Node**, int);
    void displayList(Node *);
    Node* start = NULL;
    int ch, value;
    while(1){
        cout << "\n\n1:Prepend\t\t2:Append\t\t3:After a value\n";

        cout << "4:Display\t\t5:Search\t\t6:Delete\n";

        cout << "7:Exit\n\n";
        cout << "Enter any value from the above menu : ";
        cin >> ch;
        switch(ch){
            case 1:
                  cout<<"\nEnter data to prepend in the list\n";
                  cin >> value;
                  prepend(&start, value);
                  break;
            case 2:
                  break;
            case 3:
                  break;
            case 4:
                  displayList(start);
                  break;
            case 5:
                  break;
            case 7: 
                  return 0;
            default: cout << "\nWrong Input\n";
        }
    }
}

void prepend(Node** start, int value){
    Node* newnode = new Node; //create and allocate new node

    newnode->data = value;
    newnode->next = (*start);

    (*start) = newnode;

}

void displayList(Node *node){
    cout << "\n\n";
    while(node != NULL){
        cout << node->data << "--->";
        node = node->next;
    }
    if(node == NULL){
        cout << "NULL\n\n";
    }
}