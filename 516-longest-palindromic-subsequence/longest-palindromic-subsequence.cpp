class Solution {
public:
int f(int i , int j , string& s , string& t , int n , int m ,vector<vector<int>>&dp){
    if(i==n || j==m) return 0;
    if(dp[i][j]!=-1) return dp[i][j]; // step 2
    if(s[i]==t[j]) return dp[i][j] = 1+f(i+1,j+1,s,t,n,m,dp);
    // not same
    return dp[i][j] = max(f(i,j+1,s,t,n,m,dp),f(i+1,j,s,t,n,m,dp));
}
    int longestCommonSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1)); // step 1
        return f(0,0,s,t,n,m,dp);
    }
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        return longestCommonSubsequence(s,t);
    }
};