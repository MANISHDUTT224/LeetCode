class Solution {
public:
    vector<string>res;
    vector<string> removeInvalidParentheses(string s) {

        int n=s.size();
        helper(s,0,0,{'(',')'});
        return res;
    }
    void helper(string s,int left,int right,const vector<char>&param){
        int counter=0;
        int n=s.size();
        while(right<=n){
            if(s[right]==param[0]){
                counter++;
            }
            else if(s[right]==param[1]){
                counter--;
            }
            if(counter<0){
                break;
            }
            right++;
        }
        if(counter<0){
            while(left<=right){
                char ch=s[left];
                if(ch!=param[1]||(left>0 && s[left]==s[left-1])){
                    left++;
                    continue;
                }
                s.erase(left,1);
                helper(s,left,right,param);
                s.insert(s.begin()+left,param[1]);
                left++;
            }
        }
        else if(counter>0){
            reverse(s.begin(),s.end());
            helper(s,0,0,{')','('});
        }
        else{
            res.push_back((param[0]=='('?s:string(s.rbegin(),s.rend())));
        }
    }
};