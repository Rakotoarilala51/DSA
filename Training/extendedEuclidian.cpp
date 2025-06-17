#include<bits/stdc++.h>
using namespace std;
vector<int> extendedEuclidian(int a, int b){
    if(b==0) return {1,0, a};
    vector<int> result=extendedEuclidian(b, a%b);
    int smallx=result[0];
    int smally=result[1];
    int gcd=result[2];
    
    int x=smally;
    int y=smallx-(a/b)*smally;
    return {x, y, gcd};
}
int main(){

}