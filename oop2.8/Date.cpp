#include "Date.h"
Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
	N = 0;
}
Date::Date(int day, int month, int year, int N)
{
	this->day = day;
	this->month = month;
	this->year = year;
	this->N = N;
}
Date::Date(Date& d)
{
	day = d.day;
	month = d.month;
	year = d.year;
	N = d.N;
}
Date::~Date() { }

Date::Goods::Goods()
{
	name = "";
	price = 0;
	count = 0;
	number = 0;
	N = 0;
}
Date::Goods::Goods(string n, int p, int c, int num, int N)
{
	name = n;
	price = p;
	count = c;
	number = num;
	this->N = N;
}
Date::Goods::Goods(Goods& g)
{
	name = g.name;
	price = g.price;
	count = g.count;
	number = g.number;
	this->N = g.N;
}
Date::Goods::~Goods() { }

void Date::Menu()
{
	int n, MenuItem;
	Goods a; Date b;
	do {
		cout << " ������ ������� ����� �������: "; cin >> n;
		if (n < 0) { cout << " ������ ����� ����� �� ����" << endl << endl; }
	} while (n < 0);

	Goods* p = new Goods[n];
	p->SetN(n);
	Date* d = new Date[n];
	d->SetN(n);

	do {
		cout << endl << endl << endl;
		cout << "������� ��:" << endl << endl;
		cout << " [1] - �������� ����� � ���������" << endl;
		cout << " [2] - ���� ����� �� �����" << endl;
		cout << " [3] - ������ ������� ������" << endl;
		cout << " [4] - ������ ���� ������" << endl;
		cout << " [5] - ��������� � ������" << endl;
		cout << endl << endl;
		cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
		cout << "������ ��������: "; cin >> MenuItem;
		cout << endl << endl;

		switch (MenuItem)
		{
		case 1:
			cin >> p;
			cin >> d;
			break;
		case 2:
			cout << p;
			cout << d;
			break;
		case 3:
			int num_1; int value_1;
			do {
				cout << " ������ ����� �����: "; cin >> num_1;
				if (n < num_1)
				{
					cout << " ����� �� �������� " << num_1 << " �� ����! " << endl;
				}
			} while (n < num_1);
			cout << " ���� �������: "; cin >> value_1;
			a.ChangeCount(p, num_1 - 1, value_1);
			break;
		case 4:
			int num_2; int value_2;
			do {
				cout << " ������ ����� �����: "; cin >> num_2;
				if (n < num_2)
				{
					cout << " ����� �� �������� " << num_2 << " �� ����! " << endl;
				}
			} while (n < num_2);
			cout << " ���� ����: "; cin >> value_2;
			a.ChangePrice(p, num_2 - 1, value_2);
			break;
		case 5:
			b.WorkWithDate(d, n);
			break;
		case 0:
			break;
		default:
			cout << "�� ����� ��������� ��������! "
				"��� ������ ����� - ����� ��������� ������ ����" << endl;
		}
	} while (MenuItem != 0);
}

bool Date::Goods::Init(int Price, int Count, int Number)
{
	if (Price > 0)
	{
		SetPrice(Price);
		return true;
	}
	if (Count > 0)
	{
		SetCount(Count);
		return true;
	}
	if (Number > 0)
	{
		SetNumber(Number);
		return true;
	}
	else
		return false;
}

istream& operator >> (istream& in, Date::Goods* p)
{
	int i = 0;
	do {
		cout << " ����� � " << i + 1 << ":" << endl;
		in.get();
		in.sync();
		cout << " ����� ������: "; getline(in, p[i].name);
		cout << " ֳ��: "; in >> p[i].price;
		cout << " ʳ������: "; in >> p[i].count;
		cout << " ����� ��������: "; in >> p[i].number;
		cout << endl << endl;
		if (p->Init(p[i].price, p[i].count, p[i].number) == false)
		{
			cout << endl << " ������ �������� ��������! " << endl;
		}
		cout << endl;
		i++;
	} while ((i < p->N) && !p->Init(p[i].price, p[i].count, p[i].number));
	cout << endl;
	return in;
}

ostream& operator << (ostream& out, Date::Goods* r)
{
	int i = 0;
	cout << r[0].price << endl;
	out << "=================================================================================================="
		<< endl
		<< "|  �  |     �����     |      ʳ������      |     ֳ�� ��.    |    � ��������   |     ����      |"
		<< endl
		<< "=================================================================================================="
		<< endl;
	do {
		out << "| " << setw(3) << right << i + 1 << " "
			<< "| " << setw(14) << left << r[i].name
			<< "| " << setw(20) << left << r->ToString(r[i].count)
			<< "| " << setw(15) << right << r->ToString(r[i].price) << " |"
			<< setw(17) << right << r->ToString(r[i].number) << " |"
			<< setw(14) << right << r->ToString(r[i].price * r[i].count) << " |"
			<< endl
			<< "--------------------------------------------------------------------------------------------------"
			<< endl;
		i++;
	} while (i < r->N);
	return out;
}

string Date::Goods::ToString(int value)
{
	stringstream sstr;
	sstr << value;
	return sstr.str();
}

void Date::Goods::ChangePrice(Goods* p, int num, int value) { p[num].price = value; }

void Date::Goods::ChangeCount(Goods* p, int num, int value) { p[num].count = value; }

bool Date::Init(Goods goods, int day, int month, int year)
{

	if ((1 <= day && day <= 31) &&
		(1 <= month && month <= 12) &&
		(2000 <= year && year <= 3000))
	{
		SetGoods(goods);
		SetDay(day);
		SetMonth(month);
		SetYear(year);
		return true;
	}
	else
		return false;
}

istream& operator >> (istream& in, Date* d)
{
	int i = 0;
	Date::Goods a;
	do {
		cout << " ����� � " << i + 1 << endl;
		cout << " ������ ����: "; in >> d[i].day;
		cout << " ������ �����: "; in >> d[i].month;
		cout << " ������ ��: "; in >> d[i].year;
		cout << endl << endl;
		i++;
	} while ((i < d->GetN()) && d->Init(a, d[i].day, d[i].month, d[i].year) == false);
	cout << endl;
	return in;
}

ostream& operator << (ostream& out, Date* r)
{
	int i = 0;
	cout << "====================================="
		<< endl
		<< "|  �  |  ����  |  ̳����  |   г�   |"
		<< endl
		<< "====================================="
		<< endl;
	for (int i = 0; i < r->GetN(); i++)
	{
		out << "| " << setw(3) << right << i + 1 << " "
			<< "| " << setw(7) << left << r->GetGoods().ToString(r[i].day)
			<< "| " << setw(9) << left << r->GetGoods().ToString(r[i].month)
			<< "| " << setw(7) << right << r->GetGoods().ToString(r[i].year);
		if (!(r[i].year % 4)) { cout << "*"; } cout << " |" << endl;
		cout << "-------------------------------------" << endl;
	}
	return out;
}

string ToString(int value)
{
	stringstream sstr;
	sstr << value;
	return sstr.str();
}

void Date::WorkWithDate(Date* d, int N)
{
	int MenuItem;
	do {
		cout << endl << endl << endl;
		cout << "������� ��:" << endl << endl;
		cout << " [1] - ������ �� �� ���� ������" << endl;
		cout << " [2] - ³����� �� �� ���� ������" << endl;
		cout << " [3] - �������� ����� ������� ��� ������" << endl;
		cout << " [4] - ��������� ���" << endl;
		cout << " [5] - ��������� ������� ��� �� ������" << endl;
		cout << " [6] - ��������� ����� ����������" << endl;
		cout << endl << endl;
		cout << " [0] - ����� �� ���������� ������ ��� ������" << endl << endl;
		cout << "������ ��������: "; cin >> MenuItem;
		cout << endl << endl;
		switch (MenuItem)
		{
		case 1:
			int row1, value1;
			do {
				cout << " ������ ����� �����: "; cin >> row1;
				if (N < row1)
				{
					cout << " ����� �� �������� " << row1 << " �� ����! " << endl;
				}
			} while (N < row1);
			cout << " ʳ������ ���: "; cin >> value1;
			AddDay(d, row1 - 1, value1);
			break;
		case 2:
			int row2, value2;
			do {
				cout << " ������ ����� �����: "; cin >> row2;
				if (N < row2)
				{
					cout << " ����� �� �������� " << row2 << " �� ����! " << endl;
				}
			} while (N < row2);
			cout << " ʳ������ ���: "; cin >> value2;
			RemoveDay(d, row2 - 1, value2);
			break;
		case 3:
			int row3;
			do {
				cout << " ������ ����� �����: "; cin >> row3;
				if (N < row3)
				{
					cout << " ����� �� �������� " << row3 << " �� ����! " << endl;
				}
			} while (N < row3);
			PartOfDate(d, row3 - 1);
			break;
		case 4:
			int row_1, row_2;
			do {
				cout << " ������ ����� ����� 1: "; cin >> row_1;
				cout << " ������ ����� ����� 2: "; cin >> row_2;
				if (N < row_1)
				{
					cout << " ����� �� �������� " << row_1 << " �� ����! " << endl;
				}
				if (N < row_2)
				{
					cout << " ����� �� �������� " << row_2 << " �� ����! " << endl;
				}
			} while (N < row_1 || N < row_2);
			ComparisonDate(d, row_1 - 1, row_2 - 1);
			break;
		case 5:
			int row_3, row_4;
			do {
				cout << " ������ ����� ����� 1: "; cin >> row_3;
				cout << " ������ ����� ����� 2: "; cin >> row_4;
				if (N < row_3)
				{
					cout << " ����� �� �������� " << row_3 << " �� ����! " << endl;
				}
				if (N < row_4)
				{
					cout << " ����� �� �������� " << row_4 << " �� ����! " << endl;
				}
			} while (N < row_3 || N < row_4);
			cout << " ��������� ���������(������� ������� � �������� ���): " << Diff(d, row_3 - 1, row_4 - 1);
			break;
		case 6:
			int row_5, dday, yyear, mmonth;
			do {
				cout << " ������ ����� �����: "; cin >> row_5;
				if (N < row_5)
				{
					cout << " ����� �� �������� " << row_5 << " �� ����! " << endl;
				}
			} while (N < row_5);
			cout << " ������ ����, ���� ���������� ����� ����������: " << endl;
			do {
				cout << " ���� - ? "; cin >> dday;
				if (!(dday <= 31 && dday >= 1))
				{
					cout << " ������� ������� ����" << endl;
				}
			} while (!(dday <= 31 && dday >= 1));
			do {
				cout << " ̳���� - ? "; cin >> mmonth;
				if (!(mmonth <= 12 && mmonth >= 1))
				{
					cout << " ������� ������� �����" << endl;
				}
			} while (!(mmonth <= 12 && mmonth >= 1));
			do {
				cout << " г� - ? "; cin >> yyear;
				if (!(year <= 366 && yyear >= 1))
				{
					cout << " ������� ������� ��" << endl;
				}
			} while (!(year <= 366 && yyear >= 1));
			cout << " �� ���� ������ ���������� - " << ExpirationDate(d, row_5 - 1, dday, mmonth, yyear) << " ���." << endl;
		case 0:
			break;
		default:
			cout << "�� ����� ��������� ��������! "
				"��� ������ ����� - ����� ��������� ������ ����" << endl;
		}
	} while (MenuItem != 0);
}

void Date::AddDay(Date* d, int row, int value)
{
	if (d[row].month == 1 || d[row].month == 3 ||
		d[row].month == 5 || d[row].month == 7 ||
		d[row].month == 8 || d[row].month == 10 ||
		d[row].month == 12)
	{
		d[row].day += value;
		if (d[row].day > 31)
		{
			int a;
			a = d[row].day - 31;
			d[row].day = 0;
			d[row].day += a;
			d[row].month++;
			if (d[row].month > 12)
			{
				int b;
				b = d[row].month - 12;
				d[row].month = 0;
				d[row].month += b;
				d[row].year++;
			}
		}
	}
	else
		if (d[row].month == 4 || d[row].month == 6 ||
			d[row].month == 9 || d[row].month == 11)
		{
			d[row].day += value;
			if (d[row].day > 30)
			{
				int a;
				a = d[row].day - 30;
				d[row].day = 0;
				d[row].day += a;
				d[row].month++;
				if (d[row].month > 12)
				{
					int b;
					b = d[row].month - 12;
					d[row].month = 0;
					d[row].month += b;
					d[row].year++;
				}
			}
		}
		else
			if (d[row].month == 2 && !(d[row].year % 4))
			{
				d[row].day += value;
				if (d[row].day > 29)
				{
					int a;
					a = d[row].day - 29;
					d[row].day = 0;
					d[row].day += a;
					d[row].month++;
					if (d[row].month > 12)
					{
						int b;
						b = d[row].month - 12;
						d[row].month = 0;
						d[row].month += b;
						d[row].year++;
					}
				}
			}
			else {
				d[row].day += value;
				if (d[row].day > 28)
				{
					int a;
					a = d[row].day - 28;
					d[row].day = 0;
					d[row].day += a;
					d[row].month++;
					if (d[row].month > 12)
					{
						int b;
						b = d[row].month - 12;
						d[row].month = 0;
						d[row].month += b;
						d[row].year++;
					}
				}
			}
}

void Date::RemoveDay(Date* d, int row, int value)
{
	if (d[row].month == 1 || d[row].month == 3 ||
		d[row].month == 5 || d[row].month == 7 ||
		d[row].month == 8 || d[row].month == 10 ||
		d[row].month == 12)
	{
		d[row].day -= value;
		if (d[row].day < 1)
		{
			int a;
			a = d[row].day + 31;
			d[row].day = 0;
			d[row].day += a;
			d[row].month--;
			if (d[row].month < 1)
			{
				int b;
				b = d[row].month + 12;
				d[row].month = 0;
				d[row].month += b;
				d[row].year--;
			}
		}
	}
	else
		if (d[row].month == 4 || d[row].month == 6 ||
			d[row].month == 9 || d[row].month == 11)
		{
			d[row].day -= value;
			if (d[row].day < 1)
			{
				int a;
				a = d[row].day + 30;
				d[row].day = 0;
				d[row].day += a;
				d[row].month--;
				if (d[row].month < 1)
				{
					int b;
					b = d[row].month + 12;
					d[row].month = 0;
					d[row].month += b;
					d[row].year--;
				}
			}
		}
		else
			if (d[row].month == 2 && !(d[row].year % 4))
			{

				d[row].day -= value;
				if (d[row].day < 1)
				{
					int a;
					a = d[row].day + 29;
					d[row].day = 0;
					d[row].day += a;
					d[row].month--;
					if (d[row].month < 1)
					{
						int b;
						b = d[row].month + 12;
						d[row].month = 0;
						d[row].month += b;
						d[row].year--;
					}
				}
			}
			else {
				d[row].day -= value;
				if (d[row].day < 1)
				{
					int a;
					a = d[row].day + 28;
					d[row].day = 0;
					d[row].day += a;
					d[row].month--;
					if (d[row].month < 1)
					{
						int b;
						b = d[row].month + 12;
						d[row].month = 0;
						d[row].month += b;
						d[row].year--;
					}
				}
			}
}

void Date::PartOfDate(Date* d, int row)
{
	int MenuItem;
	do {
		cout << endl << endl << endl;
		cout << "������� ��:" << endl << endl;
		cout << " [1] - ����" << endl;
		cout << " [2] - ̳����" << endl;
		cout << " [3] - г�" << endl;
		cout << endl << endl;
		cout << " [0] - ����� �� ���������� ������ ��� ������" << endl << endl;
		cout << "������ ��������: "; cin >> MenuItem;
		cout << endl << endl;
		switch (MenuItem)
		{
		case 1:
			cout << " ���� - " << d[row].day << endl;
			break;
		case 2:
			cout << " ̳���� - " << d[row].month << endl;
			break;
		case 3:
			cout << " г� - " << d[row].year; if (!(d[row].year % 4)) { cout << "*"; }
			cout << endl;
			break;
		case 0:
			break;
		default:
			cout << "�� ����� ��������� ��������! "
				"��� ������ ����� - ����� ��������� ������ ����" << endl;
		}
	} while (MenuItem != 0);
}

void Date::ComparisonDate(Date* d, int row1, int row2)
{
	cout << endl;
	if (d[row1].year > d[row2].year)
	{
		cout << " ���� 1 - " << d[row1].day << "." << d[row1].month << "." << d[row1].year; if (!(d[row1].year % 4)) { cout << "*"; }
		cout << " > ���� 2 - " << d[row2].day << "." << d[row2].month << "." << d[row2].year; if (!(d[row2].year % 4)) { cout << "*"; }
		cout << endl;
	}
	else
		if (d[row1].month > d[row2].month)
		{
			cout << " ���� 1 - " << d[row1].day << "." << d[row1].month << "." << d[row1].year; if (!(d[row1].year % 4)) { cout << "*"; }
			cout << " > ���� 2 - " << d[row2].day << "." << d[row2].month << "." << d[row2].year; if (!(d[row2].year % 4)) { cout << "*"; }
			cout << endl;
		}
		else
			if (d[row1].day > d[row2].day)
			{
				cout << " ���� 1 - " << d[row1].day << "." << d[row1].month << "." << d[row1].year; if (!(d[row1].year % 4)) { cout << "*"; }
				cout << " > ���� 2 - " << d[row2].day << "." << d[row2].month << "." << d[row2].year; if (!(d[row2].year % 4)) { cout << "*"; }
				cout << endl;
			}
			else
				if (d[row2].year > d[row1].year)
				{
					cout << " ���� 2 - " << d[row2].day << "." << d[row2].month << "." << d[row2].year; if (!(d[row2].year % 4)) { cout << "*"; }
					cout << " > ���� 1 - " << d[row1].day << "." << d[row1].month << "." << d[row1].year; if (!(d[row1].year % 4)) { cout << "*"; }
					cout << endl;
				}
				else
					if (d[row2].month > d[row1].month)
					{
						cout << " ���� 2 - " << d[row2].day << "." << d[row2].month << "." << d[row2].year; if (!(d[row2].year % 4)) { cout << "*"; }
						cout << " > ���� 1 - " << d[row1].day << "." << d[row1].month << "." << d[row1].year; if (!(d[row1].year % 4)) { cout << "*"; }
						cout << endl;
					}
					else
						if (d[row2].day > d[row1].day)
						{
							cout << " ���� 2 - " << d[row2].day << "." << d[row2].month << "." << d[row2].year; if (!(d[row2].year % 4)) { cout << "*"; }
							cout << " > ���� 1 - " << d[row1].day << "." << d[row1].month << "." << d[row1].year; if (!(d[row1].year % 4)) { cout << "*"; }
							cout << endl;
						}
						else
							if (d[row2].year == d[row1].year &&
								d[row2].month == d[row1].month &&
								d[row2].day == d[row1].day)
							{
								cout << " ���� 1 - " << d[row1].day << "." << d[row1].month << "." << d[row1].year; if (!(d[row1].year % 4)) { cout << "*"; }
								cout << " = ���� 2 - " << d[row2].day << "." << d[row2].month << "." << d[row2].year; if (!(d[row2].year % 4)) { cout << "*"; }
								cout << endl;
							}
}

int Date::Diff(Date* d, int row1, int row2)
{
	int a = 0, b = 0, c = 0;
	if (d[row1].year == d[row2].year) { a = 0; }
	if (d[row1].month == d[row2].month) { b = 0; }
	if (d[row1].day == d[row2].day) { c = 0; }
	if (d[row1].year > d[row2].year)
	{
		a = d[row1].year - d[row2].year;
		a *= 365;

		if (!(d[row1].year % 4) && !(d[row2].year % 4))
			a *= 366;
	}
	else
		if (d[row1].month > d[row2].month)
		{
			b = d[row1].month - d[row2].month;
			b *= 31;
		}
		else
			if (d[row1].day > d[row2].day)
			{
				c = d[row1].day - d[row2].day;
			}

	if (d[row1].year < d[row2].year)
	{
		a = d[row2].year - d[row1].year;
		a *= 365;

		if (!(d[row1].year % 4) && !(d[row2].year % 4))
			a *= 366;
	}
	else
		if (d[row1].month < d[row2].month)
		{
			b = d[row2].month - d[row1].month;
			b *= 31;
		}
		else
			if (d[row1].day < d[row2].day)
			{
				c = d[row2].day - d[row1].day;
			}
	return a + b + c;
}

int Date::ExpirationDate(Date* d, int row, int dday, int mmonth, int yyear)
{
	int a = 0, b = 0, c = 0;
	if (d[row].year == yyear) { a = 0; }
	if (d[row].month == mmonth) { b = 0; }
	if (d[row].day == dday) { c = 0; }
	if (d[row].year > yyear)
	{
		a = d[row].year - yyear;
		a *= 365;

		if (!(d[row].year % 4) && !(yyear % 4))
			a *= 366;
	}
	else
		if (d[row].month > mmonth)
		{
			b = d[row].month - mmonth;
			b *= 31;
		}
		else
			if (d[row].day > dday)
			{
				c = d[row].day - dday;
			}
			else
				if (d[row].year < yyear)
				{
					a = yyear - d[row].year;
					a *= 365;

					if (!(d[row].year % 4) && !(yyear % 4))
						a *= 366;
				}
				else
					if (d[row].month < mmonth)
					{
						b = mmonth - d[row].month;
						b *= 31;
					}
					else
						if (d[row].day < dday)
						{
							c = dday - d[row].day;
						}

	return a + b + c;
}