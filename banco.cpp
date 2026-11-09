#include <iostream>
#include <string>
using namespace std;

class Conta
{
private:
    double saldo;

public:
    Conta(double saldo);
    double get_saldo() const;
    void setSaldo(double valor);
    void depositar(double valor);
    bool sacar(double valor);
    void exibir();
};

Conta::Conta(double outro_saldo)
{
    if (outro_saldo >= 0)
    {
        saldo = outro_saldo;
    }
    else
    {
        saldo = 0;
    }
}

double Conta::get_saldo() const{
    return saldo;
}

void Conta::setSaldo(double valor){
    saldo = valor;
}

