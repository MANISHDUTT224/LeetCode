int findUnsortedSubarray(int* nums, int numsSize) {
    int start=-1,end=-1,maxi=nums[0],mini=nums[numsSize-1];
    for(int i=1;i<numsSize;i++){
        if(maxi<nums[i]){
            maxi=nums[i];
        }
        if(nums[i]<maxi){
            end=i;
        }
    }
    for(int i=numsSize-2;i>=0;i--){
        if(mini>nums[i]){
            mini=nums[i];
        }
        if(nums[i]>mini){
            start=i;
        }
    }
    return (end!=-1 && start!=-1)?(end-start+1):0;
}