#include"common.h"


//输入校验
char read_input(int choice)
{
	string str;
	while (true)
	{
		getline(cin, str);
		if (str.size() != 1 || str[0] - '0' <= 0 || str[0] - '0' > choice)
		{
			cout << "Invalid!" << endl;
			cout << "请重新输入。" << endl;
		}
		else
			break;
	}
	//输入合法
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
			cout << "请正确输入数字。" << endl;
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
			cout << "请重新输入(Y/N)。" << endl;
		}
		else
			break;
	}
	return toupper(str[0]);
}