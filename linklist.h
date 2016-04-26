#pragma once
#ifndef LINK_LIST_H_
#define LINK_LIST_H_
#include "Node.h"
#include <string>
#include <iostream>
using namespace std;
class LinkList {
public:
	LinkList(string data);
	LinkList();
	~LinkList();

	int get_length();
	void set_length(int i);

	int get_node_number();
	void set_node_number(int i);

	int get_symbol();
	void set_symbol(int i);

	Node* get_head();
	void InsertNode(int data);
	void Output();
	void Init();

	string get_link();
	void set_link(string data);

private:
	int length;			//链表所存储数据的长度
	int node_number;	//链表节点的数量
	int symbol;			//正负数符号标记,0表示负数，1表示正数
	Node *head;			//头节点
	string link;		//链表的字符串形式
};


#endif // !LINK_LIST_H_