#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size()==1) return 1?citations[0]>0:0;
        sort(citations.begin(), citations.end());
        int n=citations.size();
        int hindex=0;
        for(int i=0; i<n; i++){
            if((n-i)>=citations[i]){
                 hindex=max(hindex, citations[i]);
            }else{
                hindex=max(hindex, n-i);
            }
        }
        return hindex;
    }
};
int main(){
    vector<int> nums={0,0,2};
    Solution solution;
    cout<<solution.hIndex(nums);
}