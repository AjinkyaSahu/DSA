#include<bits/stdc++.h>
using namespace std;

// This function is going to find GCD

int gcd(int a, int b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);

}

int main()
{
    int a = 46, b = 20;
    cout << "GCD of " << a << " & " << b << " is " << gcd(a, b);
    return 0;
}