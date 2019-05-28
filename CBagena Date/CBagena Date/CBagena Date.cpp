// clmdate.cpp : �������̨Ӧ�ó������ڵ㡣
#include "stdafx.h"
#include "iostream"
using namespace std;
class CBagena
{
private:
	int year;
	int month;
	int day;
	int check();

public:
	CBagena();
	CBagena(int y, int m, int d);
	int setDate(int y, int m, int d);
	void displayDate();
	void addOneDay();
	int getYear();
	int getMonth();
	int getDay();
	CBagena addDate(CBagena &od);         //   od3 = od1.addDate(od2);
	CBagena operator + (CBagena &otemp);   //	od3 = od1 + od2;
	CBagena operator + (const int &d);
};
CBagena CBagena::operator +(CBagena &otemp)
{
	CBagena temp;
	temp.setDate(year + otemp.year, month + otemp.month, day + otemp.day);
	return temp;
}
CBagena CBagena::operator + (const int &d)
{
	CBagena temp;
	temp.setDate(year, month, day + d);
	return temp;
}
CBagena CBagena::addDate(CBagena &od)
{
	CBagena temp;
	temp.setDate(year + od.year, month + od.month, day + od.day);
	return temp;
}
CBagena::CBagena()
{
	year = 2019;
	month = 1;
	day = 1;
}
CBagena::CBagena(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
	check();

}
int CBagena::setDate(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
	check();
	return 0;

}
void CBagena::displayDate()
{
	cout << year << "��" << month << "��" << day << "��" << endl;
}
int CBagena::check()
{
	int flatYearDays[13] = { 31,31,28,31,30,31,30,31,31,30,31,30,31 };
	int leapYearDays[13] = { 31,31,29,31,30,31,30,31,31,30,31,30,31 };
	int temp = 1;
	while (temp == 1 && month != 0 && day != 0)
	{
		if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
		{
			if (leapYearDays[month] < day)
			{
				day = day - leapYearDays[month];
				month++;
				temp = 1;
			}
			else
			{
				temp = 0;
			}
		}
		else
		{
			if (flatYearDays[month] < day)
			{
				day = day - flatYearDays[month];
				month++;
				temp = 1;
			}
			else
			{
				temp = 0;
			}
		}
		if (month > 12)
		{
			year++;
			month = month - 12;
			temp = 1;
		}
	}

	return 0;
}
int CBagena::getYear()
{
	return year;
}
int CBagena::getMonth()
{
	return month;
}
int CBagena::getDay()
{
	return day;
}
void CBagena::addOneDay()
{
	int flatYearDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int leapYearDays[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	day++;

	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
	{
		if (leapYearDays[month - 1] < day)
		{
			day = 1;
			month++;
		}
	}
	else
	{
		if (flatYearDays[month - 1] < day)
		{
			day = 1;
			month++;
		}
	}
	if (month > 12)
	{
		month = 1;
		year++;
	}

}
int main()
{
	CBagena od1(2019, 5, 27), od2(0, 0, 100), od3;
	//od3 = od1.addDate(od2);
	od3 = od1 + 100;
	od1.displayDate();
	od2.displayDate();
	od3.displayDate();

	return 0;
}