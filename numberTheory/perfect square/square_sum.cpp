#include<bits/stdc++.h>
using namespace std;
int square_sum(int n){
    unordered_set<int> perfectSquare;
    vector<int> square;
    for(int i=1; i*i<=n; i++){
        perfectSquare.insert(i*i);
        square.push_back(i*i);
    }
    if(perfectSquare.count(n)) return 1;
    for(int a: perfectSquare){
        if(perfectSquare.count(n-a)) return 2;
    }
    for(size_t i=0; i<square.size(); i++){
        for(size_t j=i; j<square.size(); j++){
            int sum=square[i]+square[j];
            int rem=n-square[i]-square[j];
            if(rem<0) continue;
            if(perfectSquare.count(rem)) return 3;
        }
    }
    return 4;
}
int sum_of_squares(int n) {
    int sq = sqrt(n);
    if (sq * sq == n) return 1;

    for (int i = 1; i * i <= n; ++i) {
        int rem = n - i*i;
        int s = sqrt(rem);
        if (s * s == rem) return 2;
    }

    for (int i = 0; i * i <= n; ++i) {
        for (int j = i; i*i + j*j <= n; ++j) {
            int rem = n - i*i - j*j;
            int s = sqrt(rem);
            if (s * s == rem) return 3;
        }
    }

    return 4;
}
