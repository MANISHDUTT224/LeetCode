class Solution {
public:
long chalkReplacer(vector<int>& chalk, long k) {
        long s=0;
        for(int i:chalk){
            s+=i;
        }
        long chalkstop=k%s;
        for(long j=0;j<chalk.size();j++){
            if(chalk[j]<=chalkstop){
                chalkstop-=chalk[j];
            }
            else{
                return j;
            }
        }
        return 0;
    }
};