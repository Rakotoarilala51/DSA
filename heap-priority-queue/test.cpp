#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    vector<int> nums{15,16,20,100,13,17,9,6};
    priority_queue<int, vector<int>, greater<int>> maxHeap;
    for(int num:nums){
        maxHeap.push(num);
    }
    while(!maxHeap.empty()){
        cout<<maxHeap.top()<<endl;
        maxHeap.pop();
    }
}