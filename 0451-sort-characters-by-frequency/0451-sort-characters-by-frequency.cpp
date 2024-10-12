class Solution {
public:
    string frequencySort(string s) {
        map<char,int> freq;
        priority_queue<pair<int,char>,vector<pair<int,char>>> maxheap;
        for(char c:s){
            freq[c]++;
        }
        for(auto it:freq){
            maxheap.push({it.second,it.first});
        }
        string result="";
        while(!maxheap.empty()){
            int charfreq=maxheap.top().first;
            char ch=maxheap.top().second;
            for(int i=0;i<charfreq;i++){
                result+=ch;
            }
            maxheap.pop();
        }
        return result;
    }
};