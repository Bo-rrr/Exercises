map<int, set<vector<int> > > dpkv;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int> > avectorset;
        // 初始化
        for(int i = 1; i <= target; i++){
            dpkv[i] = avectorset; // 都赋值成一个空的数组
        }
        // 开始递推
        
        for(int j = 1; j <= target; j++){
            for(vector<int>::iterator it = candidates.begin(); it != candidates.end(); it++){
                if(j == *it){
                    // 直接作为一个vector<int>加入
                    vector<int> v_only_one_num;
                    v_only_one_num.push_back(j);
                    dpkv[j].insert(v_only_one_num);
                } else if(j > *it){ // 用dp[j - *it] 作为结果
                    // 遍历dp[j - *it]
                    for(set<vector<int> >::iterator its = dpkv[j - *it].begin(); its != dpkv[j - *it].end(); its++){
                        vector<int> the_vector = (*its);
                        the_vector.push_back(*it);
                        sort(the_vector.begin(), the_vector.end());
                        dpkv[j].insert(the_vector);
                    }
                }
            }
        }
        // 将set加工成vector
        vector<vector<int>> target_v;
        for(set<vector<int> >::iterator its = dpkv[target].begin(); its != dpkv[target].end(); its++){
            target_v.push_back(*its);
        }
            
        return target_v;
    }
};
