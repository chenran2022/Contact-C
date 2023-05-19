#include"contast.h"

#define _CRT_SECURE_NO_WARNINGS 1

//通讯录﹣静态版本
//1．通讯录中能够存放1000个人的信息
//每个人的信息◇
//名字＋年龄＋性别＋电话＋地址
//2．增加人的信息
//3．删除指定人的信息
//4．修改指定人的信息
//5．查找指定人的信息
//6．排序通讯录的信息

//版本2
//动态增长的版本
//1＞通讯录初始化后,能存放3个人的信息
//2＞当我们空间的存放满的时候，我们增加2个信息

//版本3
//当通讯录退出的时候，把信息写到文件
//当通讯录初始化的时候，加载文件的信息到通讯录中


void menu()
{
	printf("**************************\n");
	printf("*****1.add      2.del*****\n");
	printf("*****3.serch    4.modify**\n");
	printf("*****5.sort     6.print***\n");
	printf("******   0.exit   ********\n");
	printf("**************************\n");
}
enum Option
{
	EXIT,
	add,
	del,
	serch,
	modify,
	sort,
	print
};
int main()
{
	int input;
	//创建通讯录
	Contast con;
	//初始化通讯录
	//给date申请一块连续的空间在堆区上
	//sz=0
	//capacity 当前的最大容量
	InitContast(&con);
	do
	{
		menu();
		printf("请选择:\n");
		scanf("%d", &input);
		switch (input)
		{
		case add:
			//增加人的信息
			AddContast(&con);
			break;
		case del:
			//删除
			DelContast(&con);
			break;
		case serch:
			//查找联系人
			SerchContast(&con);
			break;
		case modify:
			//修改联系人信息
			ModifyContast(&con);
			break;
		case sort:	
			//自我完善
			break;
		case print:
			//打印通讯录
			PrintContast(&con);
			break;
		case EXIT:
			//保存信息到文件
			SaveContact(&con);
			//销毁通讯录
			DestoryContast(&con);
			printf("退出通讯录\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}