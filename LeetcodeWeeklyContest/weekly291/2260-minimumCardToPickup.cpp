#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int left=0;
        int ans=INT32_MAX;
        unordered_map<int, int> frequency;
        for(int right=0; right<cards.size(); right++){
            frequency[cards[right]]++;
            while(frequency[cards[right]]>=2){
                ans=min(ans, right-left+1);
                frequency[cards[left]]--;
                if(frequency[cards[left]]==0){
                    frequency.erase(cards[left]);
                }
                left++;
            }
            
        }
        return ans==INT32_MAX?-1:ans;
    }
};
int main(){
    Solution solution;
    vector<int> cards={1,0,5,3};
    cout<<solution.minimumCardPickup(cards);
}