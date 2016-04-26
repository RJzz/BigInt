#include <sstream>
#include "operation.h"
//��������,������ȵ�ʱ����������Ų��ȵ�ʱ����ӣ�����ֵ�����Ϊ�������ͱ�����
void Operation::Sub() {
	string change, last;
	int addAnwser = 0;
	int nodeFirst = firstData.get_node_number();
	int nodeSecond = secondData.get_node_number();
	int num = nodeFirst - nodeSecond;
	Node *p = firstData.get_head()->next;
	Node *q = secondData.get_head()->next;
	if (get_equal()) {
		answer = new LinkList("0");
	} else if (firstData.get_symbol() != secondData.get_symbol()) {		//����Ҫȡ�������ķ��Ű�
		while (nodeFirst) {
			//���ڵ��ٵĽڵ��Ѿ�����������ٶ�����д���
			if (nodeFirst >= num) {
				addAnwser = p->get_data() + q->get_data() + get_carry();
			} else {
				addAnwser = p->get_data() + get_carry();
			}
			set_carry(addAnwser / 10000);
			addAnwser %= 10000;
			change = converToString(addAnwser);
			//ת����Ľڵ㳤�����û��4�Ļ�����"0"����
			change = addZero(change);
			p = p->next;
			q = q->next;
			nodeFirst--;
			//�ж����λ�ڵ��Ƿ��н�λ
			//if (nodeFirst == 0) {
			//	last.insert(0, change);
			//	if (get_carry()) {
			//		s.clear();
			//		s << get_carry();
			//		s >> change;
			//		//����Ǹ����Ļ���ǰ����ϸ���
			//		if (firstData.get_symbol() == 0) {
			//			last.insert(0, "-" + change + ",");
			//		} else {
			//			last.insert(0, change + ",");
			//		}
			//		break;
			//	}
			//} else {
	
			last.insert(0, change);
		}
		
		//��δ���������ǰ�ǰ���'0'�����
		last = clearZero(last);
		//���϶���
		last = addCommoa(last);
		//���Ų�ͬ���ñ�������Ϊ����λ
		answer->set_symbol(firstData.get_symbol());
		if (answer->get_symbol() == 0) {
			last.insert(0, "-");
		}
		answer = new LinkList(last);
		answer->Init();
		answer->set_symbol(firstData.get_symbol());
		delete p;
		delete q;
	} else if (firstData.get_symbol() == secondData.get_symbol()) {
		while (nodeFirst) {
			//���ڵ��ٵĽڵ��Ѿ�����������ٶ�����д���
			if (nodeFirst >= num) {
				int check = p->get_data() - q->get_data() - get_borrow();
				if (check >= 0) {
					addAnwser = check;
					set_borrow(0);
				} else if (check < 0) {
					addAnwser = (check + 10000) % 10000;
					set_borrow(1);
				}
				//} else {		//�������������ȣ�������Ƿ��λ���趨��ֵ����Ϊ�ڵ������Ϊ10000����
				//	addAnwser = (10000 - get_borrow()) % 10000;
				//	if (!addAnwser) {
				//		set_borrow(0);
				//	}
				//}

			} else {
				int temp = p->get_data() - get_borrow();
				if (temp >= 0) {
					addAnwser = temp;
					set_borrow(0);
				} else if (temp < 0) {
					addAnwser = (temp + 10000) % 10000;
					set_borrow(1);
				}

			}
			change = converToString(addAnwser);
			//ת����Ľڵ㳤�����û��4�Ļ�����"0"����
			change = addZero(change);
			p = p->next;
			q = q->next;
			nodeFirst--;
			last.insert(0, change);
		}
		//��δ���������ǰ�ǰ���'0'�����
		last = clearZero(last);
		//���϶���
		last = addCommoa(last);
		answer->set_symbol(firstData.get_symbol());
		if (answer->get_symbol() == 0) {
			last.insert(0, "-");
		}
		answer = new LinkList(last);
		answer->Init();

		delete p;
		delete q;
	}
}
/*�ӷ����㣬�������ʱ���,����ֵ�����Ϊ�����������Ų���ʱ�þ���ֵ�����Ϊ������,����ķ���Ϊ����ֵ�����*/
void Operation::Add() {
	string change, last;
	int addAnwser = 0;
	int nodeFirst = firstData.get_node_number();
	int nodeSecond = secondData.get_node_number();
	int num = nodeFirst - nodeSecond;
	Node *p = firstData.get_head()->next;
	Node *q = secondData.get_head()->next;
	if (get_equal()) {
		answer = new LinkList("0");
	} else if(firstData.get_symbol() == secondData.get_symbol()){
		while (nodeFirst) {
			//���ڵ��ٵĽڵ��Ѿ�����������ٶ�����д���
			if (nodeFirst >= num) {
				addAnwser = p->get_data() + q->get_data() + get_carry();
				p = p->next;
				q = q->next;
			} else {
				addAnwser = p->get_data() +  get_carry();
				p = p->next;
			}
			set_carry(addAnwser / 10000);
			addAnwser %= 10000;
			change = converToString(addAnwser);
			//ת����Ľڵ㳤�����û��4�Ļ�����"0"����
			change = addZero(change);

			nodeFirst--;
			//�ж����λ�ڵ��Ƿ��н�λ
			if (nodeFirst == 0 && get_carry()) {
				last.insert(0, "1" + change);
			} else {
				last.insert(0, change);
			}
		}
		//��δ���������ǰ�ǰ���'0'�����
		last = clearZero(last);
		//���϶���
		last = addCommoa(last);
		answer->set_symbol(firstData.get_symbol());
		if (answer->get_symbol() == 0) {
			last.insert(0, "-");
		}
		answer = new LinkList(last);
		answer->Init();
		answer->set_symbol(firstData.get_symbol());
		delete p;
		delete q;
	} else if(firstData.get_symbol() != secondData.get_symbol()){
		while (nodeFirst) {
			//���ڵ��ٵĽڵ��Ѿ�����������ٶ�����д���
			if (nodeFirst >= num) {
				int check = p->get_data() - q->get_data() - get_borrow();
				if (check >= 0) {
					addAnwser = check;
					set_borrow(0);
				} else if(check < 0){
					addAnwser = (check + 10000) % 10000;
					set_borrow(1);
				}
				//} else {		//�������������ȣ�������Ƿ��λ���趨��ֵ����Ϊ�ڵ������Ϊ10000����
				//	addAnwser = (10000 - get_borrow()) % 10000;
				//	if (!addAnwser) {
				//		set_borrow(0);
				//	}
				//}
				
			} else {
				int temp = p->get_data() - get_borrow();
				if (temp >= 0) {
					addAnwser = temp;
				} else if (temp < 0) {
					addAnwser = (temp + 10000) % 10000;
				}
				
			}
			change = converToString(addAnwser);
			//ת����Ľڵ㳤�����û��4�Ļ�����"0"����
			change = addZero(change);
			p = p->next;
			q = q->next;
			nodeFirst--;
			last.insert(0, change);
		}
		//��δ���������ǰ�ǰ���'0'�����
		/*s.clear();
		s << last;
		s >> addAnwser;*/
		last = clearZero(last);
		//���϶���
		last = addCommoa(last);
		answer->set_symbol(firstData.get_symbol());
		if (answer->get_symbol() == 0) {
			last.insert(0, "-");
		}
		answer = new LinkList(last);
		answer->Init();
		answer->set_symbol(firstData.get_symbol());
		delete p;
		delete q;
	}
}

