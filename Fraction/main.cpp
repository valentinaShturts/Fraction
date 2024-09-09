#include <iostream>
using namespace std;


class Fraction
{
	//змінні знаменика та чисельника
private:
	int numerator;
	int denominator;
	//методи для роботи з цими змінними
public:
	//гетер для чисельника
	int GetNum()
	{
		return numerator;
	}
	//гетер для знаменника
	int GetDen()
	{
		return denominator;
	}
	//сетер дробу
	void SetFraction(int num, int den)
	{
		numerator = num;
		if (den != 0) denominator = den;
		Simplify(numerator, denominator);
	}
	//ф-ія створення дробу з перевіркою знаменника на 0
	void Add()
	{
		cout << "Enter numerator: ";
		cin >> numerator;
		do
		{
			cout << "Enter denominator: ";
			cin >> denominator;
		} while (denominator == 0);

		Simplify(numerator, denominator); //скорочення дробу
	}
	//НСД 
	int GCD(int num, int den)
	{
		if (den == 0) return num;
		return GCD(den, num % den);
	}
	//ф-ія скорочення дробу
	void Simplify(int& numerator, int& denominator)
	{
		int divisor = GCD(numerator, denominator);
		numerator /= divisor;
		denominator /= divisor;
	}
	//ф-ія додавання дробів
	Fraction Addition(Fraction b)
	{
		Fraction rez;
		rez.numerator = (numerator * b.denominator) + (b.numerator * denominator);
		rez.denominator = denominator * b.denominator;
		Simplify(rez.numerator, rez.denominator);
		return rez;
	}
	//ф-ія віднімання дробів
	Fraction Subtract(Fraction b)
	{
		Fraction rez;
		rez.numerator = (numerator * b.denominator) - (b.numerator * denominator);
		rez.denominator = denominator * b.denominator;
		Simplify(rez.numerator, rez.denominator);
		return rez;
	}
	//ф-ія множення дробів
	Fraction Multiply(Fraction b)
	{
		Fraction rez;
		rez.numerator = numerator * b.numerator;
		rez.denominator = denominator * b.denominator;
		Simplify(rez.numerator, rez.denominator);
		return rez;
	}
	//ф-ія ділення дробів
	Fraction Division(Fraction b)
	{
		Fraction rez;
		rez.numerator = numerator * b.denominator;
		rez.denominator = denominator * b.numerator;
		Simplify(rez.numerator, rez.denominator);
		return rez;
	}
	//ф-ія друку дробу
	void Show()
	{
		cout << "Fraction " << numerator << "/" << denominator << endl;
	}

};

int main()
{
	Fraction a;
	Fraction b;
	a.Add(); //створюю дріб а
	b.SetFraction(-6,8); //самостійно створюю дріб б
	a.Show();
	b.Show();
	Fraction add = a.Addition(b);
	add.Show();
	Fraction sub = a.Subtract(b);
	sub.Show();
	Fraction mul = a.Multiply(b);
	mul.Show();
	Fraction div = a.Division(b);
	div.Show();
}