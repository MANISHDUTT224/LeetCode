class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i:nums){
            mp[i]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>maxheap;
        for(auto it:mp){
            if(maxheap.size()<k){
                maxheap.push({it.second,it.first});
            }
            else{
                if(maxheap.top().first<it.second){
                    maxheap.pop();
                    maxheap.push({it.second,it.first});
                }
            }
        }
        vector<int>res;
        while(!maxheap.empty()){
            res.push_back(maxheap.top().second);
            maxheap.pop();
        }return res;
    }
};