#include<iostream>
#include<algorithm>
using namespace std;
int charToDigit(char c){
    return c-'0';
}
char digitTochar(int d){
    return d+ '0';
}
string add(string a, string b){
    if(a.length()>b.length()){
        swap(a,b);
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int carry=0;
    string result="";
    for(int i=0; i<a.length(); i++){
        int sum=carry+charToDigit(a[i])+charToDigit(b[i]);
        int output_sum=sum%10;
        carry+=sum/10;
        result.push_back(digitTochar(output_sum));
    }
    for(int i=a.length(); i<b.length(); i++){
        int sum=carry+charToDigit(b[i]);
        int output_sum=sum%10;
        carry+=sum/10;
        result.push_back(digitTochar(output_sum));
    }
    if(carry){
        result.push_back('1');
    }
    reverse(result.begin(), result.end());
    return result;
}
int main(){
    string a,b;
    cin>>a>>b;
    cout<<add(a, b)<<endl;

    return 0;
}