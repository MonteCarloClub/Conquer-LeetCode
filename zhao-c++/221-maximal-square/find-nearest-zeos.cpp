#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
//最大正方形的边长
int maximalLength = 0;
//最大正方形的左上角坐标
pair<int, int> oneAix;
//最大长方形的右下角坐标
pair<int, int> zeroAix;

/**
 * @brief 给定一个点，更新以这个点为左上角坐标的最大正方形
 * 
 * @param m 点所在行序号
 * @param n 点所在列序号
 * @param longest 能构成正方形的最长边长
 * @param matrix 所使用矩阵
 */
void update(const int m, const int n, const int longest, vector<vector<char>> &matrix)
{

    //向该点的右下方寻找正方形，如果遇到0则更新正方形的信息并返回
    for (int i = 1; i < longest; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (matrix[m + j][n + i] == '0' || matrix[m + i][n + j] == '0')
            {
                maximalLength = max(maximalLength, i);
                oneAix = make_pair(m, n);
                zeroAix = make_pair(m + i - 1, n + i - 1);
                return;
            }
        }
    }

    //如果没有找到0，则右下方到矩阵边界构成正方形，更新正方形信息
    maximalLength = max(maximalLength, longest);
    oneAix = make_pair(m, n);
    zeroAix = make_pair(m + longest, n + longest);
}

int maximalSquare(vector<vector<char>> &matrix)
{
    int column = matrix.size();
    int row = matrix[0].size();

    //遍历矩阵中的每格
    for (int m = 0; m < column; ++m)
    {
        for (int n = 0; n < row; ++n)
        {
            //如果在已经找到的最大的正方形内部，则跳过这步
            if (m != 0 && n != 0 && m > oneAix.first && m <= zeroAix.first && n > oneAix.second && n <= zeroAix.second)
            {
                continue;
            }
            //如果已经找到的最长的0距离大于剩余的长或宽则停止继续寻找
            int longest = min(matrix.size() - m, matrix[0].size() - n);
            if (longest < maximalLength)
            {
                break;
            }
            //对于其他的为1的点，更新最大正方形信息
            if (matrix[m][n] == '1')
            {
                update(m, n, longest, matrix);
            }
        }
    }
    return maximalLength * maximalLength;
}

int main()
{
    vector<vector<char>> matrix{{'1'}};
    cout << maximalSquare(matrix);
    return 0;
}