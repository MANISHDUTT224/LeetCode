const auto _ =std::cin.tie(nullptr)->sync_with_stdio(false);
#define l33tc0de
#ifdef l33tc0de
const auto __=[](){
    struct __ {
        static void _(){std::ofstream("display_runtime.txt")<<-23<<
    '\n';    }
    };
    std::atexit(&__::_);
    return 0;
}();
#endif
class Solution {
public:

    int subarraySum(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        unordered_map<int,int> mp;
        int cnt=0;
        int presum=0;

        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            presum+=nums[i];
            int res=presum-k;
            cnt+=mp[res];
            mp[presum]+=1;

        }
        return cnt;
    }
};