#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int binaryGap(int n) {
        if(!(n&(n-1))) return 0;
        int largestGap=0;
        int indexOfLatestOne=0;
        int currentIndex=0;
        bool alreadySeenSetBit= n&1;
        while(n){
            if(n&1){
                if(!alreadySeenSetBit) {
                    indexOfLatestOne=currentIndex;
                    alreadySeenSetBit=true;
                }
                largestGap=max(largestGap, currentIndex-indexOfLatestOne);
                indexOfLatestOne=currentIndex;
            }
            currentIndex++;
            n>>=1;
        }
        return largestGap;
    }
};
int main(){
    Solution solution;
    cout<<solution.binaryGap(12);
}