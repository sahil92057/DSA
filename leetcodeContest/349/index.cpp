// link -->> https://leetcode.com/contest/weekly-contest-439/problems/find-the-largest-almost-missing-integer/
class Solution {
    public:
        int largestInteger(vector<int>& nums, int k) {
            int n = nums.size();
            unordered_map<int, int>mpp;
            int largest=-1;
            for(int i =0; i<n-k+1; i++){
                set<int>hs;
                for(int j =i;j <i+k; j++){
                    if(hs.find(nums[j])==hs.end()){
                        mpp[nums[j]]++;
                        hs.insert(nums[j]);
                    }
                }
            }
            for(auto it :mpp){
                if(it.second==1){
                    largest= max(largest, it.first);   
                }
            }
            return largest;
        }
    };