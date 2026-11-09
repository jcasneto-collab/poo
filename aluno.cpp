#include <iostream>
using namespace std;

class Aluno
{
private:
    int RA;
    string Nome;

    static int proximoRA;

public:
    Aluno(string Nome); // construtor
    void set_nome(string Nome);
    string Get_nome() const;
    int Get_RA() const;
    static int getContador();
};

int Aluno::proximoRA = 1;

Aluno::Aluno(string novoNome)
{
    RA = proximoRA;
    set_nome(novoNome);
    proximoRA++;
}

void Aluno::set_nome(string novoNome)
{

    Nome = novoNome;
}

string Aluno::Get_nome() const
{
    return Nome;
}

int Aluno::Get_RA() const
{
    return RA;
}

int Aluno::getContador()
{
    return proximoRA;
}

int main()
{
    const Aluno estudante1("Renato");
    const Aluno estudante2("Ana");
    const Aluno estudante3("Carlos");

    cout << "RA " << estudante1.Get_RA() << ": " << estudante1.Get_nome() << endl;
    cout << "RA " << estudante2.Get_RA() << ": " << estudante2.Get_nome() << endl;
    cout << "RA " << estudante3.Get_RA() << ": " << estudante3.Get_nome() << endl;

    return 0;
}
