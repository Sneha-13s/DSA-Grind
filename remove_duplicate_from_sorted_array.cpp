class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int i=0;
        for(int j=0;j<nums.size();j++){
            if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};

it is said that 
inplace means we have to make the changes int the given vector
non-decreasing - it means increasing but in that vector there may be elements constant or duplicates numbers 

so what we are doing using two pointer approach i and j starting with i = 0 and j = 1 we are checking whether the values are equal or not and 
if not then first increase the i and then swap the elements 
at last return i+1 so it will be the final value 

mm
