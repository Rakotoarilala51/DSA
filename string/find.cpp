#include<iostream>
using namespace std;
int main(){
    string s="ainarakotoarainalalaarielaina";
    string pattern;
    getline(cin, pattern);
    int index=s.find(pattern);
    while(index!=-1){
        cout<<index<<endl;
        index=s.find(pattern, index+1);    
    }
    
    
}