//�˷�,�ȳ˳�һ��x1����Ȼ���ʼ�����ѽ�����浽answer���棬�ͷ�x1��
//���³�ʼ��x1����answer��ӣ�answer��Ϊ�����������ȥ
void Operation::Multiply(LinkList first, LinkList second,int c) {
	//ȷ�������ͱ�����,�ڵ��ٵ�Ϊ����
	if (first.get_node_number() >= second.get_node_number()) {
		firstData = first;
		secondData = second;
	} else {
		firstData = second;
		secondData = first;
	}
	string change, last;
	Node *p = firstData.get_head()->next;
	Node *q = secondData.get_head()->next;
	long mulAnswer = 0;							//��λ����ֵ
	int mulTime = secondData.get_node_number();		//�˷��Ĵ���Ϊ�ڵ��ٵ�����Ľڵ���
	int insertNode = 0;							//��Ҫ����ʱ�����в���
	while (mulTime) {
		LinkList *x = new LinkList("");
		int n = firstData.get_node_number();	//��Ҫ�˵Ľڵ����
		p = firstData.get_head()->next;			//����p��λ��
		while (n) {
			mulAnswer = p->get_data() * q->get_data() + get_carry();
			set_carry(mulAnswer / 10000);
			mulAnswer %= 10000;
			change = converToString(mulAnswer);
			//ת����Ľڵ㳤�����û��4�Ļ�����"0"����
			change = addZero(change);
			last.insert(0, change);
			p = p->next;
			n--;
		}
		if (get_carry()) {
			change = converToString(get_carry());
			last.insert(0, change);
		}
		//ȥ���ַ���ǰ���0
		last = clearZero(last);
		//��λ
		for (int j = 0; j < insertNode; ++j) {
			last.insert(last.size(), "0000");
		}
		last = addCommoa(last);
		x->set_link(last);
		x->Init();
		insertNode++;
		//�ѽ�λ����
		set_carry(0);
		AddForMul(*x, *answer);
		last.clear();
		delete x;
		q = q->next;
		mulTime--;
	}
	if (first.get_symbol() != second.get_symbol()) {
		answer->set_symbol(0);
		answer->set_link("-" + answer->get_link());
	}
	/*if (!c) {
		answer->Init();
	}*/
}

//����
void Operation::Division(LinkList first, LinkList second) {
	//ȷ�������ͱ�����,�ڵ��ٵ�Ϊ����
	if (first.get_node_number() >= second.get_node_number()) {
		firstData = first;
		secondData = second;
	} else {
		firstData = second;
		secondData = first;
	}
	//��ȥ���ź͸���
	if (firstData.get_symbol() == 0) {
		firstData.set_link(firstData.get_link().substr(1, firstData.get_link().size() - 1));
	}
	if (secondData.get_symbol() == 0) {
		secondData.set_link(secondData.get_link().substr(1, secondData.get_link().size() - 1));
	}
	firstData.set_link(deleteCommoa(firstData.get_link()));
	secondData.set_link(deleteCommoa(secondData.get_link()));

	int lengthF = firstData.get_length();
	int lengthS = secondData.get_link().size();	//��ȡ�������ĳ���
	int time = 0;								//������λ

	string subString;	//�Ӵ�
	subString = firstData.get_link().substr(0, lengthS + 1);

	if (lengthF == lengthS) {
		divisionList = firstData;
		while (CompareForDiv(divisionList, secondData)) {
			SubForDiv(divisionList, secondData);
			time++;
		}
		set_divide(get_divide() + converToString(time));
	} else {
		while (lengthF - lengthS) {
			//���϶���
			subString = addCommoa(subString);
			LinkList *p = new LinkList(subString);
			p->Init();
			divisionList = *p;
			//��ʼ������ÿ�μ���time��һ
			while (CompareForDiv(divisionList, secondData)) {
				SubForDiv(divisionList, secondData);
				time++;
			}
			lengthS++;

			set_divide(get_divide() + converToString(time));
			subString = firstData.get_link().substr(lengthS, 1);
			subString = clearZero(deleteCommoa(divisionList.get_link()) + subString);

			//������������
			time = 0;
		}
	}
	//�Ӷ���
	set_divide(addCommoa(get_divide()));
	answer->set_link(get_divide());
	if (first.get_symbol() != second.get_symbol()) {
		answer->set_symbol(0);
		answer->set_link("-" + answer->get_link());
	}

	answer->Init();



}

//Ϊ��������ļ���
void Operation::SubForDiv(LinkList a, LinkList b) {
	Node *pN = a.get_head()->next;
	Node *qN = b.get_head()->next;
	stringstream s;
	string change, last;
	int addAnswer;
	int nodeFirst = a.get_node_number();
	int num = a.get_node_number() - b.get_node_number();

	while (nodeFirst) {
		//���ڵ��ٵĽڵ��Ѿ�����������ٶ�����д���
		if (nodeFirst >= num) {
			int check = pN->get_data() - qN->get_data() - get_borrow();
			if (check >= 0) {
				addAnswer = check;
				set_borrow(0);
			} else if (check < 0) {
				addAnswer = (check + 10000) % 10000;
				set_borrow(1);
			}
		} else {
			int temp = pN->get_data() - get_borrow();
			if (temp >= 0) {
				addAnswer = temp;
				set_borrow(0);
			} else if (temp < 0) {
				addAnswer = (temp + 10000) % 10000;
				set_borrow(1);
			}

		}
		change = converToString(addAnswer);
		//ת����Ľڵ㳤�����û��4�Ļ�����"0"����
		change = addZero(change);
		pN = pN->next;
		qN = qN->next;
		nodeFirst--;
		last.insert(0, change);
	}
	//��δ���������ǰ�ǰ���'0'�����
	last = clearZero(last);
	//���϶���
	last = addCommoa(last);
	LinkList *temp = new LinkList(last);
	temp->Init();
	divisionList = *temp;
	delete temp;


}

//������
void Operation::Involution(LinkList a, int n) {
	n--;
	LinkList b = a;
	while (n) {
		free(answer);
		answer = new LinkList();
		Multiply(b, a, 0);
		n--;
		b = *answer;

	}
}



//Ϊ�˷�����ļӷ�
void Operation::AddForMul(LinkList a, LinkList b) {
	Node *pNode = a.get_head()->next;
	Node *qNode = b.get_head()->next;
	stringstream s;
	string change, last;
	int addAnswer;
	int nodeFirst = a.get_node_number();
	int num = a.get_node_number() - b.get_node_number();
	while (nodeFirst) {
		//���ڵ��ٵĽڵ��Ѿ�����������ٶ�����д���
		if (nodeFirst >= num) {
			addAnswer = pNode->get_data() + qNode->get_data() + get_carry();
			pNode = pNode->next;
			qNode = qNode->next;
		} else {
			addAnswer = pNode->get_data() + get_carry();
			pNode = pNode->next;
		}
		set_carry(addAnswer / 10000);
		addAnswer %= 10000;
		change = converToString(addAnswer);
		//ת����Ľڵ㳤�����û��4�Ļ�����"0"����
		change = addZero(change);

		nodeFirst--;
		//�ж����λ�ڵ��Ƿ��н�λ
		if (nodeFirst == 0 && get_carry()) {
			last.insert(0, "1" + change);
		} else {
			last.insert(0, change);
		}
	}
	last = clearZero(last);
	//���϶���
	last = addCommoa(last);
	LinkList *temp = new LinkList(last);
	temp->Init();
	*answer = *temp;
	delete temp;
	//��λ����ܹؼ�
	set_carry(0);
	free(qNode);
	free(pNode);
}

//Ϊ��������ıȽϴ�С
bool Operation::CompareForDiv(LinkList a, LinkList b) {
	if (a.get_length() > b.get_length()) {
		return true;
	}
	bool check = true;
	int i = a.get_node_number();
	Node *p = a.get_head();
	Node *q = b.get_head();
	p = p->prior;
	q = q->prior;
	while (i) {
		if (p->get_data() > q->get_data()) {
			check = true;
			break;
		} else if (p->get_data() < q->get_data()) {
			check = false;
			break;
		} else if (p->get_data() == q->get_data()) {
			p = p->prior;
			q = q->prior;
			i--;
		}

		//��ʾ���������
		if (i == 0) {
			check = true;
		}
	}
	return check;
}

//�ȽϾ���ֵ�Ĵ�С��ȷ�����ݵķ���˳��
void Operation::Compare(LinkList first, LinkList second) {
	if (first.get_length() > second.get_length()) {
		firstData = first;
		secondData = second;
	} else if (first.get_length() < second.get_length()) {
		firstData = second;
		secondData = first;
	} else {
		int i = first.get_node_number();
		Node *p = first.get_head();
		Node *q = second.get_head();
		p = p->next;
		q = q->next;
		while (i) {
			if (p->get_data() > q->get_data()) {
				firstData = first;
				secondData = second;
				break;
			} else if (p->get_data() < q->get_data()) {
				firstData = second;
				secondData = first;
				break;
			} else if (p->get_data() == q->get_data()) {
				p = p->next;
				q = q->next;
			}
			i--;
			//���Ų��ȣ�������ֵ��ȣ����Ϊ0
			if (i == 0 && first.get_symbol() != second.get_symbol()) {
				set_equal(1);
			} else if(i == 0 && first.get_symbol() == second.get_symbol()){
				firstData = first;
				secondData = second;
				set_equal(0);
			}
		}
	}
}

//��ȡequal��ֵ
int Operation::get_equal() {
	return equal;
}

//����equal��ֵ
void Operation::set_equal(int i) {
	equal = i;
}

void Operation::set_carry(int i) {
	carry = i;
}

int Operation::get_carry() {
	return carry;
}

Operation::Operation() {
	answer = new LinkList();
	carry = 0;
	borrow = 0;
}

void Operation::set_borrow(int i) {
	borrow = i;
}

int Operation::get_borrow() {
	return borrow;
}
//������
void Operation::Output() {
	answer->Output();
}

Operation::~Operation() {
}

//ɾ������
string Operation::deleteCommoa(string a) {
	string::iterator it;
	for (it = a.begin(); it != a.end(); ++it) {
		if (*it == ',' || *it == '-') {
			a.erase(it);
		}
	}
	return a;
}

//��Ӷ���
string Operation::addCommoa(string s) {
	//���϶���
	int j = s.size() - 4;
	for (; j > 0; j -= 4) {
		s.insert(j, ",");
	}
	return s;
}

//ɾ���ַ���ǰ���'0'
string Operation::clearZero(string s) {
	int start = s.find_first_not_of("0");
	//���ȫ������'0'�Ļ�
	if (start == -1) {
		s = "0";
	} else {
		s = s.substr(start, s.size() - start);
	}

	return s;
}

//��һ���ڵ���ĸ��ַ���'0'����
string Operation::addZero(string s) {
	//ת����Ľڵ㳤�����û��4�Ļ�����"0"����
	if (s.length() < 4) {
		for (int i = s.size(); i < 4; ++i) {
			s.insert(0, "0");
		}
	}
	return s;
}

//��ȡ���������
string Operation::get_divide() {
	return divide;
}

//���ó�����
void Operation::set_divide(string s) {
	divide = s;
}

//ת��Ϊ����
string Operation::converToString(int i) {
	stringstream s;
	string change;
	s.clear();
	s << i;
	s >> change;
	return change;
}

//��ȡ��������
LinkList Operation::get_divisionlist() {
	return divisionList;
}