#include <iostream>
#include <vector>

using namespace std;

bool backtrack(vector<int> &nums, int n) {
        for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
   if(n==0){
    return true;
   }
   for(int i=0; i+n<nums.size()+1;i++){
    if(nums[i]==-1 && (n==1||nums[i+n]==-1)){
        nums[i]=n;
        if(n!=1) nums[i+n]=n;
        if(backtrack(nums, n-1)){
            return true;
        }
        nums[i]=-1;
        if(n!=1) nums[i+n]=-1;
    }
   }
   return false;
}

vector<int> constructDistancedSequence(int n) {
    int size = 2 * n - 1;
    vector<int> nums(size, -1);

    backtrack(nums, n);

    return nums;
}

int main() {
    int n = 3;
    vector<int> result = constructDistancedSequence(n);

  
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
