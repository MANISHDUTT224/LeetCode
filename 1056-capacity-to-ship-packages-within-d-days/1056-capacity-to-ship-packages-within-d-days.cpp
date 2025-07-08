class Solution {
public:
    int findDays(vector<int>&weights,int mid){
        int days=1,load=0;
        for(int i=0;i<weights.size();i++){
            if(load+weights[i]>mid){
                load=weights[i];
                days++;
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
        int ans=-1;
        while(i<=j){
            int mid=(i+j)/2;
            int totaldays=findDays(weights,mid);
            if(totaldays<=days){
                ans=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return ans;
    }
};