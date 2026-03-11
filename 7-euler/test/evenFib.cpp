#include <bits/stdc++.h>
#define int long long
using namespace std;
int evenFibSum(int n)
{
    int a = 1;
    int b = 2;
    int result = 0;
    while (a <= n)
    {
        cout<<a<< " ";
        if (a%2==0)
        {
            result += a;
        }
        a = b;
        b = b + a;
    }
    return result;
}
int32_t main()
{
    cout << evenFibSum(10);
}