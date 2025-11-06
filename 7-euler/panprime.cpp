#include<bits/stdc++.h>
using namespace std;
void permute(int i,vector<int> nums, vector<vector<int>>& result){
    if(i==nums.size()){
        result.push_back(nums);
    }
    for(int j=i; j<nums.size(); j++){
        swap(nums[i], nums[j]);
        permute(i+1, nums, result);
        swap(nums[i], nums[j]);
    }
}
int main(){
    vector<int> digits= {7,6,5,4,3,2,1};
    vector<vector<int>> permutations;
    permute(0, digits, permutations);
    cout<<permutations.size();
}