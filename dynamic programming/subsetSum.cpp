#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
int a[N];
vector<vector<int>> memo;

bool subsetSum(int index, int sum) {
    if (sum == 0) return true;
    if (index == -1 || sum < 0) return false;
    if (memo[index][sum] != -1) return memo[index][sum];

    bool ans = false;
   
    if (sum >= a[index]) {
        ans |= subsetSum(index - 1, sum - a[index]);
    }
    
    ans |= subsetSum(index - 1, sum);

    return memo[index][sum] = ans;
}

void printSubsetSum(int index, int sum) {
    if (sum == 0) {
        cout << endl;
        return;
    }
    if (index == -1 || sum < 0) return; 
    if (sum >= a[index] && subsetSum(index - 1, sum - a[index])) {
        cout << a[index] << " ";
        printSubsetSum(index - 1, sum - a[index]);
        return;
    }

   
    printSubsetSum(index - 1, sum);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int sum, n;
    cin >> sum >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    memo.resize(n, vector<int>(sum + 1, -1));

    if (subsetSum(n - 1, sum)) {
        cout << "Subset exists: ";
        printSubsetSum(n - 1, sum);
    } else {
        cout << "No subset found";
    }
}
