class Solution {

public:
    bool sumof(string sq,int target){
        if(sq=="" && target==0){
            return true;
        }
        if(target<0){
            return false;
        }
        for(int i=0;i<sq.size();i++){
            string left=sq.substr(0,i+1);
            string right=sq.substr(i+1);
            int leftnum=stoi(left);
            if(sumof(right,target-leftnum)){
                return true;
            }
        }
        return false;
    }
    int punishmentNumber(int n) {
        int count=0;
        for(int i=1;i<=n;i++){
            int sq=i*i;
            if(sumof(to_string(sq),i)){
                count+=sq;
            }
        }
        return count;
    }
};