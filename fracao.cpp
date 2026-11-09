#include <iostream>
using namespace std;

class Fracao
{
private:
    int num;
    int den;

public:
    Fracao()
    {
        num = 0;
        den = 1;
    }
    Fracao(int n, int d)
    {
        num = n;
        den = d;
    }
    friend ostream &operator<<(ostream &out, const Fracao &frac);

    Fracao operator+(Fracao outro)
    {
        Fracao soma;
        soma.den = den * outro.den;
        soma.num = (num * outro.den) + outro.num * den;
        return soma;
    }

    Fracao operator*(Fracao outro)
    {
        Fracao mult;
        mult.num = num * outro.num;
        mult.den = den * outro.den;
        return mult;
    }

    Fracao operator+(int escalar)
    {
        Fracao soma;
        soma.num = (den * escalar) + num;
        soma.den = den;
        return soma;
    }

    Fracao &operator--()
    {
        num = num - den;
        return *this;
    }

    Fracao operator++(int)
    {
        Fracao antigo = *this;
        num = num + den;
        return antigo;
    }

    bool operator>(Fracao frac)
    {
        if ((num * frac.den) > (frac.num * den))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    friend Fracao operator+(int escalar, const Fracao &frac);
};
Fracao operator+(int escalar, const Fracao &frac)
{
    Fracao soma;
    soma.num = (frac.den * escalar) + frac.num;
    soma.den = frac.den;
    return soma;
}

ostream &operator<<(ostream &out, const Fracao &frac)
{
    out << frac.num << "/" << frac.den;
    return out;
}

int main()
{
    Fracao A(1, 2), B(4, 3), C;
    cout << "A = " << A << endl
         << "B = " << B << endl;
    C = A + B;
    cout << "C = A + B = " << C << endl;
    C = C * A;
    cout << "C = C * A = " << C << endl;
    C = A + 1;
    cout << "C = A + 1 = " << C << endl;
    C = 2 + B;
    cout << "C = 2 + B = " << C << endl;
    cout << "--B: " << --B << endl;
    cout << "A++: " << A++ << endl;
    cout << "A agora: " << A << endl;
    if (A > B)
        cout << "A maior que B" << endl;
    return 0;
}