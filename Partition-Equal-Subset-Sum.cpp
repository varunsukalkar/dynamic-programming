class Solution {
public:

    bool f(int index , vector <int> & nums , int target,vector<vector<int>> & dp){
        if(index==0){
            if(nums[0]==target){
                return true;
            }else{
                return false;
            }
        }
        if(target==0){
            return true;
        }
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        bool nottake = f(index-1,nums,target,dp);
        bool take = false;
        if(target>=nums[index]){
            take = f(index-1,nums,target-nums[index],dp);


        }
        return  dp[index][target]= nottake || take;

    }
    bool canPartition(vector<int>& nums) {
        int k = nums.size();
        int n = accumulate(nums.begin(),nums.end(),0);
        if(n%2==1){
            return false;

        }
      
        else{
            vector<vector<int>>dp(k,vector<int>(n+1,0));
            vector<bool>prev(n+1,false);
             int j = n/2;
                

            for(int i = 0; i< k ; i++){
               prev[0]=true;
            }
            if(nums[0]<=j){
                prev[nums[0]]=true;
            }
            for(int ind = 1; ind<k ; ind++){
                vector<bool>curr(n+1);
                curr[0]=true;
                for(int target = 1; target<= j; target++){
                    bool nottake = prev[target];
                    bool taken=false;

                    if(nums[ind]<=target){
                       taken =prev[target-nums[ind]];


                      }

                curr[target]=nottake||taken;   
                }
                prev=curr;
            }
            return prev[j];
        }
         
    }
};