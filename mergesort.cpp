#include <iostream>
#include <string>
using namespace std;

int Min(int, int);
void merge_sort_iter(int [], int, int);
void merge(int [], int, int, int);

int main(){
    int a[50], n, i;
    cout << "Enter the total number of elements: " << " \n";
    cin >> n;
    cout << "Enter array elements: " << " \n";
    for(i=0;i<n;i++)
    {
        cin >> a[i];
    }
    merge_sort_iter(a, 0, n-1);
    cout << "\n" << "After Sorting : "; 
    for(i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << "\n";
    return 0;
}

int Min(int x, int y){
    if(x < y){
        return x;
    }else{
        return y;
    }
}

void merge_sort_iter(int a[50], int low, int high){
    int i, j, mid, start, end;
    i = 1;
    
    while(i <= (high - low)){
        j = low;
      
        while(j < high){
            start = j;
            mid = j + i - 1;
            end = Min(j + 2*i - 1, high);
            
            merge(a, start, mid, end);
            j = j + 2*i;
            
        }
        i = 2*i;
        
    }
}

void merge(int a[50], int lb, int m, int ub){
    int i, j, k, n1, n2;
    n1 = m - lb + 1;
    n2 = ub - m;

    int LA[n1], RA[n2];

    i = 0;
    while(i < n1){
        LA[i] = a[lb + i];
        i = i+1;
    }
    j = 0;
    while(j < n2){
        RA[j] = a[m + 1 + j];
        j = j+1;
    }

    i = 0, j = 0, k = lb;
    while((i < n1) && (j < n2)){
        if(LA[i] <= RA[j]){
            a[k++] = LA[i++];
        
        }else{
            a[k++] = RA[j++];
        }
    }

    while(i < n1){
        a[k++] = LA[i++];
    }

    while ((j < n2)){
        a[k++] = RA[j++];
    }

}