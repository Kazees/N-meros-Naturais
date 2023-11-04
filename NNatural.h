#ifndef NNATURAL_H
#define NNATURAL_H
#include <string>
#include <cmath>
#include <sstream>


using namespace std;

class NNatural
{
private:
    long long int numero;
public:
    NNatural();
    NNatural(long long int numero);
    NNatural(const NNatural &objeto);

    void setNumero(long long int numero);
    void setNNatural(const NNatural &objeto);

    long int getNumero()const {return numero;}

    string ToString(const NNatural &objeto)const;
    bool quadradoPerfeito()const;
    NNatural calcularFatorial()const;
    bool numeroPerfeito()const;
    bool capicua()const;
    bool numeroPrimo()const;
    string mudarBase(int base)const;
    NNatural calcularMDC(const NNatural &objeto)const;
    NNatural calcularMMC(const NNatural &objeto)const;
    bool primoEntreSi(const NNatural &objeto)const;
};

#endif // NNATURAL_H
