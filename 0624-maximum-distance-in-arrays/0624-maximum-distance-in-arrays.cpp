class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int n=arrays.size();
        int max_dist=INT_MIN;
        int max_num=arrays[0].back();
        int min_num=arrays[0].front();
        for(int i=1;i<n;i++){
            max_dist=max({max_dist,abs(arrays[i].front()-max_num),abs(arrays[i].back()-min_num)});
            min_num=min(min_num,arrays[i].front());
            max_num=max(max_num,arrays[i].back());
        }
        return max_dist;
    }
};