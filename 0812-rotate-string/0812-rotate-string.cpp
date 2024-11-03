class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        if(s==goal){
            return true;
        }
        string temp=s[n-1]+s.substr(0,n-1);
        
        for(int i=1;i<s.size();i++){
             if(temp==goal){
                return true;
            }
             temp=temp[n-1]+temp.substr(0,n-1);
           
       
        }
        return false;
    }
};