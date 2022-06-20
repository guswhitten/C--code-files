/*
LEETCODE 75 #9

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> result;
	if (nums.empty()) {
		return result;
	}
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); ++i) {
		// all numbers from now on will be greater than 0, no point in continuing
		if (nums[i] > 0) break;

		// we have seen this number & combo before; skip
		if (i > 0 and nums[i] == nums[i-1]) continue;

		int left = i+1, right = nums.size() - 1;
		while (left < right) {
			int sum = nums[i] + nums[left] + nums[right];
			if (sum < 0) {
				++left;
			} else if (sum > 0) {
				--right;
			} else {
				result.push_back({nums[i], nums[left], nums[right]});
				int last_left = nums[left], last_right = nums[right];
				// we have seen this number & combo before; skip
				while (left < right && nums[left] == last_left) ++left;
				while (left < right && nums[right] == last_right) --right;
			}
		}

	}
	return result;
}
};

/*
133ms
19.9MB
*/
