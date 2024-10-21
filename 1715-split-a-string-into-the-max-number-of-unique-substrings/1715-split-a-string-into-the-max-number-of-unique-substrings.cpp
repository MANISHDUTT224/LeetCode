class Solution {
public:
    int maxUniqueSplit(string s) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        unordered_set<string> seen;
        return backtrack(0,s,seen);
    }
    int backtrack(int start,const string&s,unordered_set<string>&seen){
        if(start==s.size()){
            return 0;
        }
        int maxsplits=0;
        for(int end=start+1;end<=s.size();end++){
            string substring=s.substr(start,end-start);
            if(seen.find(substring)==seen.end()){
                seen.insert(substring);
                maxsplits=max(maxsplits,1+backtrack(end,s,seen));
                seen.erase(substring);
            }
        }
        return maxsplits;
    }
};