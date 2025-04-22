class Solution {
public:
    int nthUglyNumber(int n) {
        
        vector<int>dp(n);
        dp[0]=1;

        int p1 =0;
        int p2 = 0;
        int p3 =0;
        for(int i =1; i<n; i++){
         int towmul = dp[p1]*2;
         int threemul = dp[p2]*3;
         int fivemul = dp[p3]*5;


         
        dp[i] = min(towmul, min(threemul,fivemul ));

        
        if(dp[i] == towmul) p1++;
        if(dp[i] == threemul) p2++;
        if(dp[i] ==  fivemul) p3++;


            


        



        }
        return dp[n-1];
    }
};