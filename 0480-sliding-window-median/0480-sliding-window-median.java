class MedianFinder{
    record E(long num,long index){}
    TreeSet<E>left,right;
    public MedianFinder(){
        left=new TreeSet<E>(Comparator.comparing(E::num).reversed().thenComparing(E::index));
        right=new TreeSet<E>(Comparator.comparing(E::num).thenComparing(E::index));

    }
    public void add(long val,int index){
        if(left.size()==right.size()){
            left.add(new E(val,index));
            right.add(left.pollFirst());
        }
        else{
            right.add(new E(val,index));
            left.add(right.pollFirst());
        }
    }
    public void remove(long val,int index){
        if(!left.remove(new E(val,index))){
            right.remove(new E(val,index));
        }
        if(left.size()>right.size()){
            right.add(left.pollFirst());
        }
        else if(right.size()>left.size()+1){
            left.add(right.pollFirst());
        }
    }
    public double findMedian(){
        if(left.size()==right.size()){
            return (left.first().num+right.first().num)/2.0;
        }
        else{
            return right.first().num;
        }
    }
}
class Solution {

    public double[] medianSlidingWindow(int[] nums, int k) {
        int n=nums.length;
        double result[]=new double[n-k+1];
        MedianFinder nf=new MedianFinder();
        for(int i=0;i<k;i++){
            nf.add(nums[i],i);
        }
        result[0]=nf.findMedian();
        for(int i=1;i<=n-k;i++){
            nf.remove(nums[i-1],i-1);
            nf.add(nums[i+k-1],i+k-1);
            result[i]=nf.findMedian();
        }
        return result;
    }
}