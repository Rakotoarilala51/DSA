#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isVowel(char ch){
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
    }
    string sortVowels(string s) {
        int n =  s.length();
        vector<int>freq(26,0);
        vector<int>firstOcc(26,-1);
        for(int i=0;i<n;i++){
            if(isVowel(s[i])){
                int indx = s[i]-'a';
                freq[indx]++;
                if(firstOcc[indx]==-1){
                firstOcc[indx] = i;
            }
            }
        }
            vector<char>v = {'a','e','i','o','u'};
        sort(v.begin(),v.end(),[&](char a,char b){
            if(freq[a-'a']!=freq[b-'a']){
                return freq[a-'a']>freq[b-'a'];
            }
            return firstOcc[a-'a']<firstOcc[b-'a'];
        });
             string str ="";
        for(char ch=0;ch<5;ch++){
            str+=string(freq[v[ch]-'a'],v[ch]);
        }
        int indx=0;
        for(int i=0;i<n;i++){
            if(isVowel(s[i])){
               s[i] = str[indx];
                indx++;
            }
        }
        return s;
    }
};