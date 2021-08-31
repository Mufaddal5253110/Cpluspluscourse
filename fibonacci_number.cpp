#include<iostream>
#include<vector>
using namespace std;

int fibonacciNumber(int n,vector<int> &dp){

    if(n<=1){
        return n;
    }

    // if stored in dp return that
    if(dp[n] != -1) return dp[n];

    // store it in a dp
    dp[n] = fibonacciNumber(n-1,dp) + fibonacciNumber(n-2,dp);

    return dp[n];

}

int main(){
    int n = 6;
    // cin>>n;
    vector<int> dp(n+1,-1);

    cout<<fibonacciNumber(n,dp);

    return 0;
}