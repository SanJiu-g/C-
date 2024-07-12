#pragma once
#include"common.h"


//从文件中加载数据
void loadFileData(vector<AccountItem>& items);

//记账
void accounting(vector<AccountItem>& items);
void recordAccount(vector<AccountItem>& items, string itemType);
void insertIntoFile(const AccountItem& item);


//查询
void query(const vector<AccountItem> items);
void queryAll(const vector<AccountItem>& items);
void queryDetails(const vector<AccountItem>& items,string itemType);
void printItem(const AccountItem& item);

