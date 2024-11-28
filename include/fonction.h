#ifndef FONCTIONS_H
#define FONCTIONS_H

#include <vector>
#include "Produit.h"
#include "Vente.h"

void ajouterProduit(std::vector<Produit>& produits);
void modifierProduit(std::vector<Produit>& produits, const std::string& nom);
void supprimerProduit(std::vector<Produit>& produits, const std::string& nom);
void rechercherProduit(const std::vector<Produit>& produits, const std::string& nom);
void enregistrerVente(std::vector<Vente>& ventes, const std::string& nomProduit, int quantiteVendue, const std::string& dateVente);
void listerVentes(const std::vector<Vente>& ventes);
void sauvegarderProduits(const std::vector<Produit>& produits, const std::string& nomFichier);
void sauvegarderVentes(const std::vector<Vente>& ventes, const std::string& nomFichier);


#endif // FONCTIONS_H
