#include<iostream>
#include<cstring>
using namespace std;
void overlay(char something[], int x){
    int j=0;
    while(x>0){
        int last_bits=x&1;
        if(last_bits){
            cout<<something[j];
        }
        j++;
        x=x>>1;
    }
    cout<<endl;
}
void subset(char something[]){
    int n=strlen(something);
    for(int i=0; i<(1<<n); i++){
        overlay(something, i);
    }
}
int main(){
    char c[100];
    cin>>c;
    subset(c);
}