#include <iostream>
using namespace std;


class Fraction
{
private:
	int numerator;
	int denominator;
public:
	int GetNum()
	{
		return numerator;
	}
	int GetDen()
	{
		return denominator;
	}
	void SetNum(int num)
	{
		numerator = num;
	}
	void SetDen(int den)
	{
		if (den != 0) denominator = den;
	}
	void Add()
	{
		cout << "Enter numerator: ";
		cin >> numerator;
		do
		{
			cout << "Enter denominator: ";
			cin >> denominator;
		} while (denominator == 0);
	}
	void Show()
	{
		cout << "Fraction " << numerator << "/" << denominator << endl;
	}

};

int main()
{

}