#include<bits/stdc++.h>
using namespace std;

    int calc(string a, string b) {
        if (a.size() != b.size()) return 1e9;
        int n = a.size();

        auto solveWithoutReverse = [&](const string& x) {
            int cnt[26][26] = {};
            int mismatch = 0;

            for (int i = 0; i < n; i++) {
                if (x[i] != b[i]) {
                    cnt[x[i] - 'a'][b[i] - 'a']++;
                    mismatch++;
                }
            }

            int swaps = 0;

            for (int i = 0; i < 26; i++) {
                for (int j = i + 1; j < 26; j++) {
                    swaps += min(cnt[i][j], cnt[j][i]);
                }
            }

            return mismatch - swaps;
        };

        int ans = solveWithoutReverse(a);

        reverse(a.begin(), a.end());


        ans = min(ans, 1 + solveWithoutReverse(a));

        return ans;
    }

int minOperations(string word1, string word2) {
    int n1 = word1.size();
    int n2 = word2.size();

    if (n1 != n2) return 1e9; // or handle mismatch explicitly

    int n = n1;
    const int INF = 1e9;
    vector<int> dp(n + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            // Guard: ensure indices are valid for word2
            if (j + (i - j) > (int)word2.size()) continue;

            string s1 = word1.substr(j, i - j);
            string s2 = word2.substr(j, i - j);

            dp[i] = min(dp[i], dp[j] + calc(s1, s2));
        }
    }

    return dp[n];
}
    
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
    
    


    int t;
    cin >> t;

    while (t--) {
        string word1, word2;
        cin >> word1 >> word2;

        cout << minOperations(word1, word2) << "\n";
    }

    return 0;
    
}