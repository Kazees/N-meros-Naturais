#include "NNatural.h"

NNatural::NNatural()
{
    setNumero(numero);
}

NNatural::NNatural(long long int numero)
{
    setNumero(numero);
}

NNatural::NNatural(const NNatural &objeto)
{
    setNNatural(objeto.numero);
}

void NNatural::setNumero(long long int numero)
{
    this->numero=numero;
}

void NNatural::setNNatural(const NNatural &objeto)
{
    numero=objeto.numero;
}

NNatural NNatural::calcularFatorial()const
{
    NNatural resultado(1);

    for(long long int i=2;i<=numero;i++)
    {
        resultado.setNumero(resultado.getNumero()*i);
    }

    return resultado;
}

bool NNatural::numeroPerfeito()const
{
    long long int soma=0;

    for(long long int i=1;i<numero;i++)
    {
        if(numero%i==0)
        {
            soma+=i;
        }
    }

    if(soma!=numero)
    {
        return false;
    }

    return true;
}

bool NNatural::capicua()const
{
    string str=to_string(numero);
    long long int tam=str.length();

    for(long long int i=0,j=tam-1;i<j;i++,j--)
    {
        if(str[i]!=str[j])
        {
            return false;
        }
    }

    return true;
}

bool NNatural::quadradoPerfeito()const
{
    if(sqrt(numero)*sqrt(numero)==numero)
    {
        return true;
    }

    return false;
}

bool NNatural::numeroPrimo()const
{
    if(numero==1)
    {
        return false;
    }

    for(long long int i=2;i<sqrt(numero);i++)
    {
        if(numero%i==0)
        {
            return false;
        }
    }

    return true;
}

string NNatural::mudarBase(int base)const
{
    string resultado="";
    long long int resto;
    NNatural aux(numero);

    while(aux.getNumero()>0)
    {
        resto=aux.getNumero()%base;

        if(resto<10) // Binario
        {
            resultado=(char)(resto+'0')+resultado;
        }

        else //Hexadecimal
        {
            resultado=(char)(resto-10+'A')+resultado;
        }

        aux.setNumero(aux.getNumero()/base);
    }

    return resultado;
}

NNatural NNatural::calcularMDC(const NNatural &objeto)const
{
    NNatural a(*this);
    NNatural b(objeto);

    while(b.getNumero()!=0)
    {
        NNatural temp(b);
        b.setNumero(a.getNumero()%b.getNumero());
        a.setNNatural(temp);
    }

    return a;
}

NNatural NNatural::calcularMMC(const NNatural &objeto)const
{
    NNatural a(*this);
    NNatural b(objeto);
    NNatural mdc=a.calcularMDC(b);

    return NNatural(a.getNumero()/mdc.getNumero()*b.getNumero());
}

bool NNatural::primoEntreSi(const NNatural &objeto)const
{
    NNatural a(*this);
    NNatural b(objeto);
    NNatural mdc=a.calcularMDC(b);

    if(mdc.getNumero()==1)
    {
        return true;
    }

    return false;
}

string NNatural::ToString(const NNatural &objeto)const
{
    stringstream ss;
    ss<<objeto.getNumero();
    return ss.str();
}
