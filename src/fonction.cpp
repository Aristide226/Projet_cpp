#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Fonction.h"

void ajouterProduit(std::vector<Produit>& produits) {
    std::string nom, description;
    double prix;
    int quantite;

    std::cout << "Nom du produit: ";
    std::cin >> nom;
    std::cout << "Description du produit: ";
    std::cin.ignore(); // Ignore le caractère de nouvelle ligne restant
    std::getline(std::cin, description); // Utilise getline pour lire la description
    std::cout << "Prix du produit: ";
    std::cin >> prix;
    std::cout << "Quantite du produit: ";
    std::cin >> quantite;

    produits.push_back(Produit(nom, description, prix, quantite));
    std::cout << "Produit ajoute avec succes!\n";
}

void modifierProduit(std::vector<Produit>& produits, const std::string& nom) {
    for (auto& produit : produits) {
        if (produit.nom == nom) {
            std::cout << "Nouveau nom: ";
            std::cin >> produit.nom;
            std::cout << "Nouvelle description: ";
            std::cin.ignore();
            std::getline(std::cin, produit.description);
            std::cout << "Nouveau prix: ";
            std::cin >> produit.prix;
            std::cout << "Nouvelle quantite: ";
            std::cin >> produit.quantite;
            std::cout << "Produit modifie avec succes!\n";
            return;
        }
    }
    std::cout << "Produit non trouve!\n";
}

void supprimerProduit(std::vector<Produit>& produits, const std::string& nom) {
    auto it = std::remove_if(produits.begin(), produits.end(), [&nom](const Produit& produit) {
        return produit.nom == nom;
    });
    if (it != produits.end()) {
        produits.erase(it, produits.end());
        std::cout << "Produit supprime avec succes!\n";
    } else {
        std::cout << "Produit non trouve!\n";
    }
}

void rechercherProduit(const std::vector<Produit>& produits, const std::string& nom) {
    for (const auto& produit : produits) {
        if (produit.nom == nom) {

            std::cout << "Nom: " << produit.nom << ", Description: " << produit.description << ", Prix: " << produit.prix << ", Quantite: " << produit.quantite << "\n";
            return;
        }
    }
    std::cout << "Produit non trouvé!\n";
}

void enregistrerVente(std::vector<Vente>& ventes, const std::string& nomProduit, int quantiteVendue, const std::string& dateVente) {
    static int id = 1;
    ventes.push_back(Vente(id++, nomProduit, quantiteVendue, dateVente));
    std::cout << "Vente enregistrée avec succes!\n";
}

void listerVentes(const std::vector<Vente>& ventes) {
    for (const auto& vente : ventes) {
        std::cout << "ID: " << vente.id << ", Produit: " << vente.nomProduit << ", Quantite: " << vente.quantiteVendue << ", Date: " << vente.dateVente << "\n";
    }
}

void sauvegarderProduits(const std::vector<Produit>& produits, const std::string& nomFichier) {
    std::ofstream fichier(nomFichier);
    for (const auto& produit : produits) {
        fichier << produit.nom << "," << produit.description << "," << produit.prix << "," << produit.quantite << "\n";
    }
    fichier.close();
    std::cout << "Donnees sauvegardees avec succes!\n";
}

void chargerProduits(std::vector<Produit>& produits, const std::string& nomFichier) {
    std::ifstream fichier(nomFichier);
    std::string ligne;
    while (std::getline(fichier, ligne)) {
        std::istringstream ss(ligne);
        std::string nom, description;
        double prix;
        int quantite;
        std::getline(ss, nom, ',');
        std::getline(ss, description, ',');
        ss >> prix >> quantite;
        produits.push_back(Produit(nom, description, prix, quantite));
    }
    fichier.close();
    // std::cout << "Données chargées avec succès!\n"; // Commenter ou supprimer cette ligne
}

void sauvegarderVentes(const std::vector<Vente>& ventes, const std::string& nomFichier) {
    std::ofstream fichier(nomFichier);
    for (const auto& vente : ventes) {
        fichier << vente.id << "," << vente.nomProduit << "," << vente.quantiteVendue << "," << vente.dateVente << "\n";
    }
    fichier.close();
    std::cout << "Donnees sauvegardees avec succes!\n";
}

void chargerVentes(std::vector<Vente>& ventes, const std::string& nomFichier) {
    std::ifstream fichier(nomFichier);
    std::string ligne;
    while (std::getline(fichier, ligne)) {
        std::istringstream ss(ligne);
        int id;
        std::string nomProduit, dateVente;
        int quantiteVendue;
        ss >> id;
        ss.ignore();
        std::getline(ss, nomProduit, ',');
        ss >> quantiteVendue;
        ss.ignore();
        std::getline(ss, dateVente, ',');
        ventes.push_back(Vente(id, nomProduit, quantiteVendue, dateVente));
    }
    fichier.close();
    // std::cout << "Données chargées avec succès!\n"; // Commenter ou supprimer cette ligne
}
