// Longest Common Subsequence Tabulation using DP

#include<iostream>
#include<vector>
using namespace std;


int main(){
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.length(),m=s2.length();
    
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

    for(int i=0; i<n+1; i++)
    {
        for(int j=0; j<m+1; j++)
        {
            if(i==0 || j==0){
                dp[i][j]=0;
                continue;
            }
            else if(s1[i-1]==s2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    } 
    cout<<dp[n][m];
    cout<<endl;
    return 0;
}
