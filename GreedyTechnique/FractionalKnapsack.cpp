#include <iostream>
using namespace std;

typedef struct {
    float weight;
    float profit;
    float ratio;
}Object;

int main(){
    void input(Object [], int);
    void display(Object [], int);
    float knapsack(Object [], int, float);
    float Capacity, profit;
    int n;
    Object objects[10];
    cout << "Enter total no of objects : ";
    cin >> n;
    cout << "\n";
    input(objects, n);
    cout << "Enter data \n";
    display(objects, n);
    cout << "Enter Knapsack weight \n";
    cin >> Capacity;
    profit = knapsack(objects, n, Capacity);
    cout << " Max profit for " << Capacity << " weight is " << profit;
    return 0;
}

void input(Object objects[], int n){
    int i;
    cout << "Enter total "<< n <<" object's weight and profit" << endl;
    for(i = 0; i < n; i++){
        cout << "Enter " << i+1 << " Profit ";
        cin >> objects[i].profit;
        cout << "Enter " << i+1 << " Weight ";
        cin >> objects[i].weight;
    }
}

void display(Object objects[], int n){
    int i;
    cout << "Profit: ";
    for(i = 0; i < n; i++){
        cout << objects[i].profit << "\t";
    }
    
    cout << endl << "Weight: ";
    for(i = 0; i < n; i++){
        cout << objects[i].weight << "\t";
    }
    cout << endl;    
}

float knapsack(Object objects[], int n, float Capacity){
    void merge_sort(Object [], int, int);
    int i;
    float totalprofit = 0, totalweight=0, remainingweight;
    // calculate the profit/weight ratio of each objects
    for(i = 0; i < n; i++){
        objects[i].ratio = objects[i].profit / objects[i].weight;
    }

    cout << "\n" << "Before Sorting : "; 
    for(i = 0; i < n; i++){
        cout << objects[i].ratio << " ";
    }
    cout << "\n";

    merge_sort(objects, 0, n-1);

    cout << "\n" << "After Sorting : "; 
    for(i = 0; i < n; i++){
        cout << objects[i].ratio << " ";
    }
    cout << "\n";

    for(i = 0; i < n; i++){
        /*if((totalweight + objects[i].weight) <= Capacity){
            totalprofit += objects[i].profit;
            totalweight += objects[i].weight;
        }else{
            remainingweight = Capacity - totalweight;
            totalprofit += (remainingweight * objects[i].ratio);
            totalweight += remainingweight;
            break; 
        }*/

        if((Capacity > 0) && (objects[i].weight <= Capacity)){
            Capacity = Capacity - objects[i].weight;
            totalprofit = totalprofit + objects[i].profit;
        }else{
            break;
        }
    }
    if(Capacity > 0){
        totalprofit = totalprofit + objects[i].profit*(Capacity/objects[i].weight);
    }
    //cout << " total weight in bag " << totalweight << endl;
    return totalprofit;
}


int Min(int x, int y){
    if(x < y){
        return x;
    }else{
        return y;
    }
}

void merge_sort(Object a[10], int low, int high){
    void merge(Object [], int, int, int);
    int Min(int, int);
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

void merge(Object a[10], int lb, int m, int ub){
    int i, j, k, n1, n2;
    n1 = m - lb + 1;
    n2 = ub - m;

    float LA[n1], RA[n2];

    i = 0;
    while(i < n1){
        LA[i] = a[lb + i].ratio;
        i = i+1;
    }
    j = 0;
    while(j < n2){
        RA[j] = a[m + 1 + j].ratio;
        j = j+1;
    }

    i = 0, j = 0, k = lb;
    while((i < n1) && (j < n2)){
        if(LA[i] >= RA[j]){
            a[k++].ratio = LA[i++];
        
        }else{
            a[k++].ratio = RA[j++];
        }
    }

    while(i < n1){
        a[k++].ratio = LA[i++];
    }

    while ((j < n2)){
        a[k++].ratio = RA[j++];
    }

}