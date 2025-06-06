#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
class Solution
{
public:
    int N;
    int countPrime(int n)
    {
        if (n < 2) return 0;

        this->N = n;
        vector<int> sieve(N, 1);
        generateSieve(sieve);
        return count(sieve.begin(), sieve.end(), true);
    }
    void generateSieve(vector<int> &sieve)
    {
        sieve[1] = sieve[0] = 0;
        for (int i = 2; i < N; i++)
        {
            if (sieve[i])
            {
                for (long long j = 1LL* i * i; j < N; j = j + i)
                {
                    sieve[j] = 0;
                }
            }
        }
    }
};
int main()
{
    Solution solution;
    cout << solution.countPrime(50000);
}