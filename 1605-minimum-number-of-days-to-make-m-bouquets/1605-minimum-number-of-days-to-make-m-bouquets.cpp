class Solution {
public:
    bool possible(vector<int>&arr,int day,int m,int k){
        int conlen=0,bouqets=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=day){
              
                conlen++;
            }
            else{
            
                bouqets+=conlen/k;
                conlen=0;
            
            }
        }
        bouqets+=conlen/k;
        return bouqets>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val=m*1ll*k*1ll;
        int n= bloomDay.size();
        if(val>n){
            return -1;
        }
        int ans=-1;
        int i=*min_element(bloomDay.begin(),bloomDay.end()),j=*max_element(bloomDay.begin(),bloomDay.end());
        while(i<=j){
            int mid=(i+j)/2;
            if(possible(bloomDay,mid,m,k)){    
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return i;
    }
};