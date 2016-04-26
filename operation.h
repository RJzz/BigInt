#pragma once
#ifndef OPERATION_H_
#define OPERATION_H_
#include "linklist.h"
class Operation {
public:
	Operation();
	~Operation();
	void Add();
	void AddForMul(LinkList a, LinkList b);
	void SubForDiv(LinkList a, LinkList b);
	void Sub();
	void Compare(LinkList first, LinkList second);
	bool CompareForDiv(LinkList a, LinkList b);
	void Multiply(LinkList first, LinkList second,int c);
	void Division(LinkList first, LinkList second);
	void Involution(LinkList a, int n);
	void set_equal(int i);
	int get_equal();
	LinkList get_divisionlist();
	void set_carry(int i);
	int get_carry();
	void set_borrow(int i);
	int get_borrow();
	void set_divide(string s);
	string get_divide();
	void Output();

	string addCommoa(string s);
	string deleteCommoa(string s);
	string clearZero(string s);
	string addZero(string s);
	int covertToInt(string s);
	string converToString(int i);
private:
	string divide;				//除法链
	int borrow;					//借位
	int carry;					//进位
	int equal;					//标记两个符号不等的链表绝对值是否相等,1表示相等，0表示不等
	LinkList *answer;			//结果链表
	LinkList firstData;			//被操作的链表对象，例如被加数，被减数
	LinkList secondData;		//操作的链表对象，加数，减数等
	LinkList divisionList;		//被除的链
};


#endif // !OPERATION_H_