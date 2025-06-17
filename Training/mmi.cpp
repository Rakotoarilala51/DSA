 #include<iostream>
 #include<vector>
 using namespace std;
 vector<int> extendedGcd(int a, int m){
    if(m==0) return {1,0,a};
    vector<int> result=extendedGcd(m, a%m);
    int smallx=result[0];
    int smally=result[1];
    int gcd=result[2];

    int x=smally;
    int y=smallx-(a/m)*smally;
    return {x,y,gcd};
 }
 int mmi(int a, int m){
    vector<int> result = extendedGcd(a,m);
    int x= result[0];
    int gcd=result[2];

    if(gcd!=1) return -1;
    int ans=(x%m+m)%m;
    return ans;
 }
 int main(){
    cout<<mmi(10,12);
 }