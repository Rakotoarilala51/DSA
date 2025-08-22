#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> result;
    vector<int> num;
    vector<vector<int>> threeSum(vector<int>& nums) {
        this->num = nums;
        sort(num.begin(), num.end());
        for(int i = 0; i<num.size(); i++){
            if(i>0 && (num[i]==num[i-1])) continue;
            int left=i+1, right = num.size()-1;
            while(left<right){
                int sum = num[right]+num[left];
                if(sum==-num[i]){
                    vector<int> subresult({num[i], num[left], num[right]});
                    result.push_back(subresult);
                    left++;
                    right--;
                    while(left<right && num[left]==num[left-1]){
                        left++;
                    }
                    while(left<right && num[right]==num[right+1]){
                        right--;
                    }
                }
                else if(sum>-num[i]){
                    right--;
                }
                else{
                    left++;
                }
            }
        }
        return result;
    }
 

};
int main(){
    vector<vector<int>> result;
    vector<int> nums{2,-3,0,-2,-5,-5,-4,1,2,-2,2,0,2,-4,5,5,-10};
    Solution solution;
    result = solution.threeSum(nums);
    for(auto vec: result){
        for(int num: vec){
            cout<<num<<" ";
        }
        cout<<endl;
    }
}