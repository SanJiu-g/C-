#pragma once
//��������ͷ�ļ�
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<assert.h>
#include<stdexcept>

#define FILEPATH "D:\\��ҵ\\C++\\C++��Ŀ�������˲�\\AccountBook.txt"
#define INCOME "����"
#define EXPEND "֧��"

using namespace std;

//����ṹ��
struct AccountItem {
	string itemType;
	int amount;
	string remark;
};

//��ʾ�˵�
void showMainMenu();
void showAccountMenu();
void successMenu();
void showQueryMenu();



//����У��
char read_input(int choice);
char readQuitConfirm();
int readAmount();


