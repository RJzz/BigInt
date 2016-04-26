#include "linklist.h"
//��ʼ������
void LinkList::Init() {
	//����ѭ�������ͷ�ڵ�
	if (head == nullptr) {
		head = new Node();
		head->next = head;
		head->prior = head;
	}
	int i = 0;
	int number = 0;		//number���ڱ���ÿһ�λ�ȡ����Ҫ���浽�ڵ������ֵ

						//�����һ���ַ�Ϊ-�����������Ϊ����
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

			//������һ���ַ���ȥ'0'���ַ�ת��Ϊ��������Ϊ�ַ������ֵ�ASCII�����48
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

//��ȡ��������ַ�����ʽ
string LinkList::get_link() {
	return link;
}

//����
void LinkList::set_link(string data) {
	link = data;
}
//����ڵ�
void LinkList::InsertNode(int data) {
	Node *p = new Node();
	p->set_data(data);

	//�������Һ���ķ�������ڵ���ͷ�ڵ�֮��
	p->next = head->next;
	head->next->prior = p;
	head->next = p;
	p->prior = head;
	node_number++;

}
//Ĭ�Ϲ��캯��
LinkList::LinkList() {
	//����ѭ�������ͷ�ڵ�
	head = new Node();
	head->next = head;
	head->prior = head;
}

//Ĭ����������
LinkList::~LinkList() {
}

//��ȡ����ĳ���
int LinkList::get_length() {
	return length;
}

//��������ĳ���
void LinkList::set_length(int i) {
	length = i;
}

//��ȡ����ڵ�����
int LinkList::get_node_number() {
	return node_number;
}

//��������ڵ�����
void LinkList::set_node_number(int i) {
	node_number = i;
}

//��ȡ����ı�־����
int LinkList::get_symbol() {
	return symbol;
}

//��������ı�־����
void LinkList::set_symbol(int i) {
	symbol = i;
}

//���ͷ�ڵ�ĵ�ַ
Node* LinkList::get_head() {
	return head;
}

//�������
void LinkList::Output() {
	cout << link << endl;

}