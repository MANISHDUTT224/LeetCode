class Solution {
public:
bool isNonDecreasing(const vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] > nums[i+1]) {
                return false;
            }
        }
        return true;
    }
    
    int findMinPair(const vector<int>& nums) {
        int minSum = nums[0] + nums[1];
        int minIndex = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            int currentSum = nums[i] + nums[i+1];
            if (currentSum < minSum) {
                minSum = currentSum;
                minIndex = i;
            }
        }
        return minIndex;
    }
 int minimumPairRemoval(vector<int>& nums) {
    int count = 0;
        while (!isNonDecreasing(nums)) {
            int minPairIndex = findMinPair(nums);
            vector<int> mergedArray;
            for (int j = 0; j < nums.size(); ++j) {
                if (j == minPairIndex) {
                    mergedArray.push_back(nums[j] + nums[j+1]);
                    j++; // Skip the next element as it's merged
                } else {
                    mergedArray.push_back(nums[j]);
                }
            }
            nums = mergedArray;
            count++;
        }
        return count;
 }
 };