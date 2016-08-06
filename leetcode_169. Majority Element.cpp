class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        map<int,int> TimesOfNum;
        for(auto val: nums)
            TimesOfNum[val]++;
        for(auto &t : TimesOfNum){
            if(t.second > nums.size()/2)
                return t.first;
        }
        return 0;
    }
};