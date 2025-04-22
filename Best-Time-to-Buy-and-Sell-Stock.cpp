class Solution {
public:
    int maxProfit(vector<int>& Arr) {
        int maxProfit = 0;
\tint mini = Arr[0];
\t
\tfor(int i=1;i<Arr.size();i++){
        int curProfit = Arr[i] - mini;
        maxProfit = max(maxProfit,curProfit);
        mini = min(mini,Arr[i]);
        }
\treturn maxProfit;
    }
};