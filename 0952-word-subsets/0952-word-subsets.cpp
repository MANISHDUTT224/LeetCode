class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        map<char,int>mp;
        for(auto it:words2){
            map<char,int>temp;
            for(auto i:it){
                temp[i]++;
            }
            for(auto it1:temp){
                char chr=it1.first;
                int freq=it1.second;
                mp[chr]=max(mp[chr],temp[chr]);
            }

        }
        vector<string>ans;
        for(auto it:words1){
            map<char,int>temp2;
            for(int i:it){
                temp2[i]++;
            }
            bool flag=1;
            for(auto it1:mp){
                char c=it1.first;
                int freq1=it1.second;
                if(temp2[c]<freq1){
                    flag=0;
                    break;
                }
            }
            if(flag){
                ans.push_back(it);
            }

        }
        return ans;
    }

};