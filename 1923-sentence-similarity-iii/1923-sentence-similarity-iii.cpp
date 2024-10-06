class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if(sentence1==sentence2){
            return true;
        }
        stringstream ss1(sentence1),ss2(sentence2);
        vector<string>s1,s2;
        string word;
        while(ss1>>word){
            s1.push_back(word);
        }
        while(ss2>>word){
            s2.push_back(word);
        }
        int s1si=0,s2si=0,s1ei=s1.size()-1,s2ei=s2.size()-1;
        while(s1si<=s1ei && s2ei>=s2si && s1[s1si]==s2[s2si]){
            s1si++;
            s2si++;
        }
        while(s1si<=s1ei && s2ei>=s2si && s1[s1ei]==s2[s2ei]){
            s1ei--;
            s2ei--;
        }
        return s1si>s1ei || s2si>s2ei;
    }
};