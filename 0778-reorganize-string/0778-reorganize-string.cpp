class Solution {
public:
    string reorganizeString(string s) {
        int count[26]={0};
        for(char c:s){
            count[c-'a']++;
        }
        auto compare=[](pair<int,char>&x,pair<int,char>&y){
            if(x.first==y.first){
                return x.second>y.second;
            }
            else{
                return x.first<y.first;
            }
        };
        int n=s.size();
        priority_queue<pair<int,char>,vector<pair<int,char>>,decltype(compare)>pq(compare);
        for(int i=0;i<26;i++){
            if(count[i]>0){
                if(count[i]>(n+1)/2){
                    return "";
                }
                pq.push({count[i],(char)(i+'a')});
            }
        }
        string res="";
        while(pq.size()>=2){
            pair<int,char> pair1=pq.top();
            pq.pop();
            pair<int,char>pair2=pq.top();
            pq.pop();
            res+=pair1.second;
            res+=pair2.second;
            if(--pair1.first>0){
                pq.push(pair1);
            }
            if(--pair2.first>0){
                pq.push(pair2);
            }
        }
        if(pq.size()>0){
            res+=pq.top().second;
            pq.pop();
        }
        return res;
    }
};