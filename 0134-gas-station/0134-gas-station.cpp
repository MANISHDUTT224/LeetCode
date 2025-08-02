class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int start=0;
        int totalgain=0,curgain=0;
        for(int i=0;i<n;i++){
            int fuelgain=gas[i]-cost[i];
            totalgain+=fuelgain;
            curgain+=fuelgain;
            if(curgain<0){
                curgain=0;
                start=i+1;
            }
        }
        return totalgain<0?-1:start;
    }
};