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
//�����㷨��� 
void backtrack(State* state, vector<Choice*>& choices, vector<State*>& res) {
    // �ж��Ƿ�Ϊ��
    if (isSolution(state)) {
        // ��¼��
        recordSolution(state, res);
        // ���ټ�������
        return;
    }
    // ��������ѡ��
    for (Choice choice : choices) {
        // ��֦���ж�ѡ���Ƿ�Ϸ�
        if (isValid(state, choice)) {
            // ���ԣ�����ѡ�񣬸���״̬
            makeChoice(state, choice);
            backtrack(state, choices, res);
            // ���ˣ�����ѡ�񣬻ָ���֮ǰ��״̬
            undoChoice(state, choice);
        }
    }
}
*/

//�ж��Ƿ�Ϊ��
bool IsSolution(vector<TreeNode*> &state)
{
    return !state.empty() && state.back()->value == 7;
}

//��¼��
void RecordSolution(vector<TreeNode*> &state, vector<vector<TreeNode *>>res)
{
    res.push_back(state);
}

//�жϽ��Ƿ�Ϸ�/��֦
bool IsValid(vector<TreeNode*>& state, TreeNode *choice)
{
    return choice != nullptr && choice->value != 3;
}

//����״̬
void MakeChoice(vector<TreeNode *>& state, TreeNode* choice)
{
    state.push_back(choice);
}

//�ָ�״̬
void UndoChoice(vector<TreeNode*>& state, TreeNode* choice)
{
    state.pop_back();
}

void backtrack(vector<TreeNode*>& state, vector<TreeNode*>& choices, vector<vector<TreeNode*>>& res) {
    // ����Ƿ�Ϊ��
    if (IsSolution(state)) {
        // ��¼��
        RecordSolution(state, res);
    }
    // ��������ѡ��
    for (TreeNode* choice : choices) {
        // ��֦�����ѡ���Ƿ�Ϸ�
        if (IsValid(state, choice)) {
            // ���ԣ�����ѡ�񣬸���״̬
            MakeChoice(state, choice);
            // ������һ��ѡ��
            vector<TreeNode*> nextChoices{ choice->left, choice->right };
            backtrack(state, nextChoices, res);
            // ���ˣ�����ѡ�񣬻ָ���֮ǰ��״̬
            UndoChoice(state, choice);
        }
    }
}

/*���������ظ�����ʱ�Ļ���*/
void BackTrack1(vector<int>& state, const vector<int>& choice, vector<bool>& selected, vector<vector<int>>& res)
{
    //�ж��Ƿ�ݹ鵽�,�ʱ��¼��
    if (state.size() == choice.size())
    {
        res.push_back(state);
        return;
    }

    //��������ѡ��
    for (int i = 0; i < choice.size(); i++)
    {
        //�жϸý��Ƿ�Ϸ�
        if (!selected[i])
        {
            //�Ϸ���¼�õ�
            selected[i] = true;
            state.push_back(choice[i]);
            //������һ��ѡ��
            BackTrack1(state, choice, selected, res);
            //������һ��ѡ��
            selected[i] = false;
            state.pop_back();
        }
    }
}

/*�������г����ظ�����ʱ*/
void BackTrack2(vector<int>& state, vector<int>& choice, vector<bool> selected, vector<vector<int>>& res)
{
    if (state.size() == choice.size())
    {
        //�������ʱ��¼��
        res.push_back(state);
        return;
    }

    //���������е��ظ�����
    unordered_set<int> duplicated;
    for (int i = 0; i < choice.size(); i++)
    {
        if (!selected[i] && duplicated.find(choice[i]) == duplicated.end())
        {
            //��֦�����
            selected[i] = true;
            state.push_back(choice[i]);

            //������һ��ѡ��
            BackTrack2(state, choice, selected, res);

            //������һ��
            state.pop_back();
            selected[i] = false;
        }
    }

}


















int main()
{




	return 0;
}