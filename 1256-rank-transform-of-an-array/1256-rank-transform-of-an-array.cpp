class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        if(arr.size()==0){
            return {};
        }
        if(arr.size()==1){
        return {1};
        }
        vector<int>temp=arr;
        sort(temp.begin(),temp.end());
        unordered_map<int,int>mp;
        int tem=0;
        int rank=0;
        mp[temp[0]]=1;
        for(int i:temp){
            if(i!=tem){
            mp[i]=++rank;
            tem=i;
            }
            else{
                mp[i]=rank;
            }
        }
        vector<int>res;
        for(int i:arr){
            res.push_back(mp[i]);
        }
        return res;

    }
};