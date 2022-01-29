#include "polinomio.h"
#include <iostream>

using namespace std;

double Polinomio::Valor(size_t x) const
{
    double r=0, pot=1;
    for(auto y:coefs) {
        r+=y*pot;
        pot*=x;
    }
    return r;
}

void Polinomio::GuardarNoFicheiro(const string& nome) const
{
    ofstream of(nome);
    if(!of) throw err {"Não pude criar o ficheiro"};
    if(!(of << *this << '\n')) throw err{"Erro ao escrever no ficheiro"};
    of.close();
    cout << "Ficheiro guardado com sucesso!\n";
}

Polinomio operator+(const Polinomio& p1, const Polinomio& p2)
{
    vector<double> v(max(p1.size(),p2.size()));
    for(size_t i=0;i<min(p1.size(),p2.size());++i) v[i]=p1[i]+p2[i];
    if(p1.size()<p2.size()) {
        for(size_t i=p1.size();i<p2.size();++i) v[i]=p2[i];
    }
    else {
        for(size_t i=p2.size();i<p1.size();++i) v[i]=p1[i];
    }
    return Polinomio(v);
}

ostream& operator<<(ostream& os, const Polinomio& p)
{
    for(size_t i=0;i<p.size();++i) os << p[i] << '\t';
    return os;
}

istream& operator>>(istream& is, Polinomio& p)
{
    vector<double> v;
    double x;
    while(is>>x) v.push_back(x);
    p=Polinomio(v);
    return is;
}
