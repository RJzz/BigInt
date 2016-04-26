
#include <fstream>
#include "linklist.h"
#include "operation.h"
#define Max 10000

int main() {
	//向文件中写的字符串
	string out;
	cout << "请按照格式要求输入两个数值进行加减运算，如果想要进行幂运算，只需把数值放在两个数的第一个即可:";
	cin >> out;
	int operation = 1;
	ifstream fin;
	ofstream fout;
	fout.open("input.txt");
	if (fout.is_open()) {
		fout << out;
		fout.close();
	}
	fin.open("input.txt");
	if (fin.is_open() == false) {
		cout << "Can't open file ,Bye Bye.\n";
		exit(EXIT_FAILURE);
	}
	string input;
	getline(fin, input, ';');
	string one = input;

	input.clear();

	getline(fin, input, ';');
	string two = input;




	cout << "\n-------------欢迎各位来到恐怖的！可怕的！让你旋转爆炸的RJzz的长整数四则运算系统---------------\n";
	cout << "1.加法计算\n" << "2.减法计算\n" << "3.乘法计算\n" << "4.除法计算\n" 
		<< "5.幂运算\n"  << "6.阶乘运算\n" << "输入0退出系统\n";
	while (operation) {
		cout << "请输入你要进行的操作序号: ";
		cin >> operation;
		Operation *op = new Operation();
		LinkList *test = new LinkList(one);
		test->Init();
		LinkList *test1 = new LinkList(two);
		test1->Init();
		switch (operation) {
		case 1:
			op->Compare(*test, *test1);
			op->Add();
			cout << "加法运算的结果为：";
			op->Output();
			break;
		case 2:
			op->Compare(*test, *test1);
			op->Sub();
			cout << "减法运算的结果为：";
			op->Output();
			break;
		case 3:
			op->Multiply(*test, *test1, 0);
			cout << "乘法运算的结果为：";
			op->Output();
			break;
		case 4:
			op->Division(*test, *test1);
			cout << "除法运算运算的结果为：";
			op->Output();
			cout << "余数为： " << op->get_divisionlist().get_link() << endl;
			break;
		case 5:
			int n;
			cout << "请输入你想要进行计算的指数的值: ";
			cin >> n;
			op->Involution(*test, n);
			op->Output();
			break;
		case 6:
			cout << "时间问题，还没做出来" << endl;
			break;
		default:
			break;
		}
		delete op;
		delete test;
		delete test1;
	}
	cout << "Thanks,求教一种效率高的除法，本系统的除法个人觉得效率太低";
	fin.clear();
	fin.close();
	system("PAUSE");
	return 0;
}