#include <iostream>
#include <string>
using namespace std;

int BinarySearchRecur(int[], int, int, int);

int main()
{
    int a[50], n, x, loc, i;
    cout << "Enter the total number of elements: " << "\n";
    cin >> n;
    cout << "Enter array elements: " << "\n";
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter the element to search: " << "\n";
    cin >> x;
    loc = BinarySearchRecur(a, 0, n-1, x);
    if (loc != -1)
    {
        cout << "Element : " << x << " Found at location : " << loc+1 << "\n";
    }
    else
    {
        cout << "Element : " << x << " Not Found" << "\n";
    }
}

int BinarySearchRecur(int a[50], int l, int u, int x)
{
    int j, mid;
    if (l == u)
    {
        if (x == a[u])
        {
            return u;
        }
        else
        {
            return -1;
        }
    }
    else if (l > u)
    {
        return -1;
    }
    else
    {
        mid = (l + u) / 2;
        //cout << "value of mid inside the func : " << mid << "\n";
        if (a[mid] == x)
        {
            return mid;
        }
        else if (x < a[mid])
        {
            return BinarySearchRecur(a, l, mid - 1, x);
        }
        else if (x > a[mid])
        {
            return BinarySearchRecur(a, mid + 1, u, x);
        }
    }
    return -1;
}