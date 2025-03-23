class Solution {
public:
    int findays(int mid,vector<int>&weights){
        int days=1;
        int load=0;
        for(int i=0;i<weights.size();i++){
            if(load+weights[i]>mid){
                days++;
                load=weights[i];
            }
            else{
                load+=weights[i];
            }
        }

        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int i=*max_element(weights.begin(),weights.end());
        int j=accumulate(weights.begin(),weights.end(),0);
        int result;
        while(i<=j){
            int mid=(i+j)/2;
            int mindays=findays(mid,weights);
            if(mindays<=days){
                result=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
return result;
    }
};