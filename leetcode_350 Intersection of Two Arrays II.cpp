
//二、重复保留相同的值
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    	if(nums1.size() == 0 || nums2.size() == 0)
    		return vector<int>();
        unordered_map<int,int> hash_map;
        vector<int> results; 
        for(auto val : nums1) 
        	hash_map[val]++;
        for(auto val : nums2)
        {
        	if( hash_map.count(val) && hash_map[val] > 0 )
        		results.push_back(val);
        	hash_map[val]--;
        }
        return results;
    }
};

