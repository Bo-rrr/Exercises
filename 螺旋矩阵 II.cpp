class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));//开辟二维数组
        int loop = n/2;//每个圈循环几次，例如n为奇数3 那么loop=1，只循环一圈，矩阵中间的值需要特殊处理
        int mid = n/2;//矩阵中间的位置，例如：n为3，中间的位置就是（1,1），n为5，中间的位置就是（2,2）
        int startx = 0;//定义每一圈的起始位置
        int starty = 0;
        int count = 1;//用来矩阵中每一个方格赋值
        int offset = 1;//每一圈循环，需要控制每一条边的遍历的长度
        int i,j;
        while(loop--)
        {
            i = startx;
            j = starty;
            //四个for循环一圈
            //左闭右开
            for(j = starty; j < starty + n - offset; j++)
            {
                res[i][j] = count++ ;
            }
            //上闭下开
            for(i = startx; i < startx + n - offset; i++)
            {
                res[i][j] = count++ ;
            }
            //右闭左开
            for(; j > starty; j--)
            {
                res[i][j] = count++ ;
            }
            //下闭上开
            for(; i > startx; i--)
            {
                res[i][j] = count++;
            }
            //第二圈开始的时候，起始位置要各自+1， 例如第一圈起始位置是（0,0），第二圈起始位置是（1,1）
            startx++;
            starty++;
            //offset 控制每一圈里每一条边遍历的长度
            offset += 2;
        }
        //如果n为奇数的话，需要单独给矩阵最中间的位置赋值
        if(n%2)
        {
            res[mid][mid] = count;
        }
        return res;
    }
};
