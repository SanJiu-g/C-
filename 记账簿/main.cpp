#include"common.h"
#include"account.h"

int main(void) {
	//��������
	vector<AccountItem> items;
	//�����ļ�����
	loadFileData(items);
	bool quit = false;

	while (!quit)
	{
		showMainMenu();

		char key = read_input(3);
		switch (key)
		{
		case '1':			//����
			accounting(items);
			break;
		case '2':			//��ѯ
			query(items);
			break;
		case '3':			//�˳�
			cout << "ȷ���˳�����Y/N��" << endl;
			if (readQuitConfirm()=='Y')
				quit = true;
			break;
		default:
			break;
		}
	}

	return 0;
}