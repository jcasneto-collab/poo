#include <iostream>
using namespace std;
#include <string>
class Veiculo
{
private:
    string modelo;
    int placa;
    double valorDiaria;

public:
    Veiculo(string modelo, int placa, double valorDiaria);
    string get_modelo() const;
    int get_placa() const;
    double get_valorDiaria() const;
    double valorAluguel(int dias) const;
    void exibir(int dias) const;
};

Veiculo::Veiculo(string outroModelo, int outroPlaca, double outrovalorDiaria)
{
    modelo = outroModelo;
    placa = outroPlaca;
    valorDiaria = outrovalorDiaria;
}

string Veiculo::get_modelo() const
{
    return modelo;
}
int Veiculo::get_placa() const
{
    return placa;
}
double Veiculo::get_valorDiaria() const
{
    return valorDiaria;
}

double Veiculo::valorAluguel(int dias) const
{
    double novoPreco;
    novoPreco = dias * valorDiaria;
    return novoPreco;
}

void Veiculo::exibir(int dias) const
{
    cout << dias << "," << modelo << "," << placa << "," << valorDiaria << "," << valorAluguel(dias)<<endl;
}

class Caminhao : public Veiculo
{
private:
    int toneladas;

public:
    Caminhao(string modelo, int placa, double valorDiaria, int toneladas);
    double valorAluguel(int dias) const;
    void exibir(int dias) const;
    int get_toneladas()const;
};

Caminhao::Caminhao(string outroModelo, int outroPlaca, double outroValorDiaria, int outroToneladas) : Veiculo(outroModelo, outroPlaca, outroValorDiaria)
{
    toneladas = outroToneladas;
}

int Caminhao::get_toneladas()const{
    return toneladas;
}

double Caminhao::valorAluguel(int dias) const
{
    double newPrice = ((get_valorDiaria() + (50 * toneladas)) * dias);
    return newPrice;
}

void Caminhao::exibir(int dias) const
{
    cout << dias << "," << get_modelo() << "," << get_placa() << "," << get_valorDiaria() << "," << get_toneladas() << ","  << valorAluguel(dias)<<endl;
}

int main(){
    Veiculo v1("Kwid", 4770, 25.0);
    Caminhao p2("Scania", 7880, 70.0, 525);

    v1.exibir(3);
    p2.exibir(3);
}
