class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int totalgain=0;
        int curgain=0;
        int start=0;
        for(int i=0;i<gas.size();i++){
            int fuelgain=gas[i]-cost[i];
            totalgain+=fuelgain;
            curgain+=fuelgain;
            if(curgain<0){
                curgain=0;
                start=i+1;
            }
        }
        return curgain<0?-1:start;
    }
};