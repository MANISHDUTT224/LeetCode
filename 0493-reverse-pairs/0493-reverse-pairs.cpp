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
    int countpairs(vector<int>&nums,int i,int mid,int j){
        int k=mid+1;
        int count=0;
        for(int l=i;l<=mid;l++){
            while(k<=j && (long long)nums[l]>(long long)2*nums[k]){
                k++;
            }
            count+=(k-(mid+1));
        }
        
        return count;
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