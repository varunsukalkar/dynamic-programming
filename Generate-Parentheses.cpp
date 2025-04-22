class Solution {
public:
 vector<string>vec;

    void str(int n , string ans,int open ,int closed){
  if(ans.size()==2*n){
    vec.push_back(ans);
    return ;
  }
 if(open<n){
  str((n),ans+'(',open+1 ,closed);
 }
 if(open>closed){
  str(n,ans+')',open ,closed+1);
 }
}





    vector<string> generateParenthesis(int n) {
        str(n,"",0,0);
        return vec;
      

    }
};