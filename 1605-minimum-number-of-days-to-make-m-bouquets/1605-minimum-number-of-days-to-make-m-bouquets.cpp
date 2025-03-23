class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
       
        int i=0,j=1e9;
      
        int ans=-1;
        while(i<=j){
            int conlen=0,bouqets=0;
            int mid=(i+j)/2;
            for(int bloomindex=0;bloomindex<bloomDay.size();bloomindex++){
                if(bloomDay[bloomindex]<=mid){
                    conlen++;
                    if(conlen==k){
                        conlen=0;
                        bouqets++;
                    }
                }
                else{
                    conlen=0;
                }
            }
            if(bouqets>=m){
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