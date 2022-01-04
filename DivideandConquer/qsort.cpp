#include <iostream>
#include <string>
using namespace std;

int Q_Sort(int [], int, int);
int Partition(int [], int, int);

int main(){
    int a[50], i, n;
    cout << "Enter the total number of elements: " << " \n";
    cin >> n;
    cout << "Enter array elements: " << " \n";
    for(i=0;i<n;i++)
    {
        cin >> a[i];
    }
    Q_Sort(a, 0, n-1);
    cout << "\n" << "After Sorting : "; 
    for(i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << "\n";
    return 0;
}

int Q_Sort(int a[50], int p, int r){
    if(p<r){
        int q = Partition(a, p, r);
        Q_Sort(a, p, q-1);
        Q_Sort(a, q+1, r);
    }
}

int Partition(int a[50], int p, int r){
    int x, i, j, temp;
    x = a[r];
    i = (p-1);
    for(j=p; j<=r-1; j++){
        if(a[j] <= x){
            i = i+1;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[r];
    a[r] = a[i+1];
    a[i+1] = temp;
    return i+1; 
}