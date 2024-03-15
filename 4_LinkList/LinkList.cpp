#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//单向链表节点结构体
typedef struct ListNode//struct结构体，再使用typedef
{
	int val;
	struct ListNode* next;
}LinkNode;
//构造单向链表的函数
ListNode* newListNode(int val)
{
	ListNode* node;/*一个结构体指针，用来存放下面的空间
	如果没有typedef要使用struct LinkNode*/
	node = (ListNode*)malloc(sizeof(ListNode));//分配一个结构体空间
	node->val = val;
	node->next = NULL;
	return node;//该指针指向新创建的链表节点
}
/*
//双向链表节点结构体
typedef struct ListNode
{
	int val;			  //节点值
	struct LinkNode* next;//指向后节点的指针
	struct LinkNode* prev;//指向前节点的指针
};

//双向链表构造函数
LinkNode* newListNode(int val)
{
	ListNode* node;
	node = (LinkNode*)malloc(sizeof(LinkNode));
	node->val = val;
	node->next = NULL;
	node->prev = NULL;
	return node;
}
*/



//插入节点
void insert(ListNode* n0, ListNode* p)
{
	ListNode* n1 = n0->next;
	n0->next = p;
}

//删除节点
/*删除n0节点后的第一个节点*/
void remove(ListNode* n0)
{
	if (!n0->next)
		return;//如果该节点为最后的节点，则不删除
	ListNode* p = n0->next;
	ListNode* n1 = p->next;
	n0->next = n1;
	//释放内存
	free(p);
}

//查找节点
/*查找链表中值为target的首个节点*/
int find(ListNode* head, int target)
{
	int index = 0;
	while (head)
	{
		if (head->val == target)
			return index;
		head = head->next;
		index++;
	}
	return -1;
}




int main()
{
	//初始化各个节点
	LinkNode* n0 = newListNode(1);
	LinkNode* n1 = newListNode(3);
	LinkNode* n2 = newListNode(2);
	LinkNode* n3 = newListNode(5);
	LinkNode* n4 = newListNode(4);
	//构建结点之间的引用
	n0->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;

	return 0;
}


