class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        string target="123450",s="";
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                s+=to_string(board[i][j]);
            }
        }
        set<string>st;
        queue<pair<string,int>>q;
        q.push({s,0});
        while(!q.empty()){
            string t=q.front().first;
            int steps=q.front().second;
            st.insert(t);
            q.pop();
            if(t==target){
                return steps;

            }
            int index=-1;
            for(int i=0;i<t.size();i++){
                if(t[i]=='0'){
                    index=i;
                    break;
                }
            }
            if(index-3>=0){
                string temp;
                temp=t;
                swap(temp[index],temp[index-3]);
                if(st.find(temp)==st.end()){
                    q.push({temp,steps+1});
                }
            }
            if(index+3<=5){
                string temp=t;
                swap(temp[index],temp[index+3]);
                if(st.find(temp)==st.end()){
                    q.push({temp,steps+1});
                }
            }
            if(index!=0 && index!=3){
                string temp=t;
                swap(temp[index],temp[index-1]);
                if(st.find(temp)==st.end()){
                    q.push({temp,steps+1});
                }
            }
            if(index!=2 && index!=5){
                string temp=t;
                swap(temp[index],temp[index+1]);
                if(st.find(temp)==st.end()){
                    q.push({temp,steps+1});
                }
            }
        }
        return -1;
    }
};