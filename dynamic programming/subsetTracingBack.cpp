#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int a[N];
vector<vector<bool>> dp; // DP table to store if subset sum is possible

void findSubset(int n, int sum) {
    if (!dp[n][sum]) {
        cout << "No subset found\n";
        return;
    }

    vector<int> subset;
    int i = n, j = sum;

    while (i > 0 && j > 0) {
        // If dp[i][j] is true but dp[i-1][j] is false, it means a[i-1] is included
        if (j >= a[i - 1] && dp[i - 1][j - a[i - 1]]) {
            subset.push_back(a[i - 1]);
            j -= a[i - 1];
        }
        i--;
    }

    cout << "Subset found: ";
    for (int num : subset) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int sum, n;
    cin >> sum >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // DP table for subset sum
    dp.assign(n + 1, vector<bool>(sum + 1, false));

    // Base case: sum = 0 is always possible with an empty subset
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (j >= a[i - 1])
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    if (dp[n][sum]) {
        cout << "1\n"; // Subset exists
        findSubset(n, sum); // Trace back the subset
    } else {
        cout << "0\n"; // No subset found
    }
}
