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
        numerator_ *= second.denominator_;
        second.numerator_ *= denominator_;
        return numerator_ < second.numerator_;
    }
    bool operator>(Fraction second)
    {
        numerator_ *= second.denominator_;
        second.numerator_ *= denominator_;
        return numerator_ > second.numerator_;
    }
    bool operator<=(Fraction second)
    {
        numerator_ *= second.denominator_;
        second.numerator_ *= denominator_;
        return numerator_ <= second.numerator_;
    }
    bool operator>=(Fraction second)
    {
        numerator_ *= second.denominator_;
        second.numerator_ *= denominator_;
        return numerator_ >= second.numerator_;
    }

};

int main()
{
    Fraction f1(4, 3);
    Fraction f2(6, 11);

    std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
    std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
    std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
    std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
    std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
    std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
    return 0;
}