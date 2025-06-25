class Solution {
public:
    void merge(vector<int>&nums,int low,int mid,int high){
        int i=low,j=mid+1;
        vector<int>temp;
        while(i<=mid && j<=high){
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
        while(j<=high){
            temp.push_back(nums[j]);
            j++;
        }
        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }
    }
    int countpairs(vector<int>&nums,int low,int mid,int high){
        int j=mid+1;
        int count=0;
        for(int i=low;i<=mid;i++){
            while(j<=high && (long long)nums[i]>(long long)2*nums[j]){
                j++;
            }
            count+=(j-(mid+1));
        }
        return count;
    }
    int mergesort(vector<int>&nums,int low,int high){
        int cnt=0;
        if(low>=high){
            return cnt;
        }
        int mid=(low+high)/2;
        cnt+=mergesort(nums,low,mid);
        cnt+=mergesort(nums,mid+1,high);
        cnt+=countpairs(nums,low,mid,high);
        merge(nums,low,mid,high);
        return cnt;

    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size(),cnt;
         cnt=mergesort(nums,0,n-1);
        return cnt;
    }
};