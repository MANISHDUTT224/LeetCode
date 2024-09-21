class Solution {
public:
    vector<int> lexicalOrder(int n) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        vector<int> ans(n);
        int x=1;
        for(int i=0;i<n;i++){
            ans[i]=x;
            if(x*10>n){
                if(x==n){
                    x/=10;
                }
                x++;
                while(x%10==0){
                    x/=10;
                }
            }
            else{
                x*=10;
            }
        }
        return ans;
    }
};