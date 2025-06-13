#include <bits/stdc++.h>
using namespace std;
#define int long long
int concat(int cur, int nums){
    string a= to_string(cur);
    string b=to_string(nums);
    return stoll(a+b);
}
bool backtrack(int i, int goal, vector<int>& nums, int cur){
    if(i==nums.size()){
        return cur==goal;
    }
    bool ans=0;
    ans=ans||backtrack(i+1, goal, nums, cur+nums[i]);
    if(i>=1){
        ans=ans||backtrack(i+1, goal, nums, cur*nums[i]);
    }
    ans = ans || backtrack(i+1, goal, nums, concat(cur, nums[i]));
    return ans;
}
int32_t main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string line;
    int sum=0;
    while (getline(cin, line))
    {
        int goal;
        vector<int> nums;
        vector<string> input;
        stringstream ss(line);
        string token;
        while (getline(ss, token, ':'))
        {
            input.push_back(token);
        }
        goal = stoll(input[0]);
        stringstream sss(input[1]);
        int a;
        while (sss >> a)
        {
            nums.push_back(a);
        }
        if(backtrack(0,goal, nums, 0)) sum+=goal;
    }
     cout<<sum<<endl;
}