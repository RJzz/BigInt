
#include <fstream>
#include "linklist.h"
#include "operation.h"
#define Max 10000

int main() {
	//���ļ���д���ַ���
	string out;
	cout << "�밴�ո�ʽҪ������������ֵ���мӼ����㣬�����Ҫ���������㣬ֻ�����ֵ�����������ĵ�һ������:";
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




	cout << "\n-------------��ӭ��λ�����ֲ��ģ����µģ�������ת��ը��RJzz�ĳ�������������ϵͳ---------------\n";
	cout << "1.�ӷ�����\n" << "2.��������\n" << "3.�˷�����\n" << "4.��������\n" 
		<< "5.������\n"  << "6.�׳�����\n" << "����0�˳�ϵͳ\n";
	while (operation) {
		cout << "��������Ҫ���еĲ������: ";
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
			cout << "�ӷ�����Ľ��Ϊ��";
			op->Output();
			break;
		case 2:
			op->Compare(*test, *test1);
			op->Sub();
			cout << "��������Ľ��Ϊ��";
			op->Output();
			break;
		case 3:
			op->Multiply(*test, *test1, 0);
			cout << "�˷�����Ľ��Ϊ��";
			op->Output();
			break;
		case 4:
			op->Division(*test, *test1);
			cout << "������������Ľ��Ϊ��";
			op->Output();
			cout << "����Ϊ�� " << op->get_divisionlist().get_link() << endl;
			break;
		case 5:
			int n;
			cout << "����������Ҫ���м����ָ����ֵ: ";
			cin >> n;
			op->Involution(*test, n);
			op->Output();
			break;
		case 6:
			cout << "ʱ�����⣬��û������" << endl;
			break;
		default:
			break;
		}
		delete op;
		delete test;
		delete test1;
	}
	cout << "Thanks,���һ��Ч�ʸߵĳ�������ϵͳ�ĳ������˾���Ч��̫��";
	fin.clear();
	fin.close();
	system("PAUSE");
	return 0;
}