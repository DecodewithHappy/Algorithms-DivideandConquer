#include <iostream>
using namespace std;

typedef struct Node{
    int data;
    struct Node *next;
}Node;

int main(){
    void prepend(Node**, int);
    void displayList(Node *);
    void append(Node**, int);
    int insert_before_value(Node **, int, int, int *);
    int Search(Node **, int, int *);
    Node* start = NULL;
    int ch, value, Svalue, loc;
    while(1){
        cout << "\n\t\t\tMENU\t\t\t\n";

        cout << "1:Prepend\t\t2:Append\t\t3:Before a value\n";

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
                  cout<<"\nEnter data to append in the list\n";
                  cin >> value;
                  append(&start, value);
                  break;
            case 3:
                  cout << "\nEnter data to insert in the list\n";
                  cin >> value;
                  cout << "\nEnter data before which you like to insert value\n";
                  cin >> Svalue;
                  insert_before_value(&start, Svalue, value, &loc);
                  if(loc == (-1)){
                      cout << "\nValue is not present\n";
                  }
                  break;
            case 4:
                  displayList(start);
                  break;
            case 5:
                  cout<<"\nEnter data to search\n";
                  cin >> Svalue;
                  Search(&start, Svalue, &loc);
                  if(loc != (-1)){
                      cout << "\nValue found at location :" << loc;
                  }else{
                      cout << "\nValue not found\n";
                  }
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

void append(Node** start, int value){
    Node* newnode = new Node; 
    Node* lastnode = (*start);
    newnode->data = value;
    newnode->next = NULL;

    if((*start) == NULL){
        (*start) = newnode;
        return;
    }
    while((lastnode->next) != NULL){
        lastnode = lastnode->next;
    }

    lastnode->next = newnode;
    return;
}

int insert_before_value(Node **start, int Svalue, int value, int *loc){
    (*loc) = 1;
    Node *newnode = new Node;
    Node *ptr = (*start);
    Node *prev = ptr;
    newnode->data = value;

    if((*start) == NULL){
        (*start) = newnode;
        return (*loc);
    }

    while(ptr != NULL){
        if(ptr->data == Svalue){
            newnode->next = ptr;
            prev->next = newnode;
            return (*loc);
        }
        (*loc) = (*loc) + 1;
        prev = ptr;
        ptr = ptr->next;
    }
    (*loc) = -1;
    return (*loc);
}

int Search(Node **start, int Svalue, int (*loc)){
    Node *ptr = (*start);
    (*loc) = 1;

    while(ptr != NULL){
        if(ptr->data == Svalue){
            return (*loc);
        }
        (*loc) = (*loc) + 1;
        ptr = ptr->next;
    }
    (*loc) = -1;
    return (*loc);
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

