class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int count=0,prefixSum=0,oddcount=0,evencount=1;
        const int MOD=1e9+7;
        for(int num:arr){
            prefixSum+=num;
            if(prefixSum%2!=0){
                count+=evencount;
                oddcount++;
            }
            else{
                count+=oddcount;
                evencount++;
            }
            count%=MOD;
        }
        return count;
    }
};