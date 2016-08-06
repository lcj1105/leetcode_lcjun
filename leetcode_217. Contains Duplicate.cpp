class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        if(nums.empty() || nums.size() == 1)
            return false;
        
        map<int,int> timesOfNum;
        for(auto val: nums){
            ++timesOfNum[val];
        }
        for(auto &t : timesOfNum){
            if(t.second >1)
                return true;
        }
        return false;
    }
};


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.empty() || nums.size() == 1)
        return false;
        sort(nums.begin(),nums.end());
        int temp = nums[0];
        for(auto p = nums.begin() +1 ; p!= nums.end();p++){
            if (temp == *p)
                return true;
            temp = *p;
        }
        return false;
    }
};