#include"account.h"
#include"common.h"


//从文件中加载数据
void loadFileData(vector<AccountItem>& items) {
	ifstream prj(FILEPATH);
	assert(prj);
	
	//文件打开成功，将每条账目包装成AccountItem类型
	AccountItem item;
	while (prj >> item.itemType >> item.amount >> item.remark)
		items.push_back(item);

	prj.close();
}

//记账
void accounting(vector<AccountItem>& items)
{
	showAccountMenu();
	char choice=read_input(3);
	switch (choice)
	{
	case '1':
		//记录一笔收入
		recordAccount(items,INCOME);
		break;
	case '2':
		//记录一笔支出
		recordAccount(items,EXPEND);
		break;
	default:
		break;
	}
}
//记录一笔收入或支出
void recordAccount(vector<AccountItem>& items,string itemType)
{
	AccountItem item;
	item.itemType = itemType;

	cout << " 请输入金额：" << endl;
	if (itemType == INCOME)
	{
		item.amount = readAmount();
	}
	else
	{
		item.amount = -readAmount();
	}

	cout << "请输入备注：" << endl;
	getline(cin, item.remark);

	items.push_back(item);
	//!!!!!!!!!写入文件做持久化处理
	insertIntoFile(item);
	
	//显示成功信息
	successMenu();

	string line;
	getline(cin, line);
}

void insertIntoFile(const AccountItem& item)
{
	//创建一个ofstream对象，以追加方式进行写入
	ofstream content(FILEPATH,ios::out|ios::app);
	content << item.itemType << "\t" << item.amount << "\t" << item.remark << endl;
	content.close();
}
//查询
void query(const vector<AccountItem> items)
{
	showQueryMenu();
	//输入选择，合法性校验
	char choice = read_input(4);
	switch (choice)
	{
	case '1':		//查询全部账目
		queryAll(items);
		break;
	case '2':		//查询总收入
		queryDetails(items,INCOME);
		break;
	case '3':		//查询总支出
		queryDetails(items,EXPEND);
	}
}

void queryAll(const vector<AccountItem>& items)
{
	cout << "-----------------查询结果-----------------" << endl;
	cout << "\n类型\t\t金额\t\t备注\n" << endl;
	int totle = 0;
	for (auto item : items)
	{
		printItem(item);
		totle += item.amount;
	}
	//输出信息
	cout << "===========================================\n" << endl;
	cout << "总收支：" << totle << endl;
	cout << "\n请按回车键返回主菜单……" << endl;

	string line;
	getline(cin, line);
}
void queryDetails(const vector<AccountItem>& items, string itemType)
{
	cout << "-----------------查询结果-----------------" << endl;
	cout << "\n类型\t\t金额\t\t备注\n" << endl;

	int totle = 0;
	for (auto item : items)
	{
		if (item.itemType != itemType)
			continue;

		printItem(item);
		totle += item.amount;
	}
	//输出信息
	cout << "===========================================\n" << endl;
	cout << ((itemType == INCOME) ? "总收入:" : "总支出:") << totle << endl;
	cout << "\n请按回车键返回主菜单……" << endl;

	string line;
	getline(cin, line);
}

//打印输出一条账目信息
void printItem(const AccountItem& item)
{
	cout << item.itemType << "\t\t" << item.amount << "\t\t" << item.remark << endl;
}

