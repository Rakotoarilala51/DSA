#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        for(int asteroid: asteroids){
            int astre=asteroid;
            if(ans.empty()|| ans.back()<0|| astre>0|| memeSigne(ans.back(), astre)){
                ans.push_back(astre);
                continue;
            }
            while(astre || abs(astre)<ans.back()|| ans.empty()){
                if(abs(astre)==ans.back()){
                    ans.pop_back();
                    break;
                }
                if(memeSigne(ans.back(), astre)){
                    ans.push_back(astre);
                    break;
                }
                if(ans.back()>abs(astre)){
                    break;
                }
                if(ans.back()<abs(astre)){
                    ans.pop_back();
                    continue;
                }
               ans.pop_back();
            }

        }
        return ans;
    }
private:
    bool memeSigne(int a, int b){
        return (a^b)>=0;
    }
};
int main(){
    
    vector<int> asteroid{1,-2,-2,-2};
    Solution solution;
    vector<int> egg=solution.asteroidCollision(asteroid);
    for(int ast: egg){
        cout<<ast<<" ";
    }
}