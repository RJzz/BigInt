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
	int length;			//�������洢���ݵĳ���
	int node_number;	//����ڵ������
	int symbol;			//���������ű��,0��ʾ������1��ʾ����
	Node *head;			//ͷ�ڵ�
	string link;		//������ַ�����ʽ
};


#endif // !LINK_LIST_H_