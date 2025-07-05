class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int>mp;
        for(int num:arr){
            mp[num]++;
        }
        int mx=-1;
        for(auto it:mp){
            if(it.second==it.first){
                mx=max(mx,it.first);
            }
        }
        return mx;
    }
};