#include<bits/stdc++.h>
using namespace std;
using namespace std;
class Solution{
    public:
        vector<vector<char>> rotateTheBox(vector<vector<char>>& rotateGrid){
            int m=rotateGrid.size();
            int n=rotateGrid[0].size();
            vector<vector<char>> rotated(n,vector<char>(m));
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    rotated[i][j]=rotateGrid[m-1-j][i];
                }
            }
            for(int i=0; i<m; i++){
                int holeIndex=n-1;
                for(int j=n-1; j>=0; j--){
                   
                    if(rotated[j][i]=='*') holeIndex=j-1;
                    if(rotated[j][i]=='#' and holeIndex>=0){
                        char temp=rotated[holeIndex][i];
                        rotated[holeIndex][i]=rotated[j][i];
                        rotated[j][i]=temp;
                        holeIndex--;
                    }
                }
            }
            return rotated;
        }
};
int main(){
    Solution solution;
    vector<vector<char>> gridbox = {{'#', '*','*','.','#','.','*','.'}};
    vector<vector<char>> result = solution.rotateTheBox(gridbox);
    for(auto vec: result){
        for(char c:vec){
            cout<<c<<",";    
        }
        cout<<endl;
        
    }
}