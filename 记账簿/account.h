#pragma once
#include"common.h"


//���ļ��м�������
void loadFileData(vector<AccountItem>& items);

//����
void accounting(vector<AccountItem>& items);
void recordAccount(vector<AccountItem>& items, string itemType);
void insertIntoFile(const AccountItem& item);


//��ѯ
void query(const vector<AccountItem> items);
void queryAll(const vector<AccountItem>& items);
void queryDetails(const vector<AccountItem>& items,string itemType);
void printItem(const AccountItem& item);

