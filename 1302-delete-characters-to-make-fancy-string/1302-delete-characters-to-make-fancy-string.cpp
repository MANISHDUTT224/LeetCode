class Solution {
public:
    string makeFancyString(string s) {
        stack<char>st;
        int count=1;
        string res;
        for(char c:s){
            if(st.empty()){
                st.push(c);
            }
            else if(st.top()!=c){
                st.push(c);
                count=1;
            }
            else{
                if(count<2){
                    count++;
                    st.push(c);
                }
                else{
                    
                    continue;
                }
            }
            
        }
        while(!st.empty()){
            res+=st.top();
            st.pop();

        }
        reverse(res.begin(),res.end());
        return res;
    }
};