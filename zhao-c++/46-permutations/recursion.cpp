#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> res{};

void concat(vector<int> &head, vector<int> &tail);

vector<vector<int>> permute(vector<int> &nums);

int main()
{
    vector<int> a{1, 2, 3, 4};
    permute(a);
    for (auto i : res)
    {
        cout << "[";

        for (auto j : i)
        {
            if (j != *(i.end() - 1))
            {
                cout << j << ", ";
            }
            else
            {
                cout << j;
            }
        }
        cout << "]" << endl;
    }
    return 0;
}

void concat(vector<int> &head, vector<int> &tail)
{
    if (tail.size() == 1)
    {
        head.emplace_back(tail[0]);
        res.emplace_back(head);
    }
    else
    {
        for (int i = 0; i < tail.size(); ++i)
        {
            auto tmpHead{head};
            tmpHead.emplace_back(tail[i]);
            auto tmpTail{tail};
            tmpTail.erase(tmpTail.begin() + i);
            concat(tmpHead, tmpTail);
        }
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<int> head{};
    concat(head, nums);
    return res;
}
