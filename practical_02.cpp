#include <iostream>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace chrono;
#define MAX 100

/*
    Binary Search

    Note:
    Array must be sorted in ascending order.

    Time Complexity:
    Best Case    : O(1)
    Average Case : O(log n)
    Worst Case   : O(log n)

    Space Complexity:
    O(1)
*/
int binarySearch(int a[], int n, int key)
{
    int low = 0, high = n - 1, mid;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(a[mid] == key)
            return mid;

        else if(a[mid] < key)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}
/*
    Linear Search

    Time Complexity:
    Best Case    : O(1)
    Average Case : O(n)
    Worst Case   : O(n)

    Space Complexity:
    O(1)
*/
int linearSearch(int a[], int n, int key)
{
    int i;

    for(i = 0; i < n; i++)
    {
        if(a[i] == key)
            return i;
    }

    return -1;
}
//main function
int main()
{
    int a[MAX], n, i, key, Lpos, Bpos;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n(sorted for usage of binary search)\n";
    for(i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter element to search: ";
    cin >> key;

    auto Lstart = high_resolution_clock::now();
       Lpos = linearSearch(a, n, key);
    auto Lstop = high_resolution_clock::now();

    auto Bstart = high_resolution_clock::now();
       Bpos = binarySearch(a, n, key);
    auto Bstop = high_resolution_clock::now();
    
    double LtimeTaken = duration<double, micro>(Lstop - Lstart).count();
    double BtimeTaken = duration<double, micro>(Bstop - Bstart).count();
    
    if(Lpos && Bpos == -1)
        cout << "\nElement Not Found.\n";
    else
        cout << "\nElement Found at Position " << Lpos + 1<<"\n";

    cout << fixed << setprecision(6);
    cout << "Time Taken By Linear Search: " << LtimeTaken << " microseconds\n";
    cout << "Time Taken By Binary Search: " << BtimeTaken << " microseconds\n";
    return 0;
}
