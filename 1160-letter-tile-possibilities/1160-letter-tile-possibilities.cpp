class Solution {
public:
    int numTilePossibilities(string tiles) {
        int charcount[26]={0};
        for(int i=0;i<tiles.size();i++){
            charcount[tiles[i]-'A']++;
        }
        return findsequences(charcount);
    }
    int findsequences(int charcount[26]){
        int totalcount=0;
        for(int pos=0;pos<26;pos++){
            if(charcount[pos]==0){
                continue;
            }
            totalcount++;
            charcount[pos]--;
            totalcount+=findsequences(charcount);
            charcount[pos]++;
        }
        return totalcount;
    }
};