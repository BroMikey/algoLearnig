#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>

using namespace std;

typedef struct TreeNode
{
	int value;
	TreeNode* left;
	TreeNode* right;
}TreeNode;

struct TreeNode Tree;
list<int> path;
list<list<int>> res;

void PreOrder(TreeNode* root)
{
	if (root == nullptr)
	{
		return;
	}
	path.push_back(root->value);
	if (root->value == 7)
	{
		res.push_back(path);
	}
	PreOrder(root->left);
	PreOrder(root->right);
}


/*
//回溯算法框架 
void backtrack(State* state, vector<Choice*>& choices, vector<State*>& res) {
    // 判断是否为解
    if (isSolution(state)) {
        // 记录解
        recordSolution(state, res);
        // 不再继续搜索
        return;
    }
    // 遍历所有选择
    for (Choice choice : choices) {
        // 剪枝：判断选择是否合法
        if (isValid(state, choice)) {
            // 尝试：做出选择，更新状态
            makeChoice(state, choice);
            backtrack(state, choices, res);
            // 回退：撤销选择，恢复到之前的状态
            undoChoice(state, choice);
        }
    }
}
*/

//判断是否为解
bool IsSolution(vector<TreeNode*> &state)
{
    return !state.empty() && state.back()->value == 7;
}

//记录解
void RecordSolution(vector<TreeNode*> &state, vector<vector<TreeNode *>>res)
{
    res.push_back(state);
}

//判断解是否合法/剪枝
bool IsValid(vector<TreeNode*>& state, TreeNode *choice)
{
    return choice != nullptr && choice->value != 3;
}

//更新状态
void MakeChoice(vector<TreeNode *>& state, TreeNode* choice)
{
    state.push_back(choice);
}

//恢复状态
void UndoChoice(vector<TreeNode*>& state, TreeNode* choice)
{
    state.pop_back();
}

void backtrack(vector<TreeNode*>& state, vector<TreeNode*>& choices, vector<vector<TreeNode*>>& res) {
    // 检查是否为解
    if (IsSolution(state)) {
        // 记录解
        RecordSolution(state, res);
    }
    // 遍历所有选择
    for (TreeNode* choice : choices) {
        // 剪枝：检查选择是否合法
        if (IsValid(state, choice)) {
            // 尝试：做出选择，更新状态
            MakeChoice(state, choice);
            // 进行下一轮选择
            vector<TreeNode*> nextChoices{ choice->left, choice->right };
            backtrack(state, nextChoices, res);
            // 回退：撤销选择，恢复到之前的状态
            UndoChoice(state, choice);
        }
    }
}

/*数组中无重复数字时的回溯*/
void BackTrack1(vector<int>& state, const vector<int>& choice, vector<bool>& selected, vector<vector<int>>& res)
{
    //判断是否递归到最长,最长时记录解
    if (state.size() == choice.size())
    {
        res.push_back(state);
        return;
    }

    //遍历所有选择
    for (int i = 0; i < choice.size(); i++)
    {
        //判断该解是否合法
        if (!selected[i])
        {
            //合法记录该点
            selected[i] = true;
            state.push_back(choice[i]);
            //进行下一轮选择
            BackTrack1(state, choice, selected, res);
            //撤销上一轮选择
            selected[i] = false;
            state.pop_back();
        }
    }
}

/*当数组中出现重复数字时*/
void BackTrack2(vector<int>& state, vector<int>& choice, vector<bool> selected, vector<vector<int>>& res)
{
    if (state.size() == choice.size())
    {
        //遍历到最长时记录解
        res.push_back(state);
        return;
    }

    //避免数组中的重复数字
    unordered_set<int> duplicated;
    for (int i = 0; i < choice.size(); i++)
    {
        if (!selected[i] && duplicated.find(choice[i]) == duplicated.end())
        {
            //剪枝后存入
            selected[i] = true;
            state.push_back(choice[i]);

            //进行下一轮选择
            BackTrack2(state, choice, selected, res);

            //回溯上一步
            state.pop_back();
            selected[i] = false;
        }
    }

}


















int main()
{




	return 0;
}