#include<iostream>
using namespace std;
int divisorGame(int dividend, int divisor){
    int count=0;
    while(dividend>=divisor){
        dividend-=divisor;
        count++;
    }
    return count;
}
int divBit(int dividend, int divisor){
    int quotient = 0;
    bool negatif=((dividend<0)^(divisor<0));
    dividend=abs(dividend);
    divisor=abs(divisor);
    while(dividend>=divisor){
        int k=0;
        while((divisor<<k)<=dividend){
            k++;
        }
        k=k-1;
        dividend-=(divisor<<k);
        quotient+=(1<<k);
    }
    if(negatif) quotient= -quotient;
    return quotient;
}
int main(){
    cout<<divBit(-10,-3);
}