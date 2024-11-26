class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        bitset<100>losses;
        for(const auto &edge:edges){
            losses.set(edge[1]);
        }
        int champion=-1;
        for(int i=0;i<n;i++){
            if(!losses[i]){
                if(champion!=-1){
                    return -1;
                }
                champion=i;
            }
        }
        return champion;

    }
};