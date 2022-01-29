#ifndef POLINOMIO_H
#define POLINOMIO_H

#include <vector>
#include <fstream>
#include <string>

class err : public std::runtime_error
{
public:
    err(const std::string& s):runtime_error(s) {}
};

class Polinomio
{
private:
    std::vector<double> coefs;
public:
    Polinomio() {coefs.resize(1,0);}
    Polinomio(const std::vector<double>& v):coefs{v} {}

    double& operator[](size_t i) {return coefs[i];}
    const double& operator[](size_t i) const {return coefs[i];}

    size_t size() const {return coefs.size();}
    double Valor(size_t) const;
    void GuardarNoFicheiro(const std::string& nome) const;

};

Polinomio operator+(const Polinomio&, const Polinomio&);

std::ostream& operator<<(std::ostream&, const Polinomio&);
std::istream& operator>>(std::istream&, Polinomio&);


#endif // POLINOMIO_H
