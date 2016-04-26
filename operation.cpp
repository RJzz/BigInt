#include <sstream>
#include "operation.h"
//减法运算,符号相等的时候相减，符号不等的时候相加，绝对值大的作为被减数和被加数
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
	} else if (firstData.get_symbol() != secondData.get_symbol()) {		//符号要取被减数的符号啊
		while (nodeFirst) {
			//当节点少的节点已经处理结束后不再对其进行处理
			if (nodeFirst >= num) {
				addAnwser = p->get_data() + q->get_data() + get_carry();
			} else {
				addAnwser = p->get_data() + get_carry();
			}
			set_carry(addAnwser / 10000);
			addAnwser %= 10000;
			change = converToString(addAnwser);
			//转化后的节点长度如果没有4的话就用"0"补上
			change = addZero(change);
			p = p->next;
			q = q->next;
			nodeFirst--;
			//判断最高位节点是否有进位
			//if (nodeFirst == 0) {
			//	last.insert(0, change);
			//	if (get_carry()) {
			//		s.clear();
			//		s << get_carry();
			//		s >> change;
			//		//如果是负数的话在前面加上负号
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
		
		//这段代码的作用是吧前面的'0'都清空
		last = clearZero(last);
		//加上逗号
		last = addCommoa(last);
		//符号不同的用被减数作为符号位
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
			//当节点少的节点已经处理结束后不再对其进行处理
			if (nodeFirst >= num) {
				int check = p->get_data() - q->get_data() - get_borrow();
				if (check >= 0) {
					addAnwser = check;
					set_borrow(0);
				} else if (check < 0) {
					addAnwser = (check + 10000) % 10000;
					set_borrow(1);
				}
				//} else {		//如果两个数据相等，则根据是否借位来设定数值，因为节点的数据为10000进制
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
			//转化后的节点长度如果没有4的话就用"0"补上
			change = addZero(change);
			p = p->next;
			q = q->next;
			nodeFirst--;
			last.insert(0, change);
		}
		//这段代码的作用是吧前面的'0'都清空
		last = clearZero(last);
		//加上逗号
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
/*加法运算，符号相等时相加,绝对值大的作为被加数，符号不等时用绝对值大的作为被减数,结果的符号为绝对值大的数*/
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
			//当节点少的节点已经处理结束后不再对其进行处理
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
			//转化后的节点长度如果没有4的话就用"0"补上
			change = addZero(change);

			nodeFirst--;
			//判断最高位节点是否有进位
			if (nodeFirst == 0 && get_carry()) {
				last.insert(0, "1" + change);
			} else {
				last.insert(0, change);
			}
		}
		//这段代码的作用是吧前面的'0'都清空
		last = clearZero(last);
		//加上逗号
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
			//当节点少的节点已经处理结束后不再对其进行处理
			if (nodeFirst >= num) {
				int check = p->get_data() - q->get_data() - get_borrow();
				if (check >= 0) {
					addAnwser = check;
					set_borrow(0);
				} else if(check < 0){
					addAnwser = (check + 10000) % 10000;
					set_borrow(1);
				}
				//} else {		//如果两个数据相等，则根据是否借位来设定数值，因为节点的数据为10000进制
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
			//转化后的节点长度如果没有4的话就用"0"补上
			change = addZero(change);
			p = p->next;
			q = q->next;
			nodeFirst--;
			last.insert(0, change);
		}
		//这段代码的作用是吧前面的'0'都清空
		/*s.clear();
		s << last;
		s >> addAnwser;*/
		last = clearZero(last);
		//加上逗号
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

//乘法,先乘出一个x1来，然后初始化，把结果保存到answer里面，释放x1，
//重新初始化x1，与answer相加，answer作为加数，如此下去
void Operation::Multiply(LinkList first, LinkList second,int c) {
	//确定乘数和被乘数,节点少的为乘数
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
	long mulAnswer = 0;							//本位的数值
	int mulTime = secondData.get_node_number();		//乘法的次数为节点少的链表的节点数
	int insertNode = 0;							//需要在临时链表中插入
	while (mulTime) {
		LinkList *x = new LinkList("");
		int n = firstData.get_node_number();	//需要乘的节点次数
		p = firstData.get_head()->next;			//重置p的位置
		while (n) {
			mulAnswer = p->get_data() * q->get_data() + get_carry();
			set_carry(mulAnswer / 10000);
			mulAnswer %= 10000;
			change = converToString(mulAnswer);
			//转化后的节点长度如果没有4的话就用"0"补上
			change = addZero(change);
			last.insert(0, change);
			p = p->next;
			n--;
		}
		if (get_carry()) {
			change = converToString(get_carry());
			last.insert(0, change);
		}
		//去除字符串前面的0
		last = clearZero(last);
		//移位
		for (int j = 0; j < insertNode; ++j) {
			last.insert(last.size(), "0000");
		}
		last = addCommoa(last);
		x->set_link(last);
		x->Init();
		insertNode++;
		//把进位清零
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

//除法
void Operation::Division(LinkList first, LinkList second) {
	//确定除数和被除数,节点少的为除数
	if (first.get_node_number() >= second.get_node_number()) {
		firstData = first;
		secondData = second;
	} else {
		firstData = second;
		secondData = first;
	}
	//除去逗号和负号
	if (firstData.get_symbol() == 0) {
		firstData.set_link(firstData.get_link().substr(1, firstData.get_link().size() - 1));
	}
	if (secondData.get_symbol() == 0) {
		secondData.set_link(secondData.get_link().substr(1, secondData.get_link().size() - 1));
	}
	firstData.set_link(deleteCommoa(firstData.get_link()));
	secondData.set_link(deleteCommoa(secondData.get_link()));

	int lengthF = firstData.get_length();
	int lengthS = secondData.get_link().size();	//获取到除数的长度
	int time = 0;								//除法上位

	string subString;	//子串
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
			//加上逗号
			subString = addCommoa(subString);
			LinkList *p = new LinkList(subString);
			p->Init();
			divisionList = *p;
			//开始减法，每次减都time加一
			while (CompareForDiv(divisionList, secondData)) {
				SubForDiv(divisionList, secondData);
				time++;
			}
			lengthS++;

			set_divide(get_divide() + converToString(time));
			subString = firstData.get_link().substr(lengthS, 1);
			subString = clearZero(deleteCommoa(divisionList.get_link()) + subString);

			//除法计数清零
			time = 0;
		}
	}
	//加逗号
	set_divide(addCommoa(get_divide()));
	answer->set_link(get_divide());
	if (first.get_symbol() != second.get_symbol()) {
		answer->set_symbol(0);
		answer->set_link("-" + answer->get_link());
	}

	answer->Init();



}

//为除法服务的减法
void Operation::SubForDiv(LinkList a, LinkList b) {
	Node *pN = a.get_head()->next;
	Node *qN = b.get_head()->next;
	stringstream s;
	string change, last;
	int addAnswer;
	int nodeFirst = a.get_node_number();
	int num = a.get_node_number() - b.get_node_number();

	while (nodeFirst) {
		//当节点少的节点已经处理结束后不再对其进行处理
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
		//转化后的节点长度如果没有4的话就用"0"补上
		change = addZero(change);
		pN = pN->next;
		qN = qN->next;
		nodeFirst--;
		last.insert(0, change);
	}
	//这段代码的作用是吧前面的'0'都清空
	last = clearZero(last);
	//加上逗号
	last = addCommoa(last);
	LinkList *temp = new LinkList(last);
	temp->Init();
	divisionList = *temp;
	delete temp;


}

//幂运算
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



//为乘法服务的加法
void Operation::AddForMul(LinkList a, LinkList b) {
	Node *pNode = a.get_head()->next;
	Node *qNode = b.get_head()->next;
	stringstream s;
	string change, last;
	int addAnswer;
	int nodeFirst = a.get_node_number();
	int num = a.get_node_number() - b.get_node_number();
	while (nodeFirst) {
		//当节点少的节点已经处理结束后不再对其进行处理
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
		//转化后的节点长度如果没有4的话就用"0"补上
		change = addZero(change);

		nodeFirst--;
		//判断最高位节点是否有进位
		if (nodeFirst == 0 && get_carry()) {
			last.insert(0, "1" + change);
		} else {
			last.insert(0, change);
		}
	}
	last = clearZero(last);
	//加上逗号
	last = addCommoa(last);
	LinkList *temp = new LinkList(last);
	temp->Init();
	*answer = *temp;
	delete temp;
	//进位清零很关键
	set_carry(0);
	free(qNode);
	free(pNode);
}

//为除法服务的比较大小
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

		//表示两个数相等
		if (i == 0) {
			check = true;
		}
	}
	return check;
}

//比较绝对值的大小，确定数据的放置顺序
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
			//符号不等，但是数值相等，结果为0
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

//获取equal的值
int Operation::get_equal() {
	return equal;
}

//设置equal的值
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
//输出结果
void Operation::Output() {
	answer->Output();
}

Operation::~Operation() {
}

//删除逗号
string Operation::deleteCommoa(string a) {
	string::iterator it;
	for (it = a.begin(); it != a.end(); ++it) {
		if (*it == ',' || *it == '-') {
			a.erase(it);
		}
	}
	return a;
}

//添加逗号
string Operation::addCommoa(string s) {
	//加上逗号
	int j = s.size() - 4;
	for (; j > 0; j -= 4) {
		s.insert(j, ",");
	}
	return s;
}

//删除字符串前面的'0'
string Operation::clearZero(string s) {
	int start = s.find_first_not_of("0");
	//如果全部都是'0'的话
	if (start == -1) {
		s = "0";
	} else {
		s = s.substr(start, s.size() - start);
	}

	return s;
}

//将一个节点的四个字符用'0'填满
string Operation::addZero(string s) {
	//转化后的节点长度如果没有4的话就用"0"补上
	if (s.length() < 4) {
		for (int i = s.size(); i < 4; ++i) {
			s.insert(0, "0");
		}
	}
	return s;
}

//获取除法结果链
string Operation::get_divide() {
	return divide;
}

//设置除法链
void Operation::set_divide(string s) {
	divide = s;
}

//转化为整数
string Operation::converToString(int i) {
	stringstream s;
	string change;
	s.clear();
	s << i;
	s >> change;
	return change;
}

//获取被除的链
LinkList Operation::get_divisionlist() {
	return divisionList;
}