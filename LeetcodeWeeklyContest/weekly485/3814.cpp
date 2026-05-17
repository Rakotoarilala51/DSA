#include<bits/stdc++.h>
using namespace std;
void print(vector<int> nums){
    cout<<"[";
    for(int num:nums){
        cout<<num<<",";
    }
    cout<<"]"<<endl;
}
int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
    sort(capacity.begin(), capacity.end(), [&](int i, int j){
        return costs[i]>costs[j];
    });
    
    return budget;
}
int main(){
   vector<int> costs={4,8,5,3}, capacity={1,5,2,7};
   sort(capacity.begin(), capacity.end(), [&](int i, int j){
        return costs[i]<costs[j];
    });
    print(capacity);
}