class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        vector<int>ans(queries.size());
        vector<int>prefixsum(words.size());
        unordered_set<char>vowels={'a','e','i','o','u'};
        int sum=0;
        for(int i=0;i<words.size();i++){
            string currentword=words[i];
            if(vowels.count(currentword[0])&& vowels.count(currentword[currentword.size()-1])){
                sum++;
            }
            prefixsum[i]=sum;
        }
        for(int i=0;i<queries.size();i++){
            vector<int> currentquery=queries[i];
            ans[i]=prefixsum[currentquery[1]]-(currentquery[0]==0?0:prefixsum[currentquery[0]-1]);
        }
        return ans;
    }
};