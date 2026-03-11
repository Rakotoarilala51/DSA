#include <bits/stdc++.h>
using namespace std;
void solve(int n)
{
    if (n==3 or n==2){
        cout << "NO SOLUTION" << endl;
        return;
    }
        for (int i = 1; i <= n; i++){
        if (!(i & 1)) {
            cout << i << " ";
        }
    }
    for (int i = 1; i <= n; i++){
        if (i & 1){
            cout << i << " ";
        }
    }

    cout<<endl;
}
int main()
{
    int n;
    cin >> n;
    solve(n);
}