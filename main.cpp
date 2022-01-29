#include <iostream>
#include <fstream>
#include "polinomio.h"

int main()
{
    try
    {
        // poli = 3.2 + 2.2 x + 4.1 x^2
        std::vector<double> coef_procura({3.2, 2.2, 4.1});
        Polinomio pol_procura(coef_procura);
        std::cout << "Polinomio procura:\n"<<pol_procura<<std::endl;

        Polinomio pol_oferta;
        std::ifstream fichoferta("ficheiro_oferta.txt");
        if(!fichoferta)
        {
            std::cout << "NON EXISTENT FILE, PLEASE INTRODUCE THE ENTRANCES:\n";
            std::cin>>pol_oferta;
            pol_oferta.GuardarNoFicheiro("ficheiro_oferta.txt");
        }
        else
        {
            fichoferta>>pol_oferta;
            std::cout <<"FILE READ!\n";
            fichoferta.close();
        }
        std::cout<<"Polinomio oferta:\n" << pol_oferta << std::endl;

        double preco_base=30.;

        std::cout << "Preco do produto no dia 100 = "
                  << pol_procura.Valor(100)/pol_oferta.Valor(100)*preco_base << std::endl;

        Polinomio competicao = pol_procura+pol_oferta;
        std::cout << "Polinomio da competicao: \n" << competicao << std::endl;
        competicao.GuardarNoFicheiro("competicao.txt");

        return 0;
    }
    catch (const err& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}
