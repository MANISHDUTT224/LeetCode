class Solution {
    void permute(int[]nums,int l,int r,List<List<Integer>>res){
        if(l==r){
            List<Integer> list = Arrays.stream(nums).boxed().collect(Collectors.toList());
            res.add(list);
            return;
        }
        for(int i=l;i<=r;i++){
            swap(nums,l,i);
            permute(nums,l+1,r,res);
            swap(nums,l,i);
        }
    }
    void swap(int []nums,int l,int r){
        int temp=nums[l];
        nums[l]=nums[r];
        nums[r]=temp;
    }
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>>res=new ArrayList<>();
        permute(nums,0,nums.length-1,res);
        return res;
    }
}