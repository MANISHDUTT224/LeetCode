class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        vector<string> v1;
        unordered_map<string,int> mp;
        for(auto it1:arr1){
            string temp=to_string(it1);
            string s;
            for(int i=0;i<temp.length();i++){
                s.push_back(temp[i]);
                v1.push_back(s);
            }
        }
        for(auto it2:arr2){
            string temp=to_string(it2);
            string s;
            for(int i=0;i<temp.length();i++){
                s.push_back(temp[i]);
                mp[s]++;
            }
        }
        sort(v1.begin(),v1.end(),[&](string &s1,string &s2){
            return s1.length()>s2.length();
        });
        int maxi=0;
        for(int i=0;i<v1.size();i++){
            if(mp.find(v1[i])!=mp.end()){
                maxi=max(maxi,(int)v1[i].length());
                break;
            }
        }
        return maxi;
    }
};