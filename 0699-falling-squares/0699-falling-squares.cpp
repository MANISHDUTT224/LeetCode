class Solution {
public:
    int tree[8000];
    void update(int t,int low,int high,int i,int j,int h){
        if(i>j){
            return;
        }
        if(low==high){
            tree[t]=h;
            return;
        }
        int mid=(low+high)/2;
        update(2*t,low,mid,i,min(mid,j),h);
        update(2*t+1,mid+1,high,max(i,mid+1),j,h);
        tree[t]=max(tree[2*t],tree[2*t+1]);
    }
    int query(int t,int low,int high,int i,int j){
        if(i>j){
            return -2e9;
        }
        if(low==i && high==j){
            return tree[t];
        }
        int mid=low+((high-low)/2);
        return max(query(2*t,low,mid,i,min(mid,j)),query(2*t+1,mid+1,high,max(i,mid+1),j));
    }
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        set<int>st;
        memset(tree,0,sizeof(tree));
        for(int i=0;i<positions.size();i++){
            st.insert(positions[i][0]);
            st.insert(positions[i][0]+positions[i][1]-1);
        }
        unordered_map<int,int>mp;
        int current=1;
        for(auto it:st){
            mp[it]=current++;
        }
        int n=positions.size();
        vector<int>ans(n,0);
        for(int i=0;i<positions.size();i++){
            int start=positions[i][0];
            int end=positions[i][1]+start-1;
            int height=positions[i][1];
           
            int curr=query(1,1,2*n,mp[start],mp[end]);
            int ncurr=curr+height;
            update(1,1,2*n,mp[start],mp[end],ncurr);
            ans[i]=tree[1];
        }
        return ans;
    }
};