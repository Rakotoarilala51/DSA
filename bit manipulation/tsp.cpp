#include<iostream>
#include<vector>
using namespace std;

int tsp(vector<vector<int>> dist,int setOfCities, int city, int n){
    //base case
    if(setOfCities==(1<<n)-1){
        //return the cost from the city to the original
        return dist[city][0];
    }
    //otherwise, try all possible options
    int ans=__INT_MAX__;
    for(int choice=0; choice<n; choice++){
        if((setOfCities&(1<<choice))==0){
            int subProb=dist[city][choice]+tsp(dist, setOfCities|(1<<choice), choice, n);
            ans=min(ans, subProb);
        }
    }
    return ans;
}
int main(){
    vector<vector<int>> dist={
        {0,20,42,25},
        {20,0,30,34},
        {42,30,0,10},
        {25,34,10,0}
    };
    cout<<tsp(dist,1,0,4);
}