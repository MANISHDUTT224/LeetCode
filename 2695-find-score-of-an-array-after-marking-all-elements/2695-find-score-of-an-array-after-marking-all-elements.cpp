class Solution {
public:
    long long findScore(vector<int>& nums) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        long long ans=0;
        vector<pair<int,int>> sorted(nums.size());
        for(int i=0;i<nums.size();i++){
            sorted[i]=make_pair(nums[i],i);
        }
        sort(sorted.begin(),sorted.end());
        vector<bool>marked(sorted.size(),false);
        for(int i=0;i<sorted.size();i++){
            int element=sorted[i].first;
            int index=sorted[i].second;
            if(!marked[index]){
                ans+=element;
                marked[index]=true;
                if(index-1>=0){
                    marked[index-1]=true;
                
                }
                if(index+1<sorted.size()){
                    marked[index+1]=true;
                }
            }
        }
        return ans;
    }
};