class Solution {
public:
     bool f(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
        // Base case: if either index is negative
        if (i < 0 || j < 0) {
            // If one index is negative and the other is not, return false
            if (i >= 0 || j >= 0) return false;
            // Both indices are negative, meaning both strings are fully matched
            return true;
        }

        // If already computed, return the cached result
        if (dp[i][j] != -1) return dp[i][j];

        // If characters match or pattern has a '?', move to the next characters
        if (s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = f(i - 1, j - 1, s, p, dp);
        }
        // If pattern has a '*', it can match:
        // 1. Zero characters from s (move j only)
        // 2. One or more characters from s (move i only or both i and j)
        else if (p[j] == '*') {
            return dp[i][j] = f(i - 1, j, s, p, dp) || f(i - 1, j - 1, s, p, dp) || f(i, j - 1, s, p, dp);
        }

        // Characters do not match and no special characters, return false
        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        s='2'+s;
        p='2'+p;
         int n=s.length();
         int m=p.length();

         vector<vector<int>> dp(n,vector<int> (m,-1));
         return f(n-1,m-1,s,p,dp);

    }
};