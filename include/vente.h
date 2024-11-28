#ifndef VENTE_H
#define VENTE_H

#include <string>

class Vente {
public:
    int id;
    std::string nomProduit;
    int quantiteVendue;
    std::string dateVente;


    Vente(int i, std::string np, int qv, std::string dv);
};

#endif // VENTE_H
