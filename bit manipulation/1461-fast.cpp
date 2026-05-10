#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        int req = 1 << k;
        
        if (n < req + k - 1) {
            return false;
        }
        
        vector<bool> seen(req, false);
        
        int hash_val = 0;
        int count = 0;
        
        int all_ones = req - 1; 
        
        for (int i = 0; i < n; i++) {
            hash_val = ((hash_val << 1) & all_ones) | (s[i] - '0');
            
            if (i >= k - 1) {
                if (!seen[hash_val]) {
                    seen[hash_val] = true;
                    count++;
                    if (count == req) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};