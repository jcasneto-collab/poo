#include <iostream>
#include <string>
using namespace std;

class Pedido
{
private:
    static int counterPedidos;
    static int totalPresentes;
    const int serialNumber;
    string nome;
    int qntdPresentes;
    string *listaPresentes;

public:
    Pedido(string nome, int qntdPresentes);
    ~Pedido();
    void set_nome(string nome);
    void set_qtd(int qtdPresentes);
    void set_Presente(string presente, int posicao);
    string get_nome();
    string get_presente(int posicao);
    int get_qtd();
    static int get_totalPedidos();
    static int get_totalPresentes();
    int get_serialNumber();
};

int Pedido::counterPedidos = 0;
int Pedido::totalPresentes = 0;

Pedido::Pedido(string newName, int newQtd) : serialNumber(counterPedidos)
{
    nome = newName;
    qntdPresentes = newQtd;
    counterPedidos++;
    totalPresentes += qntdPresentes;
    listaPresentes = new string[qntdPresentes];
}

Pedido::~Pedido()
{
    delete[] listaPresentes;
    counterPedidos--;
    totalPresentes -= qntdPresentes;
}

void Pedido::set_nome(string newName)
{
    nome = newName;
}

void Pedido::set_qtd(int newqtdPresentes)
{
    qntdPresentes = newqtdPresentes;
}

void Pedido::set_Presente(string newPresente, int posicao)
{
    listaPresentes[posicao] = newPresente;
}

string Pedido::get_nome()
{
    return nome;
}

string Pedido::get_presente(int posicao){
    return listaPresentes[posicao];
}

int Pedido::get_qtd(){
    return qntdPresentes;
}

int Pedido::get_totalPedidos(){
    return counterPedidos;
}

int Pedido::get_totalPresentes(){
    return totalPresentes;
}

int Pedido::get_serialNumber(){
    return serialNumber;
}

