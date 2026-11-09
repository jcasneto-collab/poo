#include <iostream>
using namespace std;

class Vetor2D
{
private:
    double x;
    double y;

public:
    Vetor2D()
    {
        x = y = 0;
    }
    Vetor2D(double a, double b)
    {
        x = a;
        y = b;
    }
    Vetor2D operator+(Vetor2D outro)
    {
        Vetor2D soma;
        soma.x = x + outro.x;
        soma.y = y + outro.y;
        return soma;
    }

    Vetor2D operator*(double k)
    {
        Vetor2D mult;
        mult.x = k * x;
        mult.y = k * y;
        return mult;
    }

    Vetor2D &operator++()
    {
        x = x + 1;
        y = y + 1;
        return *this;
    } // o ++ antes, eu incremento e entrego incrementado
    Vetor2D operator--(int)
    {
        Vetor2D antigo = *this;
        x = x - 1;
        y = y - 1;
        return antigo;
    } // o -- depois, eu entrego o antigo e depois decremento

    bool operator!=(Vetor2D ponto)
    {
        if (ponto.x != x || ponto.y != y)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    friend Vetor2D operator*(double k, const Vetor2D &outro);

    friend ostream &operator<<(ostream &out, const Vetor2D &ponto);
};

Vetor2D operator*(double k, const Vetor2D &outro)
{
    Vetor2D mult;
    mult.x = k * outfunc.basicSalaryro.x;
    mult.y = k * outro.y;
    return mult;
}

ostream &operator<<(ostream &out, const Vetor2D &ponto)
{
    out << "(" << ponto.x << ", " << ponto.y << ")";
    return out;
}

int main()
{
    Vetor2D A(2, 3), B(1, 1), C;
    cout << "A = " << A << endl
         << "B = " << B << endl;
    C = A + B;
    cout << "C = A + B = " << C << endl;
    C = C * 2;
    cout << "C = C * 2 = " << C << endl;
    C = 3 * B;
    cout << "C = 3 * B = " << C << endl;
    cout << "++A: " << ++A << endl;
    cout << "A--: " << A-- << endl;
    cout << "A agora: " << A << endl;
    if (A != B)
        cout << "A e B sao diferentes" << endl;
    return 0;
}