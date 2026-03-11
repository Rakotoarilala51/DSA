#include <bits/stdc++.h>
using namespace std;
int pivotInteger(int n)
{
    int sum = n * (n + 1) / 2;
    int sr=sqrt(sum);
    if (sr * sr == sum)
        return sr;
    else
        return -1;
}

int main(){
    cout<<pivotInteger(8);
}