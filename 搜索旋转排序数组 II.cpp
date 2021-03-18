class Solution {
public:
  int search_helper(vector<int> &nums, int target, int left, int right) {
    while (left <= right) {
      int mid = left + (right-left)/2;
      if (nums[mid] < target) {
        left = mid + 1;
      } else if (nums[mid] > target) {
        right = mid - 1;
      } else {
        return mid;
      }
    }
    return -1;
  }

  int search(vector<int>& nums, int target) {
    int left = 0, right = 0;
    for (int i = 0; i < nums.size()-1; ++i) {
      if (nums[i] > nums[i+1]) {
        right = i;
        break;
      }
    }
    int res1 = search_helper(nums, target, left, right);
    if (res1 != -1) {
      return true;
    } else {
      int res2 = search_helper(nums, target, right + 1, nums.size() - 1);
      return res2 != -1;
    }
  }
};

