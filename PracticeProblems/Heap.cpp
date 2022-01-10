#include <iostream>
using namespace std;

#define MAX 100

int main(){
    int insert(int [MAX], int *, int);
    void display(int [MAX], int);
    int ch, arr[MAX], n, value, result;
    n = 0;
    while(1){
        cout << "\n\t\tMENU\t\t\t\n";
        cout << "1.Insert Elements\t2.Display Elements\n";
        cout << "3.Build Heap\t\t4.Heap Sort\n";
        cout << "5.Exit\n\n";
        cout << "Enter any value from the menu : ";
        cin >> ch;

        switch(ch){
            case 1:
                 cout << "\nEnter the value : ";
                 cin >> value;
                 result = insert(arr, &n, value);
                 if(result == -1){
                     cout << "\nArray is Full!!\n";
                 }else{
                     cout << "\nInsertion Successful\n";
                 }
                 break;
            case 2:
                 display(arr, n);
                 break;
            case 3:
                 break;
            case 4:
                 break;
            case 5:
                 return 0;
                 break;
            default: 
                 break;
        }
    }
}

int insert(int arr[MAX], int (*n), int value){
    if((*n) == MAX){
        return -1;
    }
    arr[(*n)] = value;
    (*n) = (*n) + 1;
    return 1;
}

void display(int arr[MAX], int n){
    int i;
    if(n == 0){
        cout << "\nArray is empty!!\n";
        return;
    }
    for(i=0; i<n; i++){
       cout << arr[i] << " ";
    }
    cout << endl;
}