class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> shortSets;
        set<int> intersection;
        vector<int> results;
        if(nums1.size() > nums2.size()){
        	vector<int> temp = nums1;
        	nums1 = nums2;
        	nums2 = temp;
        }
        for(auto p = nums1.begin() ; p != nums1.end() ; p++ )
        	shortSets.insert(*p);
        for(auto p = nums2.begin() ; p != nums2.end() ; p++ ){
        	if(shortSets.count(*p) > 0 )
        		intersection.insert(*p);
        }
        for(auto p = intersection.begin(); p != intersection.end(); p++)
        	results.push_back(*p);
        return results;
    }
};

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

