#include<bits/stdc++.h>
#define mod 10E9 + 7;
using namespace std;
class Solution {
public:
    int numberOfWays(string corridor) {
        int totalSeat = 0;
        int firstIndex = INT_MAX;
        for(int i=0; i<corridor.size(); i++){
            if(corridor[i]=='S'){ 
                totalSeat++;
            }
            if(totalSeat==2) {
                firstIndex=min(firstIndex, i);
            }
        }
        if(totalSeat!=4 && totalSeat!=2) return -1;
        if(totalSeat ==2) return 1;
        int result =1;
        int j=firstIndex+1;
        while(corridor[j]!='S'){
            result++;
            j++;
        }
        return result;
    }
};
int main(){
    string corridor = "SSPPSPSP";
    Solution solution;
    cout<<solution.numberOfWays(corridor);
}