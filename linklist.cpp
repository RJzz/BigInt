#include "linklist.h"
//初始化链表
void LinkList::Init() {
	//构造循环链表的头节点
	if (head == nullptr) {
		head = new Node();
		head->next = head;
		head->prior = head;
	}
	int i = 0;
	int number = 0;		//number用于保存每一次获取到需要保存到节点里面的值

						//如果第一个字符为-则将链表对象标记为负数
	if (link[i] == '-') {
		symbol = 0;
		i++;
	} else {
		symbol = 1;
	}
	while (i < link.size()) {
		number = 0;
		if (link[i] == ',') {
			i++;
		}
		while (link[i] != ',') {

			//这里用一个字符减去'0'将字符转化为整数，因为字符和数字的ASCII码差了48
			number = number * 10 + link[i] - '0';
			length++;
			i++;
			if (i == link.size()) {
				break;
			}
		}

		InsertNode(number);



		//if (i == data.size() - 1 && symbol == 0) {
		//	InsertNode(number);
		//	break;
		//} else if (i == data.size() - 2 && symbol == 1) {
		//	InsertNode(number);
		//	break;
		//}


	}
}
LinkList::LinkList(string data) {
	link = data;

}

//获取到链表的字符串形式
string LinkList::get_link() {
	return link;
}

//设置
void LinkList::set_link(string data) {
	link = data;
}
//插入节点
void LinkList::InsertNode(int data) {
	Node *p = new Node();
	p->set_data(data);

	//采用先右后左的方法插入节点至头节点之后
	p->next = head->next;
	head->next->prior = p;
	head->next = p;
	p->prior = head;
	node_number++;

}
//默认构造函数
LinkList::LinkList() {
	//构造循环链表的头节点
	head = new Node();
	head->next = head;
	head->prior = head;
}

//默认析构函数
LinkList::~LinkList() {
}

//获取链表的长度
int LinkList::get_length() {
	return length;
}

//设置链表的长度
void LinkList::set_length(int i) {
	length = i;
}

//获取链表节点数量
int LinkList::get_node_number() {
	return node_number;
}

//设置链表节点数量
void LinkList::set_node_number(int i) {
	node_number = i;
}

//获取链表的标志符号
int LinkList::get_symbol() {
	return symbol;
}

//设置链表的标志符号
void LinkList::set_symbol(int i) {
	symbol = i;
}

//获得头节点的地址
Node* LinkList::get_head() {
	return head;
}

//输出链表
void LinkList::Output() {
	cout << link << endl;

}