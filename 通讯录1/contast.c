#include "contast.h"

#define _CRT_SECURE_NO_WARNINGS 1



//初始化通讯录 - 静态版本
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
		//是否需要增容
		CheckCapacity(pc);
		pc->date[pc->sz] = tmp;
		pc->sz++;
	}
	fclose(pf);
	pf = NULL;
}
//初始化通讯录 - 动态版本
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

	//加载文件到通讯录
	LoadContact(pc);
}

//增加联系人 - 静态版本
//void AddContast(Contast* pc)
//{
//	if (pc->sz == MAX)
//	{
//		printf("通讯录已满,无法添加\n");
//		return;
//	}
//	//添加信息
//	printf("请输入联系人姓名\n");
//	scanf("%s", pc->date[pc->sz].name);
//	printf("请输入联系人年龄\n");
//	scanf("%d", &(pc->date[pc->sz].age));
//	printf("请输入联系人性别\n");
//	scanf("%s", pc->date[pc->sz].sex);
//	printf("请输入联系人电话\n");
//	scanf("%s", pc->date[pc->sz].tele);
//	printf("请输入联系人地址\n");
//	scanf("%s", pc->date[pc->sz].addr);
//	pc->sz++;
//	printf("添加成功\n");
//}

void CheckCapacity(Contast* pc)
{
	if (pc->sz == pc->capacity)
	{
		//增容
		PeoInfo* ptr = (PeoInfo*)realloc(pc->date, (pc->capacity + INC_SZ) * sizeof(PeoInfo));
		if (ptr != NULL)
		{
			pc->date = ptr;
			pc->capacity = pc->capacity + INC_SZ;
			printf("增容成功\n");
		}
		else
		{
			perror("AddContast");
			printf("增加联系人失败\n");
			return;
		}
	}
}
//增加联系人 - 动态版本
void AddContast(Contast* pc)
{
	//是否需要增容
	CheckCapacity(pc);
	//添加信息
	printf("请输入联系人姓名\n");
	scanf("%s", pc->date[pc->sz].name);
	printf("请输入联系人年龄\n");
	scanf("%d", &(pc->date[pc->sz].age));
	printf("请输入联系人性别\n");
	scanf("%s", pc->date[pc->sz].sex);
	printf("请输入联系人电话\n");
	scanf("%s", pc->date[pc->sz].tele);
	printf("请输入联系人地址\n");
	scanf("%s", pc->date[pc->sz].addr);
	pc->sz++;
	printf("添加成功\n");
}

//打印联系人信息
void PrintContast(const Contast* pc)
{
	int i = 0;
	//打印标题
	printf("%-20s\t%-5s\t%-5s\t%12s\t%20s\n", "名字", "年龄", "性别", "电话", "地址");
	//打印数据
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-20s\t%-5d\t%-5s\t%12s\t%20s\n", pc->date[i].name,pc->date[i].age,pc->date[i].sex,pc->date[i].tele,pc->date[i].addr);
	}
}

//删除联系人信息
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
		printf("通讯录为空，无法删除\n");
		return;
	}
	//查找删除对象
	printf("请输入想要删除的名字\n");
	scanf("%s", name);
	//有/没有
	int pos = FindName(pc, name);
	if (pos == -1)
	{
		printf("没有此对象\n");
		return;
	}
	int i = pos;
	for (i; i < pc->sz - 1; i++)
	{
		pc->date[i] = pc->date[i + 1];
	}
	pc->sz--;
	printf("删除成功\n");
	return;
}

//查找联系人
void SerchContast(Contast* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入查找人的名字：\n");
	scanf("%s", name);
	int pos = FindName(pc, name);
	if (pos == -1)
	{
		printf("查找的人不存在\n");
		return;
	}
	printf("%-20s\t%-5s\t%-5s\t%12s\t%20s\n", "名字", "年龄", "性别", "电话", "地址");
	//打印数据
	printf("%-20s\t%-5d\t%-5s\t%12s\t%20s\n", pc->date[pos].name, pc->date[pos].age, pc->date[pos].sex, pc->date[pos].tele, pc->date[pos].addr);
}

//修改联系人信息
void ModifyContast(Contast* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入要修改人的名字：\n");
	scanf("%s", name);
	int pos = FindName(pc, name);
	if (pos == -1)
	{
		printf("修改的人不存在\n");
		return;
	}
	printf("请输入联系人姓名\n");
	scanf("%s", pc->date[pos].name);
	printf("请输入联系人年龄\n");
	scanf("%d", &(pc->date[pos].age));
	printf("请输入联系人性别\n");
	scanf("%s", pc->date[pos].sex);
	printf("请输入联系人电话\n");
	scanf("%s", pc->date[pos].tele);
	printf("请输入联系人地址\n");
	scanf("%s", pc->date[pos].addr);
	printf("修改成功\n");
}

//销毁通讯录 - 动态版本
void DestoryContast(Contast* pc)
{
	free(pc->date);
	pc->date = NULL;
	pc->capacity = 0;
	pc->sz = 0;
}

//保存信息到文件
void SaveContact(Contast* pc)
{
	FILE* pf = fopen("contact.dat", "w");
	if (pf == NULL)
	{
		perror("fopen");
		return;
	}
	//写文件
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		fwrite(pc->date + i, sizeof(PeoInfo), 1, pf);
		//只能用fwrite二进制写入
		//fprintf(pf, ("%s %s %d %s %s", pc->date[i].name, pc->date[i].sex, pc->date[i].age, pc->date[i].tele, pc->date[i].addr));
	}
	fclose(pf);
	pf = NULL;
}