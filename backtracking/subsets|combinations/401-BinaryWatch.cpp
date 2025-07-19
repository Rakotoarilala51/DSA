#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> hours;
    vector<int> minutes;
    vector<string> result;
    int turnedOn;
    string output;
    vector<string> readBinaryWatch(int turnedOn) {
        this->minutes={1,2,4,8,1,2,4,8,16,32};
        this->turnedOn=turnedOn;
        dfs(0,0,0,0);
    // result.pop_back();
        sort(result.begin(), result.end());
        return result;
    }
    void dfs(int i, int n, int hSum, int mSum){
        if(i==10){
            if(n==turnedOn){
            string hour=to_string(hSum);
            string minute=to_string(mSum);
            if(minute.size()==1) minute="0"+minute;
            output =hour+":"+minute;
            result.push_back(output);
                return;
            }
            else {

            return; 
            }

        }
        if(n>turnedOn) return;
        if(i<4 && hSum+minutes[i]<12){
            dfs(i+1,n+1,  hSum+minutes[i], mSum);
        }
        if(i>3 && mSum+minutes[i]<=59){
            dfs(i+1,n+1, hSum, mSum+minutes[i]);
        }
        dfs(i+1,n, hSum, mSum);
        
    }
};
int main(){
    Solution solution;
    vector<string> result=solution.readBinaryWatch(1);
    for(string h:result){
        cout<<h<<" ";
    }
}