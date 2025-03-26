#include <iostream>

class Fraction
{
  private:
    int numerator_;
    int denominator_;

  public:
    Fraction(int numerator, int denominator)
    {
        numerator_ = numerator;
        denominator_ = denominator;
        simplifyingAnExpression();
    }

    Fraction() : numerator_(0), denominator_(0)
    {
    }

  private:
    void simplifyingAnExpression()
    {
        if (numerator_ == 0)
        {
            numerator_ = 0;
            denominator_ = 1;
            return;
        }
        else if (denominator_ == 0)
        {
            denominator_ = 1;
            return;
        }
        int gсdNum = greatestCommonDivisor(abs(numerator_), abs(denominator_));
        numerator_ /= gсdNum;
        denominator_ /= gсdNum;
    }

    int greatestCommonDivisor(int num1, int num2)
    {
        int result{};
        while (num1 != 0)
        {
            result = num1;
            num1 = num2 % num1;
            num2 = result;
        }
        return result;
    }

  public:
    int getNumerator()
    {
        return numerator_;
    }

    int getDenominator()
    {
        return denominator_;
    }

    bool operator==(Fraction second)
    {
        return (numerator_ == second.numerator_) && (denominator_ == second.denominator_);
    }

    bool operator!=(Fraction second)
    {
        return !((numerator_ == second.numerator_) && (denominator_ == second.denominator_));
    }

    bool operator<(Fraction second)
    {
        int numerator = numerator_ * second.denominator_;
        int secondNumerator = second.numerator_ * denominator_;
        return numerator < secondNumerator;
    }

    bool operator>(Fraction second)
    {
        int numerator = numerator_ * second.denominator_;
        int secondNumerator = second.numerator_ * denominator_;
        return numerator > secondNumerator;
    }

    bool operator<=(Fraction second)
    {
        int numerator = numerator_ * second.denominator_;
        int secondNumerator = second.numerator_ * denominator_;
        return numerator <= secondNumerator;
    }

    bool operator>=(Fraction second)
    {
        int numerator = numerator_ * second.denominator_;
        int secondNumerator = second.numerator_ * denominator_;
        return numerator >= secondNumerator;
    }

    Fraction operator+(Fraction second)
    {
        int numerator = numerator_ * second.denominator_ + second.numerator_ * denominator_;
        int denominator = denominator_ * second.denominator_;
        return Fraction(numerator, denominator);
    }

    Fraction operator-(Fraction second)
    {
        int numerator = numerator_ * second.denominator_ - second.numerator_ * denominator_;
        int denominator = denominator_ * second.denominator_;
        return Fraction(numerator, denominator);
    }

    Fraction operator*(Fraction second)
    {
        int numerator = numerator_ * second.numerator_;
        int denominator = denominator_ * second.denominator_;
        return Fraction(numerator, denominator);
    }

    Fraction operator/(Fraction second)
    {
        int numerator = numerator_ * second.denominator_;
        int denominator = denominator_ * second.numerator_;
        return Fraction(numerator, denominator);
    }

    Fraction operator-()
    {
        return Fraction(-numerator_, denominator_);
    }

    Fraction operator++()
    {
        numerator_ = numerator_ + denominator_;
        simplifyingAnExpression();
        return *this;
    }

    Fraction operator++(int)
    {
        Fraction local = *this;
        numerator_ = numerator_ + denominator_;
        simplifyingAnExpression();
        return local;
    }

    Fraction operator--()
    {
        numerator_ = numerator_ - denominator_;
        simplifyingAnExpression();
        return *this;
    }

    Fraction operator--(int)
    {
        Fraction local = *this;
        numerator_ = numerator_ - denominator_;
        simplifyingAnExpression();
        return local;
    }
};

void inputNum(Fraction& fraction1, Fraction& fraction2)
{
    int input1{};
    int input2{};

    std::cout << "¬ведите числитель дроби 1: ";
    std::cin >> input1;
    std::cout << "¬ведите знаменатель дроби 1: ";
    std::cin >> input2;

    fraction1 = Fraction(input1, input2);

    std::cout << "¬ведите числитель дроби 2: ";
    std::cin >> input1;
    std::cout << "¬ведите знаменатель дроби 2: ";
    std::cin >> input2;

    fraction2 = Fraction(input1, input2);
}

void printResult(Fraction fraction1, const std::string& operator_, Fraction fraction2)
{
    Fraction localfraction;

    if (operator_ == "+")
    {
        localfraction = fraction1 + fraction2;
    }
    else if (operator_ == "-")
    {
        localfraction = fraction1 - fraction2;
    }
    else if (operator_ == "*")
    {
        localfraction = fraction1 * fraction2;
    }
    else if (operator_ == "/")
    {
        localfraction = fraction1 / fraction2;
    }
    else
    {
        std::cout << "NotValid";
        return;
    }

    std::cout << fraction1.getNumerator();
    if (fraction1.getDenominator() != 1 && fraction1.getDenominator() != 0)
    {
        std::cout << "/";
        std::cout << fraction1.getDenominator();
    }

    std::cout << " " << operator_ << " ";
    std::cout << fraction2.getNumerator();

    if (fraction2.getDenominator() != 1 && fraction2.getDenominator() != 0)
    {
        std::cout << "/";
        std::cout << fraction2.getDenominator();
    }

    std::cout << " = ";
    std::cout << localfraction.getNumerator();

    if (localfraction.getDenominator() != 1 && localfraction.getDenominator() != 0)
    {
        std::cout << "/";
        std::cout << localfraction.getDenominator();
    }

    std::cout << std::endl;
}

int main()
{
    setlocale(LC_ALL, "");

    Fraction f1(4, 3);
    Fraction f2(6, 11);

    std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
    std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
    std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
    std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
    std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
    std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';

    Fraction fraction1;
    Fraction fraction2;

    inputNum(fraction1, fraction2);

    printResult(fraction1, "+", fraction2);
    printResult(fraction1, "-", fraction2);
    printResult(fraction1, "*", fraction2);
    printResult(fraction1, "/", fraction2);
    printResult(++fraction1, "*", fraction2);
    printResult(fraction1--, "/", fraction2);
    printResult(-fraction1, "+", fraction2);
    // Test
    // printResult(fraction1, "*", fraction2);
    // printResult(fraction1, "/", fraction2);

    return 0;
}