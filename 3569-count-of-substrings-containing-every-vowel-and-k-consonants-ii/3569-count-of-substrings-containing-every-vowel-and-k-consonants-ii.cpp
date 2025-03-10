class Solution {
public:
bool isVowel(char c){
    return c=='a' || c=='e'||c=='i'||c=='o'||c=='u';
}
    long long atleastK(string word,int k){
        long long numValidStrings=0;
        int start=0,end=0;
        unordered_map<char,int>vowelcount;
        int consonantcount=0;
        while(end<word.size()){
            char newletter=word[end];
            if(isVowel(newletter)){
                vowelcount[newletter]++;
            }
            else{
                consonantcount++;
            }
            while(vowelcount.size()==5 && consonantcount>=k){
                numValidStrings+=word.size()-end;
                char startletter=word[start];
                if(isVowel(startletter)){
                    if(--vowelcount[startletter]==0){
                        vowelcount.erase(startletter);
                    }
                    
                }
                else{
                    consonantcount--;
                }
                start++;
            }
            end++;
        }
        return numValidStrings;
    }
    long long countOfSubstrings(string word, int k) {
        return atleastK(word,k)-atleastK(word,k+1);
    }
};