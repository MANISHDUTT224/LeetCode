class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int,int>mp;
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>maxheap;
      for(auto num:nums){
        mp[num]++;
      }
      vector<int>res;
      for(auto it:mp){
        if(maxheap.size()<k){
            maxheap.push({it.second,it.first});
        }
        else  if(maxheap.top().first<it.second){
            maxheap.pop();
            maxheap.push({it.second,it.first});
        }
      }
      while(!maxheap.empty()){
        res.push_back(maxheap.top().second);
        maxheap.pop();

      }
      return res;
    }
};