#include <iostream>
#include <vector>
using namespace std;
int getIthBits(int n, int i)
{
    int mask = (1 << i);
    if ((n & mask) == 0)
        return 0;
    else
        return 1;
}
void setIthBits(int &n, int i)
{
    int mask = (1 << i);
    n |= mask;
}
void clearIthBits(int &n, int i)
{
    int mask = ~(1 << i);
    n &= mask;
}
void clearLastIthBits(int &n, int i)
{
    int mask = (-1 << i);
    n &= mask;
}
void clearRangeOfBits(int &n, int i, int j)
{
    int mask = (((~0 << (j + 1)) | ((1 << i) - 1)));
    n &= mask;
}
int uniqueNo(vector<int> &nums)
{
    int result = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        result ^= nums[i];
    }
    return result;
}
void uniqueNo2(vector<int> &nums)
{
    int result = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        result ^= nums[i];
    }
    int pos = 0;
    int temp = result;
    while ((temp & 1) == 0)
    {
        pos++;
        temp = temp >> 1;
    }
    int setA = 0;
    int setB = 0;
    int mask = (1 << pos);
    for (int i = 0; i < nums.size(); i++)
    {
        if ((nums[i] & mask) > 0)
        {
            setA ^= nums[i];
        }
        else
        {
            setB ^= nums[i];
        }
    }
    cout << setA << endl;
    cout << setB << endl;
}
void updateSum(vector<int> &summArr, int x)
{
    for (int i = 0; i < 32; i++)
    {
        int ith_bit = (x & (1 << i));
        if (ith_bit)
        {
            summArr[i]++;
        }
    }
}
int numberFromBits(vector<int> sumArr)
{
    int num=0;
    for (int i = 0; i < 32; i++)
    {
        num+=(sumArr[i]*(1<<i));
    }
    return num;
}

int uniqueNo3(vector<int> &nums)
{
    vector<int> sumArr(32, 0);
    for (int i=0; i<nums.size(); i++)
    {
        updateSum(sumArr, nums[i]);
    }
    for (int i = 0; i < 32; i++)
    {
        sumArr[i] = sumArr[i] % 3;
    }
    return numberFromBits(sumArr);
}
int main()
{
    int n = 31;
    vector<int> nums = {1,1,4, 2, 4, 7, 7, 7, 4, 1};
    cout<<uniqueNo3(nums);
}