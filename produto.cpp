#include <iostream>
#include <string>
using namespace std;

class Produto
{
private:
    string name;
    int cod;
    double price;

public:
    Produto(string name, int cod, double price);
    string get_name() const;
    int get_cod() const;
    double get_price() const;
    double finalPrice() const;
    void exibir() const;
};

Produto::Produto(string outro_name, int outro_cod, double outro_price)
{
    name = outro_name;
    cod = outro_cod;
    price = outro_price;
}

string Produto::get_name() const
{
    return name;
}

int Produto::get_cod() const
{
    return cod;
}

double Produto::get_price() const
{
    return price;
}

void Produto::exibir() const
{
    cout << name << "," << cod << "," << price << "," << Produto::finalPrice()<< " ";
}

double Produto::finalPrice() const
{
    return price;
}

class ProdutoPerecivel : public Produto
{
private:
    int validade;

public:
    ProdutoPerecivel(string name, int cod, double price, int validade);
    double finalPrice() const;
    void exibir() const;
    int get_validade() const;
};

int ProdutoPerecivel::get_validade() const
{
    return validade;
}

ProdutoPerecivel::ProdutoPerecivel(string outro_name, int outro_cod, double outro_price, int newValidade) : Produto(outro_name, outro_cod, outro_price)
{
    validade = newValidade;
}

double ProdutoPerecivel::finalPrice() const
{

    if (validade <= 7)
    {
        double finalPrice = get_price() * 0.7;
        return finalPrice;
    }
    else
    {
        double finalPrice = get_price();
        return finalPrice;
    }
}

void ProdutoPerecivel::exibir() const
{
    cout << get_name() << "," << get_cod() << "," << get_price() << "," << validade << "," << ProdutoPerecivel::finalPrice() << " ";
}


int main(){
    Produto p1("arroz", 344, 2.50);
    ProdutoPerecivel p2("leiteAzedo", 290, 7.0, 5);
    ProdutoPerecivel p3("leite", 290, 7.0, 10);

    p1.exibir();
    p2.exibir();
    p3.exibir();


}