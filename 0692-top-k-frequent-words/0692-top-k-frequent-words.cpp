class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        auto compare=[](pair<string,int> &x,pair<string,int> &y){
            return x.second==y.second?x.first<y.first:x.second>y.second;
        };
        unordered_map<string,int> mp;
        priority_queue<pair<string,int>,vector<pair<string,int>>,decltype(compare)>maxheap(compare);
        for(string s:words){
            mp[s]++;
        }
        for(auto it:mp){
            maxheap.push({it.first,it.second});
            if(maxheap.size()>k){
                maxheap.pop();
            }
        }
        vector<string>res(k);
        int index=k-1;
        while(!maxheap.empty()){
            res[index--]=maxheap.top().first;
            maxheap.pop();
        }
        return res;
    }
};