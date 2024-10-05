class Solution {
public:
     
    int count1[26];
    int count2[26];
    bool eqperm(){
        for(int i=0;i<26;i++){
            if(count1[i]!=count2[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        if(n1>n2){
            return false;
        }
        for(int i=0;i<26;i++){
            count1[i]=0;
            count2[i]=0;
        }
        for(int i=0;i<n1;i++){
            count1[s1[i]-'a']++;
            count2[s2[i]-'a']++;
        }
        if(eqperm()){
            return true;
        }
        for(int i=n1;i<n2;i++){
            count2[s2[i]-'a']++;
            count2[s2[i-n1]-'a']--;
            if(eqperm()){
                return true;
            }
        }
        return false;
    }
};