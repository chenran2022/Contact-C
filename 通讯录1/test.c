#include"contast.h"

#define _CRT_SECURE_NO_WARNINGS 1

//ͨѶ¼����̬�汾
//1��ͨѶ¼���ܹ����1000���˵���Ϣ
//ÿ���˵���Ϣ��
//���֣����䣫�Ա𣫵绰����ַ
//2�������˵���Ϣ
//3��ɾ��ָ���˵���Ϣ
//4���޸�ָ���˵���Ϣ
//5������ָ���˵���Ϣ
//6������ͨѶ¼����Ϣ

//�汾2
//��̬�����İ汾
//1��ͨѶ¼��ʼ����,�ܴ��3���˵���Ϣ
//2�������ǿռ�Ĵ������ʱ����������2����Ϣ

//�汾3
//��ͨѶ¼�˳���ʱ�򣬰���Ϣд���ļ�
//��ͨѶ¼��ʼ����ʱ�򣬼����ļ�����Ϣ��ͨѶ¼��


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
	//����ͨѶ¼
	Contast con;
	//��ʼ��ͨѶ¼
	//��date����һ�������Ŀռ��ڶ�����
	//sz=0
	//capacity ��ǰ���������
	InitContast(&con);
	do
	{
		menu();
		printf("��ѡ��:\n");
		scanf("%d", &input);
		switch (input)
		{
		case add:
			//�����˵���Ϣ
			AddContast(&con);
			break;
		case del:
			//ɾ��
			DelContast(&con);
			break;
		case serch:
			//������ϵ��
			SerchContast(&con);
			break;
		case modify:
			//�޸���ϵ����Ϣ
			ModifyContast(&con);
			break;
		case sort:	
			//��������
			break;
		case print:
			//��ӡͨѶ¼
			PrintContast(&con);
			break;
		case EXIT:
			//������Ϣ���ļ�
			SaveContact(&con);
			//����ͨѶ¼
			DestoryContast(&con);
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);
	return 0;
}