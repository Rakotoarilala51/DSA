#include<bits/stdc++.h>
using namespace std;
void print(vector<int> nums){
    cout<<"[";
    for(int num:nums){
        cout<<num<<",";
    }
    cout<<"]"<<endl;
}
void rotateArray(vector<int> nums, int k){
    int n=nums.size();
    k%n;
    reverse(nums.begin(), nums.end());
    print(nums);
    reverse(nums.end()-k, nums.end());
    print(nums);
    reverse(nums.begin(), nums.end()-k);
    print(nums);
}
int main(){
    vector<int> nums={5,4,6};
    rotateArray(nums,2);
}