#include<iostream>
#include<stack>
#include <stdexcept>

using namespace std;

int main()
{
	/*ջ�ĳ��ò���*/

	/*��ʼ��ջ*/
	stack<int> stack;

	/*Ԫ����ջ*/
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);

	/*����ջ��Ԫ��*/
	int top = stack.top();

	/*Ԫ�س�ջ*/
	stack.pop();

	/*��ȡջ�ĳ���*/
	int size = stack.size();

	/*�ж��Ƿ�Ϊ��*/
	bool empty = stack.empty();

	return 0;
}


/*���������ջʵ��*/
class LinkListStack
{
private:
	LinkListStack* stackTop;//ջ��ͷ�ڵ���Ϊջ��,ָ����һ�ڵ�
	int stackSize;//ջ�ĳ���

public:
	/*���캯��*/
	LinkListStack()
	{
		stackTop = nullptr;
		stackSize = 0;
	}

	/*��������*/
	~LinkListStack()
	{
		while (stackTop != nullptr)
		{
			LinkListStack* next = stackTop->stackTop;
			delete stackTop;
			stackTop = next;
		}
		
		
	}


};

void freeMemoryLinkedList(LinkListStack* stacktop)
{
	

}










