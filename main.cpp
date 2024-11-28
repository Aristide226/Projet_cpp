#include <iostream>
#include <vector>
#include "Produit.h"
#include "Vente.h"
#include "Fonction.h"

int main() {
    std::vector<Produit> produits;
    std::vector<Vente> ventes;


    int choix;

    std::cout << "********************************************************************\n";
    std::cout << "            BIENVENUE SUR NOTRE PLATEFORME E-COMMERCE               \n";
    std::cout << "********************************************************************\n";

    do {
        std::cout << "1. Ajouter un produit\n2. Modifier un produit\n3. Supprimer un produit\n4. Rechercher un produit\n5. Enregistrer une vente\n6. Lister les ventes\n7. Sauvegarder les produits\n8. Quitter\nChoix: ";
        std::cin >> choix;

        switch (choix) {
            case 1:
                ajouterProduit(produits);
                break;
            case 2: {
                std::string nom;
                std::cout << "Nom du produit a modifier: ";
                std::cin >> nom;
                modifierProduit(produits, nom);
                break;
            }
            case 3: {
                std::string nom;
                std::cout << "Nom du produit a supprimer: ";
                std::cin >> nom;
                supprimerProduit(produits, nom);
                break;
            }
            case 4: {
                std::string nom;
                std::cout << "Nom du produit a rechercher: ";
                std::cin >> nom;
                rechercherProduit(produits, nom);
                break;
            }
            case 5: {
                std::string nomProduit, dateVente;
                int quantiteVendue;
                std::cout << "Nom du produit vendu: ";
                std::cin >> nomProduit;
                std::cout << "Quantite vendue: ";
                std::cin >> quantiteVendue;
                std::cout << "Date de la vente: ";
                std::cin >> dateVente;

                enregistrerVente(ventes, nomProduit, quantiteVendue, dateVente);
                break;
            }
            case 6:
                listerVentes(ventes);
                break;
            case 7: {
                std::string nomFichier;
                std::cout << "Nom du fichier de sauvegarde: ";
                std::cin >> nomFichier;
                sauvegarderProduits(produits, nomFichier);
                break;
            }

            case 8:
                std::cout << "Au revoir!\n";
                break;
            default:
                std::cout << "Choix invalide!\n";
        }
    } while (choix != 8);

    sauvegarderProduits(produits, "data/produits.txt");
    sauvegarderVentes(ventes, "data/ventes.txt");

    return 0;
}
