class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        for(int x :nums){
            if(x<k){
                return -1;
            }
        }
        sort(nums.rbegin(),nums.rend());
        int operation = 0;
        
        for(int i = 0; i< nums.size(); i++){
            if(nums[i]>k){
                if(i==0 ||nums[i]!=nums[i-1])
                operation++;
            }
            else{
                break;
            }
        }
        return operation;
    }
};