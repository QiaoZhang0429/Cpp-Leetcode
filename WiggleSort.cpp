class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++)
            if(((i & 1) && nums[i] < nums[i-1]) || (!(i & 1) && nums[i] > nums[i-1]))
                swap(nums[i], nums[i-1]);
    }
};
//proof:induction
//if 0,...,i suffices to wiggle sort, (i,i+1) does not wiggle, swap them does not ruin (i-1,i)

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int middle = (nums.size() + 1) / 2;
        vector<int> n1(nums.begin(), nums.begin()+middle);
        vector<int> n2(nums.begin()+middle, nums.end());
        int j = n1.size()-1, k = n2.size()-1;
        for(int i = 0; i < nums.size(); i++){
            if(i & 1)
                nums[i] = n2[k--];
            else
                nums[i] = n1[j--];
        }
    }
};
//[4,5,5,6] corner case