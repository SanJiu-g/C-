#include"common.h"


//����У��
char read_input(int choice)
{
	string str;
	while (true)
	{
		getline(cin, str);
		if (str.size() != 1 || str[0] - '0' <= 0 || str[0] - '0' > choice)
		{
			cout << "Invalid!" << endl;
			cout << "���������롣" << endl;
		}
		else
			break;
	}
	//����Ϸ�
	return str[0];
}
int readAmount()
{
	int amount;

	string str;
	while (true)
	{
		getline(cin, str);

		try {
			amount = stoi(str);
			break;
		}
		catch(const invalid_argument& e)
		{
			cout << "Invalid!" << endl;
			cout << "����ȷ�������֡�" << endl;
		}
	}
	return amount;
}
char readQuitConfirm()
{
	string str;
	while (true)
	{
		getline(cin, str);
		if (str.size()!=1||toupper(str[0]) != 'Y' && toupper(str[0]) != 'N')
		{
			cout << "Invalid!" << endl;
			cout << "����������(Y/N)��" << endl;
		}
		else
			break;
	}
	return toupper(str[0]);
}