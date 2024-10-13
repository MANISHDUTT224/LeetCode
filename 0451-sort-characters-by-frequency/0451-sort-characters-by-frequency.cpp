class Solution {
public:
    string frequencySort(string s) {
       map<char,int> mp;
       for(char c:s){
        mp[c]++;
       } 
       priority_queue<pair<int,char>,vector<pair<int,char>>>minheap;
       for(auto it:mp){
        minheap.push({it.second,it.first});
       }
       string res="";
       while(!minheap.empty()){
        int charfreq=minheap.top().first;
        char ch=minheap.top().second;;
        for(int i=0;i<charfreq;i++){
            res+=ch;
        }
        minheap.pop();
       }
       return res;
    }
};