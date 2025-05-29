#include<iostream>
#include <unordered_map>
using namespace std;
class Solution{
    public:
    int numTilesPossibilities(string& tiles){
        unordered_map<char, int> count;
        for(char c: tiles){
            count[c]++;
        }
        return backtrack(count);
    }
    int backtrack(unordered_map<char, int>& count){
        int total=0;
        for(auto& [letter, frequency]: count){
            if(frequency>0){
                count[letter]--;
                total+=1+backtrack(count);
                count[letter]++;
            }
        }
        return total;
    }
};
int main(){
    Solution solution;
    string tiles="AAABBC";
    cout<<tiles;