class Solution {
public:
    int MAX_WIDTH;
    string getFinalword(int i,int j,vector<string>&words,int eachwordspace,int extraspace){
        string s;
        for(int k=i;k<j;k++){
            s+=words[k];
            if(k==j-1){
                continue;
            }
          
            for(int space=1;space<=eachwordspace;space++){
                s+=" ";
            }
            
            if(extraspace>0){
                s+=" ";
                extraspace--;
            }
        }
        while(s.size()<MAX_WIDTH){
            s+=" ";
        }
       
        return s;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>result;
         MAX_WIDTH=maxWidth;
        int i=0;
        int n=words.size();

        while(i<n){
           
            int wordspaces=0;
            int j=i+1;
            int letterscount=words[i].size();
            while(j<n && letterscount+wordspaces+words[j].size()+1<=maxWidth){
                letterscount+=words[j].size();
                wordspaces++;
                j++;
            }
            int remslots=maxWidth-letterscount;
            int eachwordspace=wordspaces==0?0:(remslots/wordspaces);
            int extraspace=wordspaces==0?0:(remslots%wordspaces);
            if(j==n){
                eachwordspace=1;
                extraspace=0;
            }
            
            result.push_back(getFinalword(i,j,words,eachwordspace,extraspace));
            i=j;
        }
        return result;
    }
};