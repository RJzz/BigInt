#pragma once
#ifndef NODE_H_
#define NODE_H_
class Node {
public:
	Node();
	~Node();
	void set_data(int i);		
	int get_data();		
	Node *next;
	Node *prior;
private:
	int data;		//�ڵ��������
};



#endif NODE_H_
