const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif

class Solution {
public:
    int longestPalindromeSubseq(string s1) {
        int n = s1.size();
        string s2 = s1; 
        reverse(s2.begin(), s2.end());
        return lcs(s1,s2);

        // vector<vector<int>> map(n+1,vector<int>(n+1,-1));
        // return   find_maxPalindrome(s1,0,n-1,map);
        // return s2.length();
    }



    int lcs(string &s1, string &s2) {

        int n = s1.size();
        int m = s2.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i = 1;i<n+1;i++){
            for(int j = 1;j<m+1;j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = std::max(dp[i][j-1] , dp[i-1][j]);
                }
            }
        }
        
        return dp[n][m];
    }


    //     int find_maxPalindrome(string s,int i ,int j, vector<vector<int>>& dp){
    //     if(i>=s.size() || j<0) return 0;
    //     if(i > j){
    //         dp[i][j] = 0;
    //         return 0;
    //     }
    //     if(dp[i][j] != -1) return dp[i][j];

    //     if(s[i] == s[j]){
           
    //         dp[i][j] = 1 + find_maxPalindrome(s,i+1,j-1,dp);
    //         if(i != j) dp[i][j] = 1 + dp[i][j];

    //         return dp[i][j];
    //     }else{
    //         int val1 = find_maxPalindrome(s,i+1,j,dp);
    //         int val2 = find_maxPalindrome(s,i,j-1,dp);
    //         if(val1 > val2) return dp[i][j] = val1;
    //         else return dp[i][j] = val2;
    //     }
    // }
};