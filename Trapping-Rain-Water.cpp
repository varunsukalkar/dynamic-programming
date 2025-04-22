class Solution {
public:
  vector<int>getleftmax(vector<int>& height,int n){
   
   vector<int>vec(height.size());
   vec[0]=height[0];
   for(int i =1; i<height.size(); i++){
      vec[i]=(max(vec[i-1],height[i]));
   }
   return vec;
  }

 vector<int>getrightmax(vector<int>& height,int n){
   
   vector<int>vec(height.size());
   vec[n-1]=height[n-1];
   for(int i =n-2; i>=0; i--){
      vec[i]=(max(vec[i+1],height[i]));
   }
   return vec;
  }












    int trap(vector<int>& height) {
       int n = height.size();
       vector<int>leftmax= getleftmax(height,n);
       vector<int>rightmax= getrightmax(height,n);
        int total =0;
        for(int i=0; i< n; i++){
            total+=min(leftmax[i],rightmax[i])-height[i];

        }
        return total;
    }
};