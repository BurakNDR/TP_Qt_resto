//
// TP Restaurant en Qt
//
// By Burak ÖNDER
//
// fichier header .h
//
// Fait avec Qt Creator sans le mode Design
//

#ifndef RESTO_H
#define RESTO_H

#include <QMainWindow>

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>

#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QComboBox> // Pour créer des listes déroulantes
#include <QString> // Pour manipuler des chaînes de caractères
#include <QDebug> // Pour affiche des messages de débug
#include <QMessageBox> // Pour afficher des messages dans une fenêtre
#include <QFile> // Pour lire et écrire des fichiers

QT_BEGIN_NAMESPACE
namespace Ui { class resto; }
QT_END_NAMESPACE

class resto : public QMainWindow
{
    Q_OBJECT

public:
    resto(QWidget *parent = nullptr);  // Constructeur de la classe resto
    ~resto(); // Destructeur de la classe resto

    //-- Instancier les layouts
    QVBoxLayout *mainlayout; // Layout principal de la fenêtre
    QHBoxLayout *horiz1; // Layout horizontal pour la 1ere ligne de la fenêtre
    QHBoxLayout *horiz2; // Layout horizontal pour la 2e ligne
    QHBoxLayout *horiz3; // Layout horizontal pour la 3e ligne
    QGridLayout *grille = new QGridLayout; // Layout en grille pour les plats et les boissons

    QLabel *question = new QLabel(this); // Création d'un label pour poser la question de départ
    QLabel *bv; // Label de bienvenue
    QLabel *sonprenom; // Label pour afficher le prénom de l'utilisateur
    QLabel *sonom; // Label pour afficher le nom
    QLabel *label_entree; // Label pour afficher "Entrées"
    QLabel *label_plat; // Label pour afficher "Plats"
    QLabel *label_dessert; // Label pour afficher "Desserts"
    QLabel *label_boisson; // Label pour afficher "Boissons"
    QLabel *label_commande; // Label pour afficher la commande
    QLabel *sonentree; // Label pour afficher l'entrée choisie
    QLabel *sonplat; // Label pour afficher le plat choisi
    QLabel *sondessert;; // Label pour afficher le dessert choisi
    QLabel *saboisson; // Label pour afficher la boisson choisie

    QLineEdit *id; // Champ de saisie pour l'ID du gérant
    QLineEdit *mdp; // Champ de saisie pour le mot de passe du gérant
    QLineEdit *nom; // Champ de saisie pour le nom
    QLineEdit *prenom; // Champ de saisie pour le prénom

    QPushButton *nouvelle; // bouton pour ajouter une nouvelle commande
    QPushButton *afficher; // bouton pour afficher les commandes existantes
    QPushButton *modifier; // bouton pour modifier une commande existante
    QPushButton *quitter; // bouton pour quitter l'application
    QPushButton *commander; // bouton pour passer une commande
    QPushButton *revenir; // bouton pour retourner à l'écran principal


    QComboBox *payment;  // liste déroulante pour sélectionner le mode de paiement

    //-- Création des entrées
    QCheckBox *salade; // case à cocher pour sélectionner la salade
    QCheckBox *soupe_lentille; // case à cocher pour sélectionner la soupe aux lentilles
    QCheckBox *quiche; // pareil qu'en haut

    //-- Création des plats
    QCheckBox *tagliatelle; // case à cocher pour sélectionner les tagliatelles
    QCheckBox *osso_bucco; // case à cocher pour sélectionner l'osso bucco
    QCheckBox *potjevleesch; // pareil que la ligne d'au dessus
    QCheckBox *risotto; // pareil que la ligne d'au dessus
    QCheckBox *raviolis; // pareil que la ligne d'au dessus

    //-- Création des desserts
    QCheckBox *tiramisu; // case à cocher pour sélectionner le tiramisu
    QCheckBox *daim; // case à cocher pour sélectionner le tiramisu
    QCheckBox *citron_meringuee; // pareil que la ligne d'au dessus
    QCheckBox *brownie; // pareil que la ligne d'au dessus

    //-- Création des boissons
    QCheckBox *eau; // case à cocher pour sélectionner l'eau
    QCheckBox *coca; // case à cocher pour sélectionner le coca
    QCheckBox *oasis; // pareil que la ligne d'au dessus
    QCheckBox *cafe; // pareil que la ligne d'au dessus
    QCheckBox *the; // pareil que la ligne d'au dessus
    QCheckBox *entrees[3]; // pareil que la ligne d'au dessus
    QCheckBox *plats[5]; // pareil que la ligne d'au dessus
    QCheckBox *desserts[4]; // pareil que la ligne d'au dessus
    QCheckBox *boissons[5]; // pareil que la ligne d'au dessus

public slots:
    //-- fonctions appelées lorsque les boutons sont cliqués
    void bouton_gerant(); // ouvre l'écran de connexion pour les gérants
    void bouton_client(); // ouvre l'écran de connexion pour les clients
    void bouton_connexion(); // ouvre l'écran de bienvenue après la connexion
    void bienvenue(); // ouvre l'écran principal après la connexion
    void bouton_commander(); // ouvre l'écran de commande lorsque le bouton est cliqué

//-- boutons principaux
    void bouton_nouvelle();
    //void bouton_modifier(); // permet de modifier une commande existante
    void bouton_afficher();

private:
    Ui::resto *ui;
};
#endif // RESTO_H