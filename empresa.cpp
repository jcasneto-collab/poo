#include <iostream>
#include <string>
using namespace std;

class Funcionario
{
private:
    string name;
    int cod;
    double basicSalary;

public:
    Funcionario(string name, int cod, double basicSalary);
    Funcionario();
    string get_name() const;
    int get_cod() const;
    double get_basicSalary() const;
    double remunaration() const; // retorna o salario fixo do func
    friend ostream &operator<<(ostream &out, const Funcionario &func);
    bool operator>(Funcionario outro)
    {
        if (remunaration() > outro.remunaration())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator==(Funcionario outro)
    {
        if (outro.cod == cod)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    Funcionario &operator+=(double value)
    {
        basicSalary += value;
        return *this;
    }
};

Funcionario::Funcionario(string otherName, int otherCod, double other_basicSalary)
{
    name = otherName;
    cod = otherCod;
    basicSalary = other_basicSalary;
}

Funcionario::Funcionario()
{
    name = "x";
    cod = 0;
    basicSalary = 0.0;
}

ostream &operator<<(ostream &out, const Funcionario &func)
{
    out << func.name << " (cod " << func.cod << ") " << "fixo: " << func.basicSalary;
    return out;
}

string Funcionario::get_name() const
{
    return name;
}

int Funcionario::get_cod() const
{
    return cod;
}

double Funcionario::get_basicSalary() const
{
    return basicSalary;
}

double Funcionario::remunaration() const
{
    return basicSalary;
}

class Gerente : public Funcionario
{
private:
    int numSupervisionados;

public:
    Gerente(string name, int cod, double basicSalary, int numSupervisionados);
    int get_numSupervisionados() const;
    double remunaration() const;
    Gerente &operator++()
    {
        numSupervisionados += 1;
        return *this;
    }
    Gerente operator++(int)
    {
        Gerente antigo = *this;
        numSupervisionados += 1;
        return antigo;
    }

    Gerente &operator+=(double value)
    {
        Funcionario::operator+=(value);
        return *this;
    }

    bool operator>(Gerente outro_gerente)
    {
        if (remunaration() > outro_gerente.remunaration())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator>(Funcionario f1)
    {
        if (remunaration() > f1.remunaration())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    friend ostream &operator<<(ostream &out, const Gerente &g1);
};

bool operator>(const Funcionario &funcionario, const Gerente &gerente)
{
    if (funcionario.remunaration() > gerente.remunaration())
    {
        return true;
    }
    else
    {
        return false;
    }
}

Gerente::Gerente(string othername, int otherCod, double other_basicSalary, int other_numSupervisionados) : Funcionario(othername, otherCod, other_basicSalary)
{
    numSupervisionados = other_numSupervisionados;
}

int Gerente::get_numSupervisionados() const
{
    return numSupervisionados;
}
double Gerente::remunaration() const
{
    double newRemunaration = get_basicSalary() + get_basicSalary() * 0.01 * numSupervisionados;
    return newRemunaration;
}

ostream &operator<<(ostream &out, const Gerente &g1)
{
    out << g1.get_name() << " (cod " << g1.get_cod() << ") " << "fixo: " << g1.get_basicSalary() << " | supervisiona: " << g1.numSupervisionados;
    return out;
}

int main()
{
    Funcionario f1("Ana", 1, 3000), f2("Bia", 2, 5200);
    Gerente g1("Caio", 3, 5000, 10), g2("Duda", 4, 3600, 40);

    cout << f1 << endl;
    cout << g1 << endl;
    cout << "Remuneracao g1 = " << g1.remunaration() << endl;
    cout << "Remuneracao g2 = " << g2.remunaration() << endl;

    if (f2 > f1)
        cout << "f2 > f1" << endl;
    if (g1 > f1)
        cout << "g1 > f1" << endl;
    if (f2 > g1)
        cout << "f2 > g1" << endl;
    else
        cout << "f2 NAO > g1" << endl;
    if (g2 > g1)
        cout << "g2 > g1" << endl;
    else
        cout << "g2 NAO > g1" << endl;

    cout << (f1 += 500) << endl;
    cout << (g1 += 1000) << endl;
    cout << g1++ << endl;
    cout << g1 << endl;
    cout << ++g1 << endl;
    cout << "Remuneracao g1 = " << g1.remunaration() << endl;

    if (g1 == g2)
        cout << "mesmo codigo" << endl;
    else
        cout << "codigos diferentes" << endl;
    return 0;
}