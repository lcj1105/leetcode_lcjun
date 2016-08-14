class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index1 = 0;
        int index2 = 0;
        int length = nums.size();
        while(index1 < length){
        	if( nums[index1] != 0 ){
        		if(index1 != index2){
        			nums[index2++] = nums[index1];
        			nums[index1] = 0;
        		}
        		else
        			++index2;
        	}
        	++index1;
        }
    }
};
