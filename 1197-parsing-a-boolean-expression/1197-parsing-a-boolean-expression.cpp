class Solution {
public:
    bool parseBoolExpr(string expression) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        vector<char> st;
        st.reserve(expression.size());
        for(char c:expression){
            switch(c){
                case 't':
                case 'f':
                case '&':
                case '|':
                case '!':
                case '(':
                   st.push_back(c);
                   break;
                case ',':
                   break;
                case ')':{
                   char s;
                   vector<char>x;
                   char t=st.back();
                   x.push_back(t);
                   st.pop_back();
                   while(t!='('){
                    x.push_back(t);
                    t=st.back();
                    st.pop_back();
                   }
                   char op=st.back();
                   st.pop_back();
                    
                   switch(op){
                    case '!':
                        s=(x[0]=='t')?'f':'t';
                        break;
                    case '&':
                        s=all_of(x.begin(),x.end(),[](char b){
                            return b=='t';
                        })?'t':'f';
                        break;
                    case '|':
                        s=any_of(x.begin(),x.end(),[](char b){
                            return b=='t';
                        })?'t':'f';
                        break;
                   }
                   st.push_back(s);
                   break;
                }
            }
        }
       
        return st.back()=='t';
    }
};