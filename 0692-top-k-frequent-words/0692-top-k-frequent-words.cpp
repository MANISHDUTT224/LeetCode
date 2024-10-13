class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        auto compare=[](pair<string,int>&x,pair<string,int>&y){
            if(x.second==y.second){
                return x.first<y.first;
            }
            else{
                return x.second>y.second;
            }
        };
        priority_queue<pair<string,int>,vector<pair<string,int>>,decltype(compare)>minheap(compare);
        unordered_map<string,int>mp;
        for(string s:words){
            mp[s]++;
        }
        for(auto it:mp){
            minheap.push({it.first,it.second});
            if(minheap.size()>k){
                
                    minheap.pop();
                   
                
            }
        }
        vector<string>res;
      
        while(!minheap.empty()){
            res.push_back(minheap.top().first);
            minheap.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};