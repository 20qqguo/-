#include<stdio.h>
#include<stdlib.h>
#include <conio.h>

//全局变量放置
int year,month,day;
//闰年和平年各月份的天数
int  runnian[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
int  pingnian[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
char xingqi[7][10]  ={"一","二","三","四","五","六","日"};
char xingqi_1[7][10]  ={"日","一","二","三","四","五","六"};

//函数声明
int runnian_judge(int year);
int before_day(int year, int month);
void mon_calendar(int year, int month);
void year_search();
void month_search();


//判断是否为闰年，返回1为闰年，0为平年
int runnian_judge(int year)
{
	//闰年要么可以被400整除，要么被4整除的同时不可以被100整除
	if( (year % 4 == 0 && year % 100 != 0) || year % 400 == 0 )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//1900年1月1日为周一，比较方便计算，以此为开始
int before_day(int year, int month)
{
	//定义年序列，月序列，之前的总天数
	int year_num, month_num, before_day_sum = 0;

	//计算年份到上一年
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

	//计算月份到上一个月
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

//打印月历 
void mon_calendar(int year, int month)
{
	int rest_day, huan_hang, i;

	//确定该月第一天前应空余多少天
	rest_day = before_day(year, month) % 7;
	//第一行什么时候换行
	huan_hang = 7 - rest_day;

	printf("---------------------------------------------------\n");
	printf("\t\t%d", year);
	printf("\t%d\n", month);
	printf("---------------------------------------------------\n");
	//打印日历头
	for(i = 0; i < 7; i++)
	{
		printf("%s\t",xingqi[i]);	
	}
	printf("\n");

	//打印空余天
	for(i = 0; i < rest_day; i++)
	{
		printf("\t");
	}

	//打印该月对应的天数，分闰年和平年
	if (runnian_judge(year) == 1)
	{
		//月份的数组索引0对应1月
		//每月日期从1号开始
		for(i = 1; i <= runnian[month-1]; i++)
		{
			printf("%d\t", i);
			//第一行换行与后面每7天换行
			if( i == huan_hang || (i-huan_hang)%7==0 )
			{
				printf("\n");
			}

		}
	}
	else
	{
		//月份的数组索引0对应1月
		//每月日期从1号开始
		for(i = 1; i <= pingnian[month-1]; i++)
		{
			printf("%d\t", i);
			//第一行换行与后面每7天换行
			if( i == huan_hang || (i-huan_hang)%7==0 )
			{
				printf("\n");
			}

		}
	}

	printf("\n---------------------------------------------------\n");

} 

//打印年历 
void year_calendar(int year)
{
	int i;
	for(int i = 1; i <= 12; i++)
	{
		mon_calendar(year, i);
		printf("\n");
	}
}

//查找年历
void year_search()
{
	int year;
	int flag_1 = 1, flag_2 = 1;

	printf("请输入年份：");
	scanf("%d", &year);
	system("cls");

		while (flag_1)
	{
		year_calendar(year);
		//进行方向键选择
		printf("可使用←、→方向键实现翻页，↑方向键退出\n");
		flag_2 = 1;
		while(flag_2)
		{
			//按下方向键，第一次会先返回224
			if(getch() == 224)
			{
				switch(getch())
				{
					//左方向键
					case 75:year -= 1;flag_2 = 0;break;
					//右方向键
					case 77:year += 1;flag_2 = 0;break;
					//上方向键
					case 72:flag_1 = 0;flag_2 = 0;break;
					default:break; //如果输入的值不规范，则需要重新输入

				}
			}
		}

		system("cls");
	}

}

//查找月历
void month_search()
{
	int year;
	int month;
	int flag_1 = 1, flag_2 = 1;

	printf("请输入年份：");
	scanf("%d", &year);
	system("cls");
	printf("请输入月份：");
	scanf("%d", &month);
	system("cls");

	while (flag_1)
	{
		mon_calendar(year, month);
		//进行方向键选择
		printf("可使用←、→方向键实现翻页，↑方向键退出\n");
		flag_2 = 1;
		while(flag_2)
		{
			//按下方向键，第一次会先返回224
			if(getch() == 224)
			{
				switch(getch())
				{
					//左方向键
					case 75:month -= 1;flag_2 = 0;break;
					//右方向键
					case 77:month += 1;flag_2 = 0;break;
					//上方向键
					case 72:flag_1 = 0;flag_2 = 0;break;
					default:break; //如果输入的值不规范，则需要重新输入

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

//查找日历
void day_search()
{
	int rest_day;
	int year, month, day;
	int flag_1 = 1, flag_2 = 1;

	printf("请输入年份：");
	scanf("%d", &year);
	system("cls");
	printf("请输入月份：");
	scanf("%d", &month);
	system("cls");
	printf("请输入几号：");
	scanf("%d", &day);
	system("cls");

	while (flag_1)
	{
		rest_day = before_day(year, month) % 7;
		printf("%d", year);
		printf("年");
		printf("%d", month);
		printf("月");
		printf("%d", day);
		printf("日是星期");
		printf("%s", xingqi_1[(rest_day+day)%7]);
		//进行方向键选择
		printf("\n可使用←、→方向键实现翻页，↑方向键退出\n");
		flag_2 = 1;
		while(flag_2)
		{
			//按下方向键，第一次会先返回224
			if(getch() == 224)
			{
				switch(getch())
				{
					//左方向键
					case 75:day -= 1;flag_2 = 0;break;
					//右方向键
					case 77:day += 1;flag_2 = 0;break;
					//上方向键
					case 72:flag_1 = 0;flag_2 = 0;break;
					default:break; //如果输入的值不规范，则需要重新输入

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
	//显示界面

	while (1)
	{
		//选择功能
		printf("--------------------------------------------------------\n");
		printf("                  Perpetual  Calendar\n");
		printf("                       1.年历\n");
		printf("                       2.月历\n");
		printf("                       3.日历\n");
		printf("--------------------------------------------------------\n");
		printf("选择你想要的功能：");
		scanf("%d", &function);

		//清屏并进行功能
		system("cls");
		switch(function)
		{
			case 1:year_search();break;

			case 2:month_search();break;

			case 3:day_search();break;

			default:printf("!!!!!!请输入1~3的数字以选择功能!!!!!!!\n"); 
				break;
		}


	}

	// //用户输入年 月 
	// printf("请输入年-月："); 
	// scanf("%d-%d",&year,&month);
	// printBegin();
	// int sum=daySum(year,month);
	// printResult(sum,year,month);
	// printStar();
	// system("pause");//防止闪屏 
	return 0;	
}
