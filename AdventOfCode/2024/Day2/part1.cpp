#include<bits/stdc++.h>
using namespace std;
bool safe(vector<int>& nums){
    bool croissant=is_sorted(nums.begin(), nums.end());
    bool decroissant=is_sorted(nums.begin(), nums.end(), greater<int>());
    if(!(croissant || decroissant)) return false;
    for(int i=0; i<nums.size()-1; i++){
        if(abs(nums[i]-nums[i+1])<1 || abs(nums[i]-nums[i+1])>3) return false;
    }
    return true;
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string input;
    int sum=0;
    while(getline(cin, input)){
        stringstream ss(input);
        vector<int> nums;
        int a;
        while(ss>>a){
            nums.push_back(a);
        }
        sum+=safe(nums);
    }
    cout<<sum;
}