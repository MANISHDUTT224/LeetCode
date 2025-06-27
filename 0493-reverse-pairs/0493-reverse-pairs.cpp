class Solution {
public:
    void merge(vector<int>&nums,int l,int mid,int r){
        int i=l,j=mid+1;
        vector<int>temp;
        while(i<=mid && j<=r){
            if(nums[i]<=nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=r){
            temp.push_back(nums[j]);
            j++;
        }
        
        for(int i=l;i<=r;i++){
            nums[i]=temp[i-l];
        }
    }
    int countpairs(vector<int>&nums,int l,int mid,int r){
        int j=mid+1;
        int cnt=0;
        for(int i=l;i<=mid;i++){
            while(j<=r && (long long)nums[i]>(long long)nums[j]*2){
                j++;
            }
            cnt+=(j-(mid+1));
        }
        return cnt;
    }
    int mergesort(vector<int>&nums,int l,int r){
        int cnt=0;
        if(l>=r){
            return cnt;
        }
        
        int mid=(l+r)/2;
        cnt+=mergesort(nums,l,mid);
        cnt+=mergesort(nums,mid+1,r);
        cnt+=countpairs(nums,l,mid,r);
        merge(nums,l,mid,r);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size(),cnt;
        cnt=mergesort(nums,0,n-1);
        return cnt;
    }
};