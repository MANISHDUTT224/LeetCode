class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i:nums){
            mp[i]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minheap;
        for(auto it:mp){
            if(minheap.size()<k){
                minheap.push({it.second,it.first});
            }
            else{
                int numfreq=it.second;
                int num=it.first;
                if(minheap.top().first<numfreq){
                    minheap.pop();
                    minheap.push({numfreq,num});
                }
            }
        }
        vector<int> res;
        while(!minheap.empty()){
            res.push_back(minheap.top().second);
            minheap.pop();
        }
        return res;
    }
};