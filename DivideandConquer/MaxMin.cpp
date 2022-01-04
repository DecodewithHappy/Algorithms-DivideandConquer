#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int MaxMin(int, int, int* , int*);

int a[50], n;

int main(){
    int i, Max, Min;
    cout << "Enter the total number of elements: " << " \n";
    cin >> n;
    cout << "Enter array elements: " << " \n";
    for(i=1; i<=n; i++)
    {
        cin >> a[i];
    }
    MaxMin(1, n, &Max, &Min);
    cout << "Maximum Value is : " << Max << "\n";
    cout << "Minimum Value is : " << Min << "\n";
    return 0;
}

int MaxMin(int i, int j, int* Max, int* Min){

    int mid, Max1, Min1;
    if(i == j){
        (*Max) = (*Min) = a[i];
    }
    else if(i == (j-1)){
        if(a[i] < a[j]){
            (*Max) = a[j];
            (*Min) = a[i];
        }else{
            (*Max) = a[i];
            (*Min) = a[j];
        }
    }else{
        mid = ceil((i + j) /2);
        //cout << "Mid Value is : " << mid << "\n";
        MaxMin(1, mid, Max, Min);
        //cout << "Maximum Value after func call is : " << (*Max) << "\n";
        //cout << "Minimum Value after func call is : " << (*Min) << "\n";
        MaxMin(mid+1, j, &Max1, &Min1);
        //cout << "Maximum Value after func call is : " << Max1 << "\n";
        //cout << "Minimum Value after func call is : " << Min1 << "\n";
        if(*Max < Max1){
            *Max = Max1;
        }
        if(*Min > Min1){
            *Min = Min1;
        }
    }
    //cout << "Maximum Value is : " << *Max << "\n";
    //cout << "Minimum Value is : " << *Min << "\n";
    return 0;
}
