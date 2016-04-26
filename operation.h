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
	string divide;				//������
	int borrow;					//��λ
	int carry;					//��λ
	int equal;					//����������Ų��ȵ��������ֵ�Ƿ����,1��ʾ��ȣ�0��ʾ����
	LinkList *answer;			//�������
	LinkList firstData;			//������������������类������������
	LinkList secondData;		//������������󣬼�����������
	LinkList divisionList;		//��������
};


#endif // !OPERATION_H_