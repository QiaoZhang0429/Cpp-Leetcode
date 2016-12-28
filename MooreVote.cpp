class Solution {
public:
    int majorityElement(vector<int>& nums) {//Moore's vote
        int candidate = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(count > 0 && nums[i] == candidate)
                count++;
            else{
                if(count == 0){
                    count++;
                    candidate = nums[i];
                }
                else
                    count--;
            }
        }
        return candidate;
    }
};

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1, candidate2;
        int count1 = 0, count2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(count1 > 0 && nums[i] == candidate1)
                count1++;
            else if(count2 > 0 && nums[i] == candidate2)
                count2++;
            else{
                if(count1 == 0){
                    count1++;
                    candidate1 = nums[i];
                }
                else if(count2 == 0){
                    count2++;
                    candidate2 = nums[i];
                }
                else{
                    count1--;
                    count2--;
                }
            }
        }
        count1 = count2 = 0;
        for(auto n:nums){
            if(candidate1 == n)
                count1++;
            if(candidate2 == n)
                count2++;
        }
        vector<int> rslt;
        if(count1 > (nums.size() / 3)){
            rslt.push_back(candidate1);
        }
        if(count2 > (nums.size() / 3) && candidate1 != candidate2){
            rslt.push_back(candidate2);
        }
        return rslt;
    }
};

//vote for itself if candidate is valid and it is candidate
//try to become the candidate if vacant
//down vote otherwise