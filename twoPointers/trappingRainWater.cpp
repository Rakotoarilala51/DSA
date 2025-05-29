#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
    int trap(vector<int>& height){
        int n=height.size();
        if(n<=2){
            return 0;
        }
        vector<int> left(n, 0);
        vector<int> right(n,0);
        left[0]=height[0];
        right[n-1]=height[n-1];
        for(int i=1; i<n; i++){
            left[i]=max(left[i-1], height[i]);
            right[n-i-1]=max(height[n-i-1], right[n-i]);
        }
        int water=0;
        for(int i=0; i<n; i++){
            water+=min(left[i], right[i])-height[i];
        }
        return water;
    }
};
int main(){
    vector<int> height={4,2,0,3,2,5};
    Solution solution;
    cout<<solution.trap(height);
}