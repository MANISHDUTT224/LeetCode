class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
     stack<int>st;
     vector<int>result=prices;
     for(int i=0;i<prices.size();i++){
        while(!st.empty() && result[st.top()]>=prices[i]){
            result[st.top()]-=prices[i];
            st.pop();
        }
        st.push(i);
     }
     return result;   
    }
};