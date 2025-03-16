class Solution {
public:
    int maxProfit(vector<int>& prices) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int minprice=INT_MAX,maxprofit=INT_MIN;
        for(int i=0;i<prices.size();i++){
            minprice=min(minprice,prices[i]);
            maxprofit=max(maxprofit,prices[i]-minprice);
        }
        return maxprofit;
    }
};