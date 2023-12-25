#include<stdio.h>
#include<stdlib.h>
#include <conio.h>

//ȫ�ֱ�������
int year,month,day;
//�����ƽ����·ݵ�����
int  runnian[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
int  pingnian[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
char xingqi[7][10]  ={"һ","��","��","��","��","��","��"};
char xingqi_1[7][10]  ={"��","һ","��","��","��","��","��"};

//��������
int runnian_judge(int year);
int before_day(int year, int month);
void mon_calendar(int year, int month);
void year_search();
void month_search();


//�ж��Ƿ�Ϊ���꣬����1Ϊ���꣬0Ϊƽ��
int runnian_judge(int year)
{
	//����Ҫô���Ա�400������Ҫô��4������ͬʱ�����Ա�100����
	if( (year % 4 == 0 && year % 100 != 0) || year % 400 == 0 )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//1900��1��1��Ϊ��һ���ȽϷ�����㣬�Դ�Ϊ��ʼ
int before_day(int year, int month)
{
	//���������У������У�֮ǰ��������
	int year_num, month_num, before_day_sum = 0;

	//������ݵ���һ��
	for(year_num = 1900; year_num<year; year_num++)	
	{
		
		{	
			if(runnian_judge(year_num))
			{
				before_day_sum += 366;
			}
			else
			{
				before_day_sum += 365;	
			} 
		} 
	}

	//�����·ݵ���һ����
	for(month_num = 0; month_num<month-1; month_num++)
	{
		if(runnian_judge(year_num))
		{
			before_day_sum += runnian[month_num];	
		} 
		else
		{
			before_day_sum += pingnian[month_num];
		}
	}

	return before_day_sum;
} 

//��ӡ���� 
void mon_calendar(int year, int month)
{
	int rest_day, huan_hang, i;

	//ȷ�����µ�һ��ǰӦ���������
	rest_day = before_day(year, month) % 7;
	//��һ��ʲôʱ����
	huan_hang = 7 - rest_day;

	printf("---------------------------------------------------\n");
	printf("\t\t%d", year);
	printf("\t%d\n", month);
	printf("---------------------------------------------------\n");
	//��ӡ����ͷ
	for(i = 0; i < 7; i++)
	{
		printf("%s\t",xingqi[i]);	
	}
	printf("\n");

	//��ӡ������
	for(i = 0; i < rest_day; i++)
	{
		printf("\t");
	}

	//��ӡ���¶�Ӧ���������������ƽ��
	if (runnian_judge(year) == 1)
	{
		//�·ݵ���������0��Ӧ1��
		//ÿ�����ڴ�1�ſ�ʼ
		for(i = 1; i <= runnian[month-1]; i++)
		{
			printf("%d\t", i);
			//��һ�л��������ÿ7�컻��
			if( i == huan_hang || (i-huan_hang)%7==0 )
			{
				printf("\n");
			}

		}
	}
	else
	{
		//�·ݵ���������0��Ӧ1��
		//ÿ�����ڴ�1�ſ�ʼ
		for(i = 1; i <= pingnian[month-1]; i++)
		{
			printf("%d\t", i);
			//��һ�л��������ÿ7�컻��
			if( i == huan_hang || (i-huan_hang)%7==0 )
			{
				printf("\n");
			}

		}
	}

	printf("\n---------------------------------------------------\n");

} 

//��ӡ���� 
void year_calendar(int year)
{
	int i;
	for(int i = 1; i <= 12; i++)
	{
		mon_calendar(year, i);
		printf("\n");
	}
}

//��������
void year_search()
{
	int year;
	int flag_1 = 1, flag_2 = 1;

	printf("��������ݣ�");
	scanf("%d", &year);
	system("cls");

		while (flag_1)
	{
		year_calendar(year);
		//���з����ѡ��
		printf("��ʹ�á����������ʵ�ַ�ҳ����������˳�\n");
		flag_2 = 1;
		while(flag_2)
		{
			//���·��������һ�λ��ȷ���224
			if(getch() == 224)
			{
				switch(getch())
				{
					//�����
					case 75:year -= 1;flag_2 = 0;break;
					//�ҷ����
					case 77:year += 1;flag_2 = 0;break;
					//�Ϸ����
					case 72:flag_1 = 0;flag_2 = 0;break;
					default:break; //��������ֵ���淶������Ҫ��������

				}
			}
		}

		system("cls");
	}

}

//��������
void month_search()
{
	int year;
	int month;
	int flag_1 = 1, flag_2 = 1;

	printf("��������ݣ�");
	scanf("%d", &year);
	system("cls");
	printf("�������·ݣ�");
	scanf("%d", &month);
	system("cls");

	while (flag_1)
	{
		mon_calendar(year, month);
		//���з����ѡ��
		printf("��ʹ�á����������ʵ�ַ�ҳ����������˳�\n");
		flag_2 = 1;
		while(flag_2)
		{
			//���·��������һ�λ��ȷ���224
			if(getch() == 224)
			{
				switch(getch())
				{
					//�����
					case 75:month -= 1;flag_2 = 0;break;
					//�ҷ����
					case 77:month += 1;flag_2 = 0;break;
					//�Ϸ����
					case 72:flag_1 = 0;flag_2 = 0;break;
					default:break; //��������ֵ���淶������Ҫ��������

				}
			}
		}

		if(month<1)
		{
			year -= 1;
			month = 12;
		}
		if(month>12)
		{
			year += 1;
			month = 1;
		}
		system("cls");
	}
}

//��������
void day_search()
{
	int rest_day;
	int year, month, day;
	int flag_1 = 1, flag_2 = 1;

	printf("��������ݣ�");
	scanf("%d", &year);
	system("cls");
	printf("�������·ݣ�");
	scanf("%d", &month);
	system("cls");
	printf("�����뼸�ţ�");
	scanf("%d", &day);
	system("cls");

	while (flag_1)
	{
		rest_day = before_day(year, month) % 7;
		printf("%d", year);
		printf("��");
		printf("%d", month);
		printf("��");
		printf("%d", day);
		printf("��������");
		printf("%s", xingqi_1[(rest_day+day)%7]);
		//���з����ѡ��
		printf("\n��ʹ�á����������ʵ�ַ�ҳ����������˳�\n");
		flag_2 = 1;
		while(flag_2)
		{
			//���·��������һ�λ��ȷ���224
			if(getch() == 224)
			{
				switch(getch())
				{
					//�����
					case 75:day -= 1;flag_2 = 0;break;
					//�ҷ����
					case 77:day += 1;flag_2 = 0;break;
					//�Ϸ����
					case 72:flag_1 = 0;flag_2 = 0;break;
					default:break; //��������ֵ���淶������Ҫ��������

				}
			}
		}

		if(runnian_judge(year))
		{
			if(day > runnian[month-1])
			{
				day = 1;
				month += 1;
			}
			if(day < 1)
			{
				day = runnian[month-2];
				month -= 1;
			}
		}
		else
		{
			if(day > pingnian[month-1])
			{
				day = 1;
				month += 1;
			}
			if(day < 1)
			{
				day = pingnian[month-2];
				month -= 1;
			}
		}

		if(month<1)
		{
			year -= 1;
			month = 12;
			day = 31;
		}
		if(month>12)
		{
			year += 1;
			month = 1;
		}
		system("cls");
	}

}


int main(void)
{

	int function;
	//��ʾ����

	while (1)
	{
		//ѡ����
		printf("--------------------------------------------------------\n");
		printf("                  Perpetual  Calendar\n");
		printf("                       1.����\n");
		printf("                       2.����\n");
		printf("                       3.����\n");
		printf("--------------------------------------------------------\n");
		printf("ѡ������Ҫ�Ĺ��ܣ�");
		scanf("%d", &function);

		//���������й���
		system("cls");
		switch(function)
		{
			case 1:year_search();break;

			case 2:month_search();break;

			case 3:day_search();break;

			default:printf("!!!!!!������1~3��������ѡ����!!!!!!!\n"); 
				break;
		}


	}

	// //�û������� �� 
	// printf("��������-�£�"); 
	// scanf("%d-%d",&year,&month);
	// printBegin();
	// int sum=daySum(year,month);
	// printResult(sum,year,month);
	// printStar();
	// system("pause");//��ֹ���� 
	return 0;	
}
