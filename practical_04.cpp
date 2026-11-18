#include <iostream>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace chrono;
/*
    Iterative Factorial

    Time Complexity:
    Best Case    : O(n)
    Average Case : O(n)
    Worst Case   : O(n)

    Space Complexity:
    O(1)
*/
long long iterativeFactorial(int n)
{
    int i;
    long long fact = 1;

    for(i = 1; i <= n; i++)
    {
        fact = fact * i;
    }

    return fact;
}
/*
    Recursive Factorial

    Time Complexity:
    Best Case    : O(n)
    Average Case : O(n)
    Worst Case   : O(n)

    Space Complexity:
    O(n)

    Note:
    Recursive method uses function call stack.
*/
long long recursiveFactorial(int n)
{
    if(n == 0 || n == 1)
        return 1;

    return n * recursiveFactorial(n - 1);
}

// Main Function
int main()
{
    int n, ch;
    long long Ians;
    long long Rans;
    cout << "Enter a number: ";
    cin >> n;

    auto Istart = high_resolution_clock::now();
        Ians = iterativeFactorial(n);
    auto Istop = high_resolution_clock::now();

    auto Rstart = high_resolution_clock::now();
        Rans = recursiveFactorial(n);
    auto Rstop = high_resolution_clock::now();
        cout << "\nFactorial = " << Ians<<"\n";
    
    double ItimeTaken = duration<double, micro>(Istop - Istart).count();
    double RtimeTaken = duration<double, micro>(Rstop - Rstart).count();
    cout << fixed << setprecision(6);
    cout << "Time Taken: " << ItimeTaken << " microseconds\n";
    cout << "Time Taken: " << RtimeTaken << " microseconds\n";
    return 0;
}
