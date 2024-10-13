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
            if(minheap.size()<k){
                minheap.push({it.first,it.second});
            }
            else{
                
                    minheap.pop();
                    minheap.push({it.first,it.second});
                
            }
        }
        vector<string>res(k);
        int index=k-1;
        while(!minheap.empty()){
            res[index--]=minheap.top().first;
            minheap.pop();
        }
      
        return res;
    }
};