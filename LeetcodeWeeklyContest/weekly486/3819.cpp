#include<bits/stdc++.h>
using namespace std;
void print(vector<int> nums){
    cout<<"[";
    for(int num:nums){
        cout<<num<<",";
    }
    cout<<"]"<<endl;
}
vector<int> rotateElements(vector<int>& nums, int k) {
    vector<int>nonNegative;
    for(int num:nums){
        if(num>0)nonNegative.push_back(num);
    }
    int n=nonNegative.size();
    k%=n;
    reverse(nonNegative.begin(), nonNegative.end());
    reverse(nonNegative.end()-k,nonNegative.end());
    reverse(nonNegative.begin(), nonNegative.end()-k);

    int nonNegativeIndex=0;
    for(int i=0; i<nums.size(); i++){
        if(nums[i]>=0){
            nums[i]=nonNegative[nonNegativeIndex];
            nonNegativeIndex++;
        }
        if(nonNegativeIndex==n) break;
    }
    return nums;
}
int main(){
    vector<int> nums={1,-2,3,-4};
    vector<int> result=rotateElements(nums,3);
    print(result);
}