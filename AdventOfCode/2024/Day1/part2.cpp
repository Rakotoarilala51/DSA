#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>& nums, unordered_map<int, int> frequency){
    int sum=0;
    for(int num: nums){
        sum+=(num*frequency[num]);
    }
    return sum;
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string input;
    vector<int> nums;
    unordered_map<int, int> frequency;
    while(getline(cin, input)){
        stringstream ss(input);
        int a,b;
        while(ss>>a>>b){
            nums.push_back(a);
            frequency[b]++;
        }
    }
    cout<<solve(nums, frequency);
}