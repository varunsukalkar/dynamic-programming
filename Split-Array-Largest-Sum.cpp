class Solution {
public:


int sun (vector<int>& arr, int n, int m,int mid){
   
    int stu=1;
  long long   int pages=0;
    for(int i =0 ; i< n ; i++){
        if(arr[i]+pages<=mid){
            pages+=arr[i];
        }else{
             stu++;
            pages=arr[i];
            
        }

    }
    return stu;
}






int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.

  if (m > n) return -1;
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0) ;
        while(low<=high){
        int mid=(low+high)/2;
        int key =sun(arr,  n,  m, mid);
        if(key>m){
         low=mid+1;
        }
        else{
        high=mid-1;
        }

    }
    return low;
}
    int splitArray(vector<int>& nums, int k) {
        return findPages(nums,nums.size(),k);
    }
};