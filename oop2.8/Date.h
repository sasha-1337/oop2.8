#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <Windows.h>

using namespace std;

class Date
{
private:
	int day, month, year;
	int N;
public:
	class Goods
	{
	private:
		string name;
		int price;
		int count;
		int number;
		int N; // кількість рядків
	public:
		int GetN() { return N; }
		void SetN(int N) { this->N = N; }
		Goods();
		Goods(string, int, int, int, int);
		Goods(Goods&);
		~Goods();
		string GetName() const { return name; }
		int GetPrice() const { return price; }
		int GetCount() const { return count; }
		int GetNumder() const { return number; }

		void SetName(string name) { this->name = name; }
		void SetPrice(int price) { this->price = price; }
		void SetCount(int count) { this->count = count; }
		void SetNumber(int number) { this->number = number; }

		friend ostream& operator << (ostream&, Goods*);
		friend istream& operator >> (istream&, Goods*);
		string ToString(int value);

		bool Init(int Price, int Count, int Number);
		void ChangePrice(Goods* p, int num, int value);
		void ChangeCount(Goods* p, int num, int value);
	};
private:
	Goods goods;
public:
	Date();
	Date(int, int, int, int);
	Date(Date&);
	~Date();
	Goods GetGoods() { return goods; }
	int GetDay() const { return day; }
	int GetMonth() const { return month; }
	int GetYear() const { return year; }
	int GetN() { return N; }

	void SetN(int N) { this->N = N; }
	void SetGoods(Goods goods) { this->goods = goods; }
	void SetDay(int day) { this->day = day; }
	void SetMonth(int month) { this->month = month; }
	void SetYear(int year) { this->year = year; }

	void Menu();
	bool Init(Goods goods, int day, int month, int year);
	friend istream& operator >> (istream& in, Date*);
	friend ostream& operator << (ostream& out, Date*);
	string ToString(int value);
	void WorkWithDate(Date* d, int N);
	void AddDay(Date* d, int row, int value);
	void RemoveDay(Date* d, int row, int value);
	void PartOfDate(Date* d, int row);
	void ComparisonDate(Date* d, int row1, int row2);
	int Diff(Date* d, int row1, int row2);
	int ExpirationDate(Date* p, int row, int dday, int mmonth, int yyear);
};