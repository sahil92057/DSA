#include <iostream>
#include <vector>

using namespace std;

void backtrack(int start, vector<int>& nums, vector<int>& path, vector<vector<int>>& result) {
    result.push_back(path);
    for (int i = start; i < nums.size(); ++i) {
        path.push_back(nums[i]);
        backtrack(i + 1, nums, path, result);
        path.pop_back();
    }
}

vector<vector<int>> generateSubsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> path;
    backtrack(0, nums, path, result);
    return result;
}


int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> subsets = generateSubsets(nums);/'/////''//'                                            

    for (const auto& subset : subsets) {
        cout << "[";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
