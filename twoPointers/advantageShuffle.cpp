#include<iostream>
#include<set>
#include<vector>
using namespace std;
class Solution{
    public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2){
        multiset<int> s(nums1.begin(), nums1.end());
        for(int i=0; i<nums2.size(); i++){
            auto it=s.upper_bound(nums2[i]);
            if(it!=s.end()){
                nums1[i]=*it;
                s.erase(it);
            }
            else{
                nums1[i]=*s.begin();
                s.erase(s.begin());
            }
        }
        return nums1;
    }
};
int main(){
    Solution solution;
    vector<int> nums1={2,7,15,10};
    vector<int> nums2={1,10,4,11};
    vector<int> result = solution.advantageCount(nums1, nums2);
    for(auto x: result){
        cout<<x<<" ";
    }
}