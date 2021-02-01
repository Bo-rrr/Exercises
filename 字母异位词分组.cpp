class Solution {
public:
    vector<vector<string>> ret;
    string temp;
    vector<string> ans;
    multimap<string, string> map;
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        for (int i = 0; i < strs.size(); ++i)
        {
            temp = strs[i];
            sort(temp.begin(), temp.end());
            map.insert({ temp,strs[i] });
        }
        temp.clear();
        for (auto it : map)
        {
            if (temp == it.first)/*key相同的value在multimap中将会
被顺序排序，因此记录上一个的key，并比较，相同则是同一个解，不同则
已经遍历完所有的key,保存结果即可*/
                ans.push_back(it.second);
            else
            {
                if (!ans.empty())   
                    ret.push_back(ans);
                temp = it.first;
                ans.clear();
                ans.push_back(it.second);
            }
        }
        if (!ans.empty())
            ret.push_back(ans);
        return ret;
    }
};
