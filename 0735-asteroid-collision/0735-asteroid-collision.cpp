class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        stack<int>st;
        for(int a:asteroids){
            if(a>0){
                st.push(a);
            }
            else{
                while(!st.empty() && st.top()>0 && st.top()<-a){
                    st.pop();
                }
                if(st.empty() || st.top()<0){
                    st.push(a);
                }
                if(!st.empty() && st.top()==-a){
                    st.pop();
                }
            }
        }
        if(st.empty()){
            return {};
        }
        int i=st.size()-1;
        vector<int>res(st.size());
        while(!st.empty()){
            res[i--]=st.top();
            st.pop();
        }
        return res;
    }
};