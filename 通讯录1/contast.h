#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30

#define DEFAULT_SZ 3
#define INC_SZ 2


#define MAX 1000

//通讯录个人信息
typedef struct PeoInfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;

//通讯录 - 静态版本
//typedef struct Contast
//{
//	PeoInfo date[MAX];//存放添加进来的人的信息
//	int sz;	//记录通讯录中当前有效信息的个数
//}Contast;

//通讯录 - 动态版本
typedef struct Contast
{
	PeoInfo* date ;//指向动态申请的空间，用来存放联系人的信息
	int sz;//记录通讯录中当前有效信息的个数
	int capacity;//记录当前通讯录的最大容量
}Contast;

//初始化通讯录
void InitContast(Contast* pc);

//增加联系人
void AddContast(Contast* pc);

//打印联系人信息
void PrintContast(const Contast* pc);

//删除联系人信息
void DelContast(Contast* pc);

//查找联系人
void SerchContast(Contast* pc);

//修改联系人信息
void ModifyContast(Contast* pc);

//销毁通讯录
void DestoryContast(Contast* pc);

//保存信息到文件
void SaveContact(Contast* pc);

//加载文件
void LoadContact(Contast* pc);

//是否需要增容
void CheckCapacity(Contast* pc);