#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){
    vector<int> unsorted={10,4,15,78,52,5,4};
    priority_queue<int, vector<int>, greater<int>> heap;
    for(int num: unsorted){
        heap.push(num);
    }
    while(!heap.empty()){
        cout<<heap.top()<<endl;
        heap.pop();
    }

}