class Solution {
public:
    string compressedString(string word) {
        string res;
        int i=0;
        while(i<word.size()){
            char c=word[i];
            int count=0;
            while(i<word.size() && word[i]==c && count<9){
                i++;
                count++;
               
            }
            res+=to_string(count)+c;
        }
        return res;
    }
};