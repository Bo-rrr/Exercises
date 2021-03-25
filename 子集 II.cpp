class Solution {
public:
vector<vector<int>> res;
vector<int> tmp;

void dfs(vector<int>& nums, int index) {
    //每次都填入当前结果tmp
    res.emplace_back(tmp);

    for (int j = index; j < nums.size(); j++) {
        //去除重复数字
        if (j > index && nums[j] == nums[j - 1]) {
            continue;
        }
        else {
            tmp.emplace_back(nums[j]);
            dfs(nums, j + 1);
            tmp.pop_back();
        }
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    //去重先排序
    sort(nums.begin(), nums.end());
    dfs(nums, 0);
    return res;
}
};
