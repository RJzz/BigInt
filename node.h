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
	int data;		//节点的数据域
};



#endif NODE_H_
