#include <iostream>
#include <algorithm>

using namespace std;

class information
{
private:
	int age;
	string name;
	int index;

public:
	
	information()
	{
		this->age = 0;
		this->name = "";
		this->index = 0;
	}

	information(int a,string n, int i)
	{
		this->age = a;
		this->name = n;
		this->index = i;
	}

	~information(){}

	//setter
	void setter(int age, string name, int index)
	{
		this->age = age;
		this->name = name;
		this->index = index;
	}

	//getter
	int getage() { return age; }
	string getName() { return name; }
	int getIndex() { return index; }
	
	void printInfo()
	{
		cout << this->age << " " << this->name << '\n';
	}

};

int cmp(information a, information b)
{
	if (a.getage() == b.getage())
	{
		return a.getIndex() < b.getIndex();
	}
	else return a.getage() < b.getage();
}

int main()
{
	int n;
	cin >> n;

	information* ary = new information[n];

	int age;
	string name;

	for (int i = 0; i < n; i++)
	{
		cin >> age >> name;

		ary[i].setter(age, name, i);	
	}


	sort(ary, ary + n,cmp);


	for (int i = 0; i < n; i++)
	{
		ary[i].printInfo();
	}

	return 0;
}