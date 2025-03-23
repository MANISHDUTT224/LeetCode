class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int l=1,r=1e9,ans=-1;
        while(l<=r){
            int conlen=0,bouqets=0;
            int mid=l+(r-l)/2;
            for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
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
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return ans;
    }
};