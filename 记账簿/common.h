#pragma once
//引入所需头文件
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<assert.h>
#include<stdexcept>

#define FILEPATH "D:\\作业\\C++\\C++项目——记账簿\\AccountBook.txt"
#define INCOME "收入"
#define EXPEND "支出"

using namespace std;

//定义结构体
struct AccountItem {
	string itemType;
	int amount;
	string remark;
};

//显示菜单
void showMainMenu();
void showAccountMenu();
void successMenu();
void showQueryMenu();



//输入校验
char read_input(int choice);
char readQuitConfirm();
int readAmount();


