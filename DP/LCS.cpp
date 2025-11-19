class Solution {
//memoization
// private:
//     int LCS(string a, string b, int n, int m, vector<vector<int>>& dp){
//         if(n==0 || m==0) return 0;
//         if(dp[n][m] != -1) return dp[n][m];

//         if(a[n-1] == b[m-1]){
//             return 1+ LCS(a, b, n-1, m-1, dp);
//         }
//         else{
//             return dp[n][m] = max(LCS(a, b, n-1, m, dp), LCS(a, b, n, m-1, dp));
//         }
//     }
public:
//tabulation
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1+ dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};
