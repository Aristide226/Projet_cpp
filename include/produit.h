#ifndef PRODUIT_H
#define PRODUIT_H

#include <string>

class Produit {
public:
    std::string nom;
    std::string description;
    double prix;
    int quantite;


    Produit(std::string n, std::string d, double p, int q);
};

#endif // PRODUIT_H
