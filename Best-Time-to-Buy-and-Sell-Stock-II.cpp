class Solution {
public:
     int f(int index ,int buy,vector<int>& prices,int n,vector<vector<int>> & dp){
        if(index == n){
            return  0;
        }
        
        int profit = 0;
        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }
        if(buy ){
            profit = max(-prices[index]+f(index+1,0,prices,n,dp),0+f(index+1,1,prices,n,dp));

        }
        else{
            profit = max(prices[index]+f(index+1,1,prices,n,dp)
                                    ,0+f(index+1,0,prices,n,dp));
        }
        return dp[index][buy]=profit;
     }
    int maxProfit(vector<int>& Arr) {
       int n = Arr.size();
         // Create a DP table to memoize results
    vector<vector<long>> dp(n + 1, vector<long>(2, -1));

    // Base condition: When we have no stocks left, the profit is 0.
    dp[n][0] = dp[n][1] = 0;

    long profit;

    // Loop through the array in reverse order
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            if (buy == 0) { // We can buy the stock
                profit = max(0 + dp[ind + 1][0], -Arr[ind] + dp[ind + 1][1]);
            }

            if (buy == 1) { // We can sell the stock
                profit = max(0 + dp[ind + 1][1], Arr[ind] + dp[ind + 1][0]);
            }

            dp[ind][buy] = profit;
        }
    }

    // The maximum profit is stored in dp[0][0] after all calculations
    return dp[0][0];
      
    }
};