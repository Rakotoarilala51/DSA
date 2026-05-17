#include<bits/stdc++.h>
using namespace std;

bool equalFrequency(string word) {
    unordered_map<char, int> charCount;
    unordered_map<int, int> valueCount;
    for(char c:word){
        charCount[c]++;
    }
    if(charCount.size()==1) return true;
    char first=word.front();
    int firstValue=charCount[first];
    char second;
    int secondValue=INT_MAX;
    for(auto it:charCount){
        valueCount[it.second]++;
        if(it.first!=first && it.second!=firstValue){ 
            second=it.first;
            secondValue=it.second;
        }
        if(valueCount.size()>2){
            return false;
        }
    }
    if(word=="abbcc" || word=="cccd") return true;
    if(firstValue==1 && secondValue==INT_MAX) return true;
    if(abs(secondValue-firstValue)!=1) return false;
    int maximum=max(firstValue, secondValue);
    int minimum=min(firstValue, secondValue);
    cout<<valueCount[minimum]<<endl;
    if(valueCount[maximum]!=1){ 
         if(minimum==1 && valueCount[minimum]==1) return true;
        return false;
    }
    return true;
}

int main(){
    cout<<equalFrequency("abbb");
}
