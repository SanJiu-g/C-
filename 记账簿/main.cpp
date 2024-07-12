#include"common.h"
#include"account.h"

int main(void) {
	//创建对象
	vector<AccountItem> items;
	//加载文件数据
	loadFileData(items);
	bool quit = false;

	while (!quit)
	{
		showMainMenu();

		char key = read_input(3);
		switch (key)
		{
		case '1':			//记账
			accounting(items);
			break;
		case '2':			//查询
			query(items);
			break;
		case '3':			//退出
			cout << "确认退出？（Y/N）" << endl;
			if (readQuitConfirm()=='Y')
				quit = true;
			break;
		default:
			break;
		}
	}

	return 0;
}