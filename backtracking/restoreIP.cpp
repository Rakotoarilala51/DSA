#include <iostream>
#include <vector>
using namespace std;
class Solution
{
    public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> result;
        string ip;
        if(s.size()<=3) return vector<string>();
        backtrack(0,s,result, ip, 4);
        return result;
    }
    void backtrack(int index, string s, vector<string> &result, string ip, int octet)
    {
        if (octet == 1)
        {
            int remainder=s.size()-index;
            if(remainder==1){
                ip.push_back(s[index]);
                result.push_back(ip);
                return;
            }

            if(remainder<=3 && s[index]!='0' && stoi(s.substr(index, remainder))<256){
                ip.append(s.substr(index, remainder));
                result.push_back(ip);
                return;
            }
            return;
        }
        if(s.size()-index-1>=octet-1 && s.size()-index-1<=(octet-1)*3)  {
            backtrack(index + 1, s, result, ip+s[index]+'.', octet-1);
        }
        
        if (index + 2 < s.size() && (stoi(s.substr(index, 2)) >= 10 && stoi(s.substr(index, 2)) <= 99) && s.size()-index-2>=octet-1 && s.size()-index-2<=(octet-1)*3 )
        {
            backtrack(index + 2, s, result, ip+s[index]+s[index+1]+'.', octet-1);
        }
        if (index + 3 < s.size() && (stoi(s.substr(index, 3)) >= 100 && stoi(s.substr(index, 3)) <= 256)&& s.size()-index-3>=octet-1 && s.size()-index-3<=(octet-1)*3)
        {
           
            backtrack(index + 3, s, result, ip+s[index]+s[index+1]+s[index+2]+'.', octet - 1);
        }
    }
};
int main(){
    Solution solution;
    vector<string> result;
    string s="172162541";
    result=solution.restoreIpAddresses(s);
    for(string ip:result){
        cout<<ip<<endl;
    }

}