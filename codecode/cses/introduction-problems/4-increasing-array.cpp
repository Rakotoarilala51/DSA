#include<bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    vector<int> nums;
    while(t--){
        int a;
        cin>>a;
        nums.push_back(a);
    }
    int sum=0;
    for(int i=1; i<long(nums.size());i++){
        if(nums[i]<nums[i-1]){ 
            int diff=nums[i-1]-nums[i];
            sum+=diff;
            nums[i]=nums[i-1];
        }
    }
    cout<<sum<<endl;
}