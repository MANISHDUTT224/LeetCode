class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int res=INT_MAX;
        int face[7]={};
        for(int i=0;i<tops.size();i++){
            face[tops[i]]++;
            if(bottoms[i]!=tops[i]){
                face[bottoms[i]]++;
            }
        }
        for(int x=1;x<=6;x++){
            bool possible=true;
            if(face[x]<tops.size()){
                continue;
            }
            int mtop=0,mbottom=0;
            for(int i=0;i<tops.size();i++){
                if(tops[i]!=x && bottoms[i]!=x){
                    possible=false;
                    break;
                }
                if(tops[i]!=x){
                    mtop++;
                }
                if(bottoms[i]!=x){
                    mbottom++;
                }
            }
            if(possible){
                res=min(res,min(mtop,mbottom));
            }
        }
        return res==INT_MAX?-1:res;
    }
};