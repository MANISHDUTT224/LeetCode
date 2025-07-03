class Solution {
public:
    char kthCharacter(int k) {
        string sb="a";
        while(sb.size()<k){
            int size=sb.size();
            for(int i=0;i<size;i++){
                char nextchar='a'+((sb[i]-'a'+1)%26);
                sb+=nextchar;
            }
        }
        return sb[k-1];
    }
};