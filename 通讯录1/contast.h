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

//ͨѶ¼������Ϣ
typedef struct PeoInfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;

//ͨѶ¼ - ��̬�汾
//typedef struct Contast
//{
//	PeoInfo date[MAX];//�����ӽ������˵���Ϣ
//	int sz;	//��¼ͨѶ¼�е�ǰ��Ч��Ϣ�ĸ���
//}Contast;

//ͨѶ¼ - ��̬�汾
typedef struct Contast
{
	PeoInfo* date ;//ָ��̬����Ŀռ䣬���������ϵ�˵���Ϣ
	int sz;//��¼ͨѶ¼�е�ǰ��Ч��Ϣ�ĸ���
	int capacity;//��¼��ǰͨѶ¼���������
}Contast;

//��ʼ��ͨѶ¼
void InitContast(Contast* pc);

//������ϵ��
void AddContast(Contast* pc);

//��ӡ��ϵ����Ϣ
void PrintContast(const Contast* pc);

//ɾ����ϵ����Ϣ
void DelContast(Contast* pc);

//������ϵ��
void SerchContast(Contast* pc);

//�޸���ϵ����Ϣ
void ModifyContast(Contast* pc);

//����ͨѶ¼
void DestoryContast(Contast* pc);

//������Ϣ���ļ�
void SaveContact(Contast* pc);

//�����ļ�
void LoadContact(Contast* pc);

//�Ƿ���Ҫ����
void CheckCapacity(Contast* pc);