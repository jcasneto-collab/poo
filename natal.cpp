#include <iostream>
#include <string>
using namespace std;

class Pedido
{
private:
    static int counterp;
    static int countern;
    const int number;
    string nome;
    int itens;
    string *nome_itens;

public:
    Pedido(string nome, int itens);
    ~Pedido();
    void set_presente(string novoPresente, int i);
    void set_itens(int itens);
    void set_crianca(string crianca);
    string get_nome();
    int get_item();
    string get_nomeItem(int indice);
    static int get_totaln();
    static int get_totalp();
    int get_serial();
};

int Pedido::countern = 0;
int Pedido::counterp = 0;

Pedido::Pedido(string Novonome, int qtdItens) : number(counterp)
{
    nome = Novonome;
    itens = qtdItens;
    counterp++;
    countern += qtdItens;

    nome_itens = new string[itens];
}

Pedido::~Pedido()
{
    counterp--;
    countern -= itens;

    delete[] nome_itens;
}

void Pedido::set_itens(int qtdItens)
{
    itens = qtdItens;
}

void Pedido::set_presente(string novoPresente, int i)
{

    nome_itens[i] = novoPresente;
}

void Pedido::set_crianca(string newName)
{
    nome = newName;
}

string Pedido::get_nome()
{
    return nome;
}

int Pedido::get_item()
{
    return itens;
}

string Pedido::get_nomeItem(int indice)
{
    return nome_itens[indice];
}

int Pedido::get_totalp()
{
    return counterp;
}

int Pedido::get_totaln()
{
    return countern;
}

int Pedido::get_serial()
{
    return number;
}

int main()
{
    // Criação dos pedidos (número sequencial é automático)
    Pedido p1("Berbel", 1);
    Pedido p2("Berbel2", 2);
    Pedido p3("Berbel3", 3);

    // Preenchendo os itens de cada pedido, um a um
    cout << "Digite " << p1.get_item() << " presente(s) para " << p1.get_nome() << ":\n";
    for (int i = 0; i < p1.get_item(); i++)
    {
        string presente;
        cin.ignore(); // limpa o buffer antes de getline
        getline(cin, presente);
        p1.set_presente(presente, i);
    }

    cout << "Digite " << p2.get_item() << " presente(s) para " << p2.get_nome() << ":\n";
    for (int i = 0; i < p2.get_item(); i++)
    {
        string presente;
        getline(cin, presente);
        p2.set_presente(presente, i);
    }

    cout << "Digite " << p3.get_item() << " presente(s) para " << p3.get_nome() << ":\n";
    for (int i = 0; i < p3.get_item(); i++)
    {
        string presente;
        getline(cin, presente);
        p3.set_presente(presente, i);
    }

    // Exibindo os pedidos
    cout << "\n--- Pedidos ---\n";
    Pedido* pedidos[3] = { &p1, &p2, &p3 };
    for (int p = 0; p < 3; p++)
    {
        cout << "Pedido nº " << pedidos[p]->get_serial()
             << " - Crianca: " << pedidos[p]->get_nome()
             << " - Itens (" << pedidos[p]->get_item() << "):\n";
        for (int i = 0; i < pedidos[p]->get_item(); i++)
        {
            cout << "  - " << pedidos[p]->get_nomeItem(i) << "\n";
        }
    }

    // Totais gerais (métodos estáticos, chamados pela classe)
    cout << "\nTotal de pedidos ativos: " << Pedido::get_totalp() << "\n";
    cout << "Total de itens em todos os pedidos: " << Pedido::get_totaln() << "\n";

    // Demonstrando que o destrutor atualiza os contadores
    {
        Pedido p4("Temporario", 5);
        cout << "\nApos criar p4:\n";
        cout << "Total de pedidos ativos: " << Pedido::get_totalp() << "\n";
        cout << "Total de itens: " << Pedido::get_totaln() << "\n";
    } // p4 é destruído aqui, ao sair do escopo

    cout << "\nApos p4 sair de escopo (destruido):\n";
    cout << "Total de pedidos ativos: " << Pedido::get_totalp() << "\n";
    cout << "Total de itens: " << Pedido::get_totaln() << "\n";

    return 0;
}
