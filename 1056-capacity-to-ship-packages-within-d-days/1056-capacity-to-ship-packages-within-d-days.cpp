class Solution {
public:
    int findays(vector<int>&weights,int mid){
        int load=0,days=1;
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
        int i=*max_element(weights.begin(),weights.end()),j=accumulate(weights.begin(),weights.end(),0);
        int ans=-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(findays(weights,mid)<=days){
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