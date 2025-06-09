#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>& nums1, vector<int>& nums2){
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int sum=0;
    for(int i=0; i<nums1.size(); i++){
        sum+=abs(nums1[i]-nums2[i]);
    }
    return sum;
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string input;
    vector<int> nums1;
    vector<int> nums2;
    while (getline(cin, input))
    {
       stringstream ss(input);
       int a, b;
       while (ss>>a>>b)
       {
            nums1.push_back(a);
            nums2.push_back(b);
       }
       
    }
    cout<<solve(nums1, nums2);
    
}