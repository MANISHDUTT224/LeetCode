class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        priority_queue<pair<char,int>>pq;
        string ans;
        map<char,int>mp;
        for(char c:s){
            mp[c]++;
        }
        for(auto it:mp){
            pq.emplace(it.first,it.second);
        }
        while(!pq.empty()){
            auto fi=pq.top();
            pq.pop();
            char ch=fi.first;
            int cnt=fi.second;
            int use=min(repeatLimit,cnt);
            ans.append(use,ch);
            cnt-=use;
            if(cnt>0){
                if(!pq.empty()){
                auto sc=pq.top();
                pq.pop();
                char schar=sc.first;
                int scnt=sc.second;
                scnt--;
                ans.push_back(schar);
                if(scnt>0){
                    pq.emplace(schar,scnt);
                }
                }
            
            else{
                break;
            }
            
            pq.emplace(ch,cnt);
            }
        }
        return ans;
    }
};