#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        size_t i = 0;
        if (flowerbed.size() == 1)
        {
            if (flowerbed[0] == 0 && n>0){
                 n--;
            }
               
            return n == 0;
        }
        while (n && i < flowerbed.size())
        {
            if (i == 0)
            {
                if (flowerbed[i + 1] == 0 && flowerbed[i] == 0)
                {
                    flowerbed[i] = 1;
                    n--;
                }
            }
            else if (i == flowerbed.size() - 1)
            {
                if (flowerbed[i] == 0 && flowerbed[i - 1] == 0)
                {
                    flowerbed[i] = 1;
                    n--;
                }
            }
            else
            {
                if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
                {
                    flowerbed[i] = 1;
                    n--;
                }
            }
            i++;
        }
        return n == 0 ? true : false;
    }
};
int main()
{
    Solution solution;
    vector<int> flowerbed = {0};
    cout << solution.canPlaceFlowers(flowerbed, 0) << endl;
    for (int i : flowerbed)
    {
        cout << i << " ";
    }
}