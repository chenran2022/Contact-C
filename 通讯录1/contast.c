#include "contast.h"

#define _CRT_SECURE_NO_WARNINGS 1



//��ʼ��ͨѶ¼ - ��̬�汾
//void InitContast(Contast* pc)
//{
//	pc->sz = 0;
//	memset(pc->date, 0, sizeof(pc->date));
//}

void LoadContact(Contast* pc)
{
	FILE* pf = fopen("contact.dat", "r");
	if (pf == NULL)
	{
		perror("fopen");
		return;
	}
	PeoInfo tmp = { 0 };
	while (fread(&tmp, sizeof(PeoInfo), 1, pf))
	{
		//�Ƿ���Ҫ����
		CheckCapacity(pc);
		pc->date[pc->sz] = tmp;
		pc->sz++;
	}
	fclose(pf);
	pf = NULL;
}
//��ʼ��ͨѶ¼ - ��̬�汾
void InitContast(Contast* pc)
{
	pc->date = (PeoInfo*)malloc(DEFAULT_SZ * sizeof(PeoInfo));
	if (pc->date == NULL)
	{
		perror("InitContast");
		return;
	}
	pc->sz = 0;
	pc->capacity = DEFAULT_SZ;
	memset(pc->date, 0, sizeof(pc->date));

	//�����ļ���ͨѶ¼
	LoadContact(pc);
}

//������ϵ�� - ��̬�汾
//void AddContast(Contast* pc)
//{
//	if (pc->sz == MAX)
//	{
//		printf("ͨѶ¼����,�޷����\n");
//		return;
//	}
//	//�����Ϣ
//	printf("��������ϵ������\n");
//	scanf("%s", pc->date[pc->sz].name);
//	printf("��������ϵ������\n");
//	scanf("%d", &(pc->date[pc->sz].age));
//	printf("��������ϵ���Ա�\n");
//	scanf("%s", pc->date[pc->sz].sex);
//	printf("��������ϵ�˵绰\n");
//	scanf("%s", pc->date[pc->sz].tele);
//	printf("��������ϵ�˵�ַ\n");
//	scanf("%s", pc->date[pc->sz].addr);
//	pc->sz++;
//	printf("��ӳɹ�\n");
//}

void CheckCapacity(Contast* pc)
{
	if (pc->sz == pc->capacity)
	{
		//����
		PeoInfo* ptr = (PeoInfo*)realloc(pc->date, (pc->capacity + INC_SZ) * sizeof(PeoInfo));
		if (ptr != NULL)
		{
			pc->date = ptr;
			pc->capacity = pc->capacity + INC_SZ;
			printf("���ݳɹ�\n");
		}
		else
		{
			perror("AddContast");
			printf("������ϵ��ʧ��\n");
			return;
		}
	}
}
//������ϵ�� - ��̬�汾
void AddContast(Contast* pc)
{
	//�Ƿ���Ҫ����
	CheckCapacity(pc);
	//�����Ϣ
	printf("��������ϵ������\n");
	scanf("%s", pc->date[pc->sz].name);
	printf("��������ϵ������\n");
	scanf("%d", &(pc->date[pc->sz].age));
	printf("��������ϵ���Ա�\n");
	scanf("%s", pc->date[pc->sz].sex);
	printf("��������ϵ�˵绰\n");
	scanf("%s", pc->date[pc->sz].tele);
	printf("��������ϵ�˵�ַ\n");
	scanf("%s", pc->date[pc->sz].addr);
	pc->sz++;
	printf("��ӳɹ�\n");
}

//��ӡ��ϵ����Ϣ
void PrintContast(const Contast* pc)
{
	int i = 0;
	//��ӡ����
	printf("%-20s\t%-5s\t%-5s\t%12s\t%20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	//��ӡ����
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-20s\t%-5d\t%-5s\t%12s\t%20s\n", pc->date[i].name,pc->date[i].age,pc->date[i].sex,pc->date[i].tele,pc->date[i].addr);
	}
}

//ɾ����ϵ����Ϣ
static int FindName(Contast* pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->date[i].name,name) == 0)
		{
			return i;
		}
	}
	return -1;
}
void DelContast(Contast* pc)
{
	char name[MAX_NAME] = { 0 };
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ��޷�ɾ��\n");
		return;
	}
	//����ɾ������
	printf("��������Ҫɾ��������\n");
	scanf("%s", name);
	//��/û��
	int pos = FindName(pc, name);
	if (pos == -1)
	{
		printf("û�д˶���\n");
		return;
	}
	int i = pos;
	for (i; i < pc->sz - 1; i++)
	{
		pc->date[i] = pc->date[i + 1];
	}
	pc->sz--;
	printf("ɾ���ɹ�\n");
	return;
}

//������ϵ��
void SerchContast(Contast* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("����������˵����֣�\n");
	scanf("%s", name);
	int pos = FindName(pc, name);
	if (pos == -1)
	{
		printf("���ҵ��˲�����\n");
		return;
	}
	printf("%-20s\t%-5s\t%-5s\t%12s\t%20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	//��ӡ����
	printf("%-20s\t%-5d\t%-5s\t%12s\t%20s\n", pc->date[pos].name, pc->date[pos].age, pc->date[pos].sex, pc->date[pos].tele, pc->date[pos].addr);
}

//�޸���ϵ����Ϣ
void ModifyContast(Contast* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ�޸��˵����֣�\n");
	scanf("%s", name);
	int pos = FindName(pc, name);
	if (pos == -1)
	{
		printf("�޸ĵ��˲�����\n");
		return;
	}
	printf("��������ϵ������\n");
	scanf("%s", pc->date[pos].name);
	printf("��������ϵ������\n");
	scanf("%d", &(pc->date[pos].age));
	printf("��������ϵ���Ա�\n");
	scanf("%s", pc->date[pos].sex);
	printf("��������ϵ�˵绰\n");
	scanf("%s", pc->date[pos].tele);
	printf("��������ϵ�˵�ַ\n");
	scanf("%s", pc->date[pos].addr);
	printf("�޸ĳɹ�\n");
}

//����ͨѶ¼ - ��̬�汾
void DestoryContast(Contast* pc)
{
	free(pc->date);
	pc->date = NULL;
	pc->capacity = 0;
	pc->sz = 0;
}

//������Ϣ���ļ�
void SaveContact(Contast* pc)
{
	FILE* pf = fopen("contact.dat", "w");
	if (pf == NULL)
	{
		perror("fopen");
		return;
	}
	//д�ļ�
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		fwrite(pc->date + i, sizeof(PeoInfo), 1, pf);
		//ֻ����fwrite������д��
		//fprintf(pf, ("%s %s %d %s %s", pc->date[i].name, pc->date[i].sex, pc->date[i].age, pc->date[i].tele, pc->date[i].addr));
	}
	fclose(pf);
	pf = NULL;
}