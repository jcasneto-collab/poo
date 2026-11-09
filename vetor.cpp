#include <iostream>
using namespace std;

class vetor
{
private:
    int tamanho;
    int *vetorptr;

public:
    vetor(int tamanho);
    ~vetor();
    bool setValor(int posicao, int valor);
    bool getValor(int posicao, int &valor) const;
    int getTamanho() const;
};

vetor::vetor(int novoTamanho)
{
    tamanho = novoTamanho;
    vetorptr = new int[tamanho];
}

vetor::~vetor()
{
    delete[] vetorptr;
}

bool vetor::setValor(int posicao, int valor)
{

    if (posicao >= 0 && posicao < tamanho)
    {
        vetorptr[posicao] = valor;
        return true;
    }
    return false; // indica falha
}

bool vetor::getValor(int posicao, int &valor) const
{
    if (posicao >= 0 && posicao < tamanho)
    {
        valor = vetorptr[posicao];
        
        return true;
    }
    else
    {
        return false;
    }
}

int vetor::getTamanho() const{
    return tamanho;
}
