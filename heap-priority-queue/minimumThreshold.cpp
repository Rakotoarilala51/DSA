#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution{
    public:
        int minOperations(vector<int>& nums, int k){
            priority_queue<int, vector<int>, greater<int>> minHeap;
            int count=0;
            for(int num: nums){
                minHeap.push(num);
            }
            while(minHeap.size()>1 & minHeap.top()<k){
                const int x=minHeap.top();
                minHeap.pop();
                const int y=minHeap.top();
                minHeap.pop();
                minHeap.push(min(x,y)*2+max(y,x));
                count++;
            }
            return count;
        }
};
int main(){
    Solution solution;
    vector<int> nums={1,1,2,4,9};
    int k=10;
    cout<<solution.minOperations(nums, k);
    
}