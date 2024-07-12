#include"account.h"
#include"common.h"


//���ļ��м�������
void loadFileData(vector<AccountItem>& items) {
	ifstream prj(FILEPATH);
	assert(prj);
	
	//�ļ��򿪳ɹ�����ÿ����Ŀ��װ��AccountItem����
	AccountItem item;
	while (prj >> item.itemType >> item.amount >> item.remark)
		items.push_back(item);

	prj.close();
}

//����
void accounting(vector<AccountItem>& items)
{
	showAccountMenu();
	char choice=read_input(3);
	switch (choice)
	{
	case '1':
		//��¼һ������
		recordAccount(items,INCOME);
		break;
	case '2':
		//��¼һ��֧��
		recordAccount(items,EXPEND);
		break;
	default:
		break;
	}
}
//��¼һ�������֧��
void recordAccount(vector<AccountItem>& items,string itemType)
{
	AccountItem item;
	item.itemType = itemType;

	cout << " �������" << endl;
	if (itemType == INCOME)
	{
		item.amount = readAmount();
	}
	else
	{
		item.amount = -readAmount();
	}

	cout << "�����뱸ע��" << endl;
	getline(cin, item.remark);

	items.push_back(item);
	//!!!!!!!!!д���ļ����־û�����
	insertIntoFile(item);
	
	//��ʾ�ɹ���Ϣ
	successMenu();

	string line;
	getline(cin, line);
}

void insertIntoFile(const AccountItem& item)
{
	//����һ��ofstream������׷�ӷ�ʽ����д��
	ofstream content(FILEPATH,ios::out|ios::app);
	content << item.itemType << "\t" << item.amount << "\t" << item.remark << endl;
	content.close();
}
//��ѯ
void query(const vector<AccountItem> items)
{
	showQueryMenu();
	//����ѡ�񣬺Ϸ���У��
	char choice = read_input(4);
	switch (choice)
	{
	case '1':		//��ѯȫ����Ŀ
		queryAll(items);
		break;
	case '2':		//��ѯ������
		queryDetails(items,INCOME);
		break;
	case '3':		//��ѯ��֧��
		queryDetails(items,EXPEND);
	}
}

void queryAll(const vector<AccountItem>& items)
{
	cout << "-----------------��ѯ���-----------------" << endl;
	cout << "\n����\t\t���\t\t��ע\n" << endl;
	int totle = 0;
	for (auto item : items)
	{
		printItem(item);
		totle += item.amount;
	}
	//�����Ϣ
	cout << "===========================================\n" << endl;
	cout << "����֧��" << totle << endl;
	cout << "\n�밴�س����������˵�����" << endl;

	string line;
	getline(cin, line);
}
void queryDetails(const vector<AccountItem>& items, string itemType)
{
	cout << "-----------------��ѯ���-----------------" << endl;
	cout << "\n����\t\t���\t\t��ע\n" << endl;

	int totle = 0;
	for (auto item : items)
	{
		if (item.itemType != itemType)
			continue;

		printItem(item);
		totle += item.amount;
	}
	//�����Ϣ
	cout << "===========================================\n" << endl;
	cout << ((itemType == INCOME) ? "������:" : "��֧��:") << totle << endl;
	cout << "\n�밴�س����������˵�����" << endl;

	string line;
	getline(cin, line);
}

//��ӡ���һ����Ŀ��Ϣ
void printItem(const AccountItem& item)
{
	cout << item.itemType << "\t\t" << item.amount << "\t\t" << item.remark << endl;
}

