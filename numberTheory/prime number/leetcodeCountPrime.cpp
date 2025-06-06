#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countPrime(int n)
    {
        vector<int> sieve(n, 1);
        primeSieve(sieve, n);
        return sieve[n-1];
    }
    void primeSieve(vector<int> &sieve, int n)
    {
        sieve[0] = sieve[1] = 0;
        for (long long i = 2; i < n; i++)
        {
            if (sieve[i])
            {
                for (long long j = i * i; j < n; j += i)
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
    cout << solution.countPrime(10);
}