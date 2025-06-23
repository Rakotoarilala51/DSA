#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> nextGreater(vector<int>& nums){
    vector<int> result(nums.size());
    stack<int> st;
    for(int i=nums.size()-1; i>=0; i--){
        while(!st.empty() && st.top()<=nums[i]){
            st.pop();
        }
        if(st.empty()) result[i]=-1;
        else result[i]=st.top();
        st.push(nums[i]);
    }
    return result;
}
int main(){
    vector<int> nums={4,12,5,3,1,2,5,3,1,2,4,6};
    vector<int> result=nextGreater(nums);
    for(int num: result){
        cout<<num<<" ";
    }
}