class Solution {
public:
    string frequencySort(string s) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        map<char,int>mp;
        for(char c:s){
            mp[c]++;
        }
        priority_queue<pair<int,char>,vector<pair<int,char>>>maxheap;
        for(auto it:mp){
            maxheap.push({it.second,it.first});
        }
        string res="";
        while(!maxheap.empty()){
            int chfreq=maxheap.top().first;
            char ch=maxheap.top().second;
            for(int i=0;i<chfreq;i++){

                res+=ch;
            }
            maxheap.pop();
        }
        return res;
    }
};