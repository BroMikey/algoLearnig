#include<iostream>
#include<stack>
#include <stdexcept>

using namespace std;

int main()
{
	/*栈的常用操作*/

	/*初始化栈*/
	stack<int> stack;

	/*元素入栈*/
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);

	/*访问栈顶元素*/
	int top = stack.top();

	/*元素出栈*/
	stack.pop();

	/*获取栈的长度*/
	int size = stack.size();

	/*判断是否为空*/
	bool empty = stack.empty();

	return 0;
}


/*基于链表的栈实现*/
class LinkListStack
{
private:
	LinkListStack* stackTop;//栈的头节点作为栈顶,指向下一节点
	int stackSize;//栈的长度

public:
	/*构造函数*/
	LinkListStack()
	{
		stackTop = nullptr;
		stackSize = 0;
	}

	/*析构函数*/
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










