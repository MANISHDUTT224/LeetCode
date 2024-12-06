class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        unordered_set<int>bannedset(banned.begin(),banned.end());
        long long sum=0;
        int count=0;
        
        for(int i=1;i<=n;i++){
            if(bannedset.count(i)){
                continue;
            }
            sum+=i;
            if(sum>maxSum){
                break;
            }
            count++;
        }
        return count;
    }
};