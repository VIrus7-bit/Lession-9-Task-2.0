#include <cassert> 
#include <iostream>
#include <numeric> 
using namespace std;

class Fraction
{
private:
	int Numerator_{};
	int Denominator_{};

	void reduce()
	{
		int divisor = std::gcd(Numerator_, Denominator_);//gcd выводит ошибку
		Numerator_ /= divisor;
		Denominator_ /= divisor;
	}

public:Fraction(int getnumerator, int Denominator) : Numerator_{ getnumerator }, Denominator_{ Denominator } {}
 
	  friend std::ostream& operator <<(std::ostream& os, const Fraction& Fraction)
	  {
		  os << Fraction.Numerator_ << "/" << Fraction.Denominator_;
		  return os;
	  }

	  Fraction operator =(const Fraction& Fraction)
	  {
		  if (this == &Fraction) { return *this; }

		  this->Denominator_ = Fraction.Denominator_;
		  this->Numerator_ = Fraction.Numerator_;
		  return *this;
	  }
	  Fraction operator +(const Fraction& h2)
	  {
		  int ResultNumerator_ = Numerator_ * h2.Denominator_ + Denominator_ * h2.Numerator_;
		  int ResultDenominator_ = Denominator_ * h2.Denominator_;
		  return { ResultNumerator_ ,ResultDenominator_ };
	  }
	  Fraction operator -(const Fraction& h2)
	  {
		  int ResultNumerator_ = Numerator_ * h2.Denominator_ - Denominator_ * h2.Numerator_;
		  int ResultDenominator_ = Denominator_ * h2.Denominator_;
		  return { ResultNumerator_ ,ResultDenominator_ };
	  }
	  Fraction operator /(const Fraction& h2)
	  {
		  int ResultNumerator_ = Numerator_ * h2.Denominator_;
		  int ResultDenominator_ = Denominator_ * h2.Numerator_;
		  return { ResultNumerator_ ,ResultDenominator_ };
	  }
	  //Fraction operator *(const Fraction& h2)
	  //{
		//  int ResultNumerator_ = Numerator_ * h2.Numerator_;
		//  int ResultDenominator_ = Denominator_ * h2.Denominator_; 
		//  return { ResultNumerator_ ,ResultDenominator_ };
	  //}
	  Fraction operator *(const Fraction& h2)
	  {
		  Numerator_ = Numerator_ * h2.Numerator_;
		  Denominator_ = Denominator_ * h2.Denominator_;
		  reduce();
		  return *this;
	  }
	  Fraction operator - ()	     
	  {
		  Numerator_ = -Numerator_;
		  Denominator_ = -Denominator_;
		  return *this;
	  }
	  Fraction operator ++()   
	  {
		  Numerator_ = ++Numerator_;
		  Denominator_ = ++Denominator_;
		  return *this;
	  }
	  Fraction operator --(int)
	  {
		  Numerator_ = --Numerator_;
		  Denominator_ = --Denominator_;
		  return *this;
	  }
	  Fraction operator ++(int)
	  {
		  Fraction temp{ *this };
		  ++(*this);
		  return temp;
	  }

	  bool operator == (const Fraction& h2)
	  {
		  return { Numerator_ / Denominator_ == h2.Numerator_ / h2.Denominator_ };
	  }
	  bool operator <  (const Fraction& h2)
	  {
		  return { Numerator_ / Denominator_ < h2.Numerator_ / h2.Denominator_ };
	  }
	  bool operator >  (const Fraction& h2)
	  {
		  return { Numerator_ / Denominator_ > h2.Numerator_ / h2.Denominator_ };
	  }
	  bool operator != (const Fraction& h2)
	  {
		  return { Numerator_ / Denominator_ != h2.Numerator_ / h2.Denominator_ };
	  }
	  bool operator <= (const Fraction& h2)
	  {
		  return { Numerator_ / Denominator_ <= h2.Numerator_ / h2.Denominator_ };
	  }
	  bool operator >= (const Fraction& h2)
	  {
		  return { Numerator_ / Denominator_ >= h2.Numerator_ / h2.Denominator_ };
	  }
	  operator int()
	  {
		  return Numerator_;
	  }

	  void proverka() {
		assert(Numerator_ > 0);  
		assert(Denominator_ > 0);
	  }
};

int main() {

	setlocale(LC_ALL, "Rus");
	system("chcp 1251");
	system("cls");

	int a, b, c, d, e = 7, f = 4;
	cout << "Введите числитель дроби 1:"; cin >> a;
	cout << "Введите знаменатель дроби 1:"; cin >> b;
	cout << "Введите числитель дроби 2:"; cin >> c;
	cout << "Введите знаменатель дроби 2:"; cin >> d;

	Fraction f1(a, b);
	Fraction f2(c, d);
	Fraction f3(e, f);
	f1.proverka();
	f2.proverka();

	cout << a << "/" << b << " + " << c << "/" << d << " = " << (f1 + f2) << endl;
	cout << a << "/" << b << " - " << c << "/" << d << " = " << (f1 - f2) << endl;
	cout << a << "/" << b << " * " << c << "/" << d << " = " << (f1 * f2) << endl;
	cout << a << "/" << b << " / " << c << "/" << d << " = " << (f1 / f2) << endl;
	cout << "++" << a << "/" << b << " * " << c << "/" << d << " = " << (++f1) * f2 << endl;// Не получается ответа что в задании 4/5 * 4/5 = 16/25 как из этого получить 7/5?
	cout << "Значения дроби 1 = " << f3 << endl; 
	cout << e << "/" << f << "-- * "<< c << "/" << d << " = " << f3 * f2 << endl; //Ответ получается верным только в том случае если не ставить оператор --.

	system("pause");
	return 0;
}