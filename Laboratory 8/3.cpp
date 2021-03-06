#include <iostream>
#include <string>

using namespace std;

class publication
{
	string title;
	float price;
public:
	void getdata()
	{
		cout << "\nEnter title:"; cin >> title;
		cout << "Enter price:"; cin >> price;
	}
	void putdata() const
	{
		cout << "\nTitle:" << title;
		cout << "\nPrice:" << price;
	}
};

class sales
{
	enum { MONTHS = 3 };
	float salesArr[MONTHS];
public:
	void getdata()
	{
		cout << "Enter sales for 3 months\n";
		for(int j=0; j<MONTHS; j++)
		{
			cout << "      Month " << j+1 << ":";
			cin >> salesArr[j];
		}
	}
	void putdata() const
	{
		for(int j=0; j<MONTHS; j++)
		{
			cout << "\n   Sales for month " << j+1 << ": ";
			cout << salesArr[j];
		}
	}
};

class book : private publication, private sales
{
	int pages;
public:
	void getdata()
	{
		publication::getdata();
		cout << "Enter number of pages:"; cin >> pages;
		sales::getdata();
	}
	void putdata() const
	{
		publication::putdata();
		cout << "\nPages: " << pages;
		sales::putdata();
	}
};

class tape : private publication, private sales
{
	float time;
public:
	void getdata()
	{
		publication::getdata();
		cout << "Enter playing time:"; cin >> time;
		sales::getdata();
	}
	void putdata() const
	{
		publication::putdata();
		cout << "\nPlaying time: " << time;
		sales::putdata();
	}
};

int main()
{
	book book1;
	tape tape1;

	book1.getdata();
	tape1.getdata();

	book1.putdata();
	tape1.putdata();
	cout << endl;
	return 0;
}