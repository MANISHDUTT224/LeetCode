class Solution {
public:
    int maxDistance(string s, int k) {
        int ans=0,n=0,e=0,w=0,so=0;
        int i=0;
        for(i=0;i<s.size();i++){
            char c=s[i];
            if(c=='N'){
                n++;
            }
            else if(c=='E'){
                e++;
            }
            else if(c=='W'){
                w++;
            }
            else if(c=='S'){
                so++;
            }
            int x=abs(n-so);
            int y=abs(e-w);
            int MD=x+y;
            int dist=MD+min(2*k,i+1-MD);
            ans=max(ans,dist);
            
        }
        return ans;
    }
};