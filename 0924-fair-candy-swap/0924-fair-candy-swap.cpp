class Solution {
public:
    bool bs(vector<int>&arr,int target){
        int i=0,j=arr.size()-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(arr[mid]==target){
                return true;
            }
            else if(arr[mid]>target){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return false;
    }
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int at=0,bt=0;
        for(int a:aliceSizes){
            at+=a;
        }
        for(int b:bobSizes){
            bt+=b;
        }
        sort(bobSizes.begin(),bobSizes.end());
        int m=aliceSizes.size(),n=bobSizes.size();
        for(int i=0;i<m;i++){
            int target=(bt-at+2*aliceSizes[i])/2;
            if(bs(bobSizes,target)){
                return {aliceSizes[i],target};
            }

        }
        return {};
    }
};