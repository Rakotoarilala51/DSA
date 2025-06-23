#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include<sstream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    freopen("input.txt", "r", stdin);
    int t;
    string input;
    getline(cin, input);
    t=stoi(input);
    vector<int> stv;
    stack<int> sts;
    while(t--){
        string line;
        getline(cin, line);
        stringstream ss(line);
        string struc;
        int som;
        ss>>struc>>som;
        if(struc=="PUSH"){
            sts.push(som);
        }
        else if(struc=="POP"){
            if(sts.empty()){
                cout<<"Error"<<endl;
                break;
            } 
            sts.pop();
        }else if(struc=="ADD"){
            if(sts.size()<2){
                cout<<"Error"<<endl;
                break;
            }
            int a=sts.top();
            sts.pop();
            int b=sts.top();
            sts.pop();
            sts.push(a+b);
        }else if(struc=="SUB"){
            if(sts.size()<2){
                cout<<"Error"<<endl;
                break;
            }
            int a=sts.top();
            sts.pop();
            int b=sts.top();
            sts.pop();
            sts.push(b-a);
        }
        else if(struc=="PRINT"){
            if(sts.empty()){
                cout<<"Error"<<endl;
                break;
            }
            cout<<sts.top()<<endl;
        }
    }
    return 0;
}
