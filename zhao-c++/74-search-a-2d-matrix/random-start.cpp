#include <iostream>
#include <vector>
#include <random>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {


        vector<int> firstColumn;
        for(auto vec: matrix)
        {
            firstColumn.emplace_back(vec[0]);
        }
        int row = findBiggestSmall(firstColumn, 0, firstColumn.size(), target);
        int result = findBiggestSmall(matrix[row], 0, matrix[row].size(), target);
        return (result == target);
    }

    int findBiggestSmall(vector<int> rowOrColumn, int startPosition, int endPosition, int target)
    {
        if (startPosition == endPosition)
        {
           return startPosition;
        }
        else if (startPosition + 1 == endPosition) 
        {
           if (target == rowOrColumn[endPosition])
           {
               return endPosition;
           }
           else
           {
               return startPosition;
           }
        }
        int halfPosition = (endPosition + startPosition) / 2;
        if (rowOrColumn[halfPosition] == target)
        {
            return halfPosition;
        }
        else if (rowOrColumn[halfPosition] > target)
        {
            findBiggestSmall(rowOrColumn, startPosition, halfPosition, target);
        }
        else
        {
            findBiggestSmall(rowOrColumn, halfPosition, endPosition, target);
        }
    }

};

int main()
{

    vector<vector<int>> matrix{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 3;
    Solution solution;
    cout << " " << solution.searchMatrix(matrix, target);
    return 0;
}
