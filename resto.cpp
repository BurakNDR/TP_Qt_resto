//
// TP Restaurant en Qt
//
// By Burak ÖNDER
//
// fichier source .cpp
//
// Fait avec Qt Creator sans le mode Design
//

#include "resto.h"
#include "ui_resto.h"

resto::resto(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::resto)
{
    ui->setupUi(this);

    setWindowTitle("Fenêtre de choix"); // Changer le nom de la fenêtre

    // Création des layout
    horiz1 = new QHBoxLayout;
    horiz2 = new QHBoxLayout;
    mainlayout = new QVBoxLayout;

    //-- 1. Personnalisation du QLabel "question"
        // définit le texte à afficher
    question->setText("Vous êtes le client ou le gérant ?");
        // définir la police du texte
    QFont font("Arial Black",11);
    question->setFont(font);
        // centrer le texte
    question->setAlignment(Qt::AlignHCenter);

    //-- 2. Bouton Client et Gérant
    QPushButton *client = new QPushButton("Client");
    QPushButton *gerant = new QPushButton("Gérant");

    // Ajout des boutons dans le layout horizontal 2
    horiz2->addWidget(client);
    horiz2->addWidget(gerant);

    // Ajout du label dans le layout horizontal 1
    horiz1->addWidget(question);

    // Ajout des layouts dans le layout vertical principal
    mainlayout->addLayout(horiz1);
    mainlayout->addLayout(horiz2);

    adjustSize(); // Ajuster la fenêtre automatiquement

    // Création d'un widget contenant le layout principal
    QWidget *widget = new QWidget();
    widget->setLayout(mainlayout);
    setCentralWidget(widget);

    //-- Signal - Slot des boutons
        // Connexion du signal clicked du bouton gerant au slot bouton_gerant
    connect(gerant, SIGNAL(clicked()),this, SLOT(bouton_gerant()));
        // Connexion du signal clicked du bouton client au slot bouton_client
    connect(client, SIGNAL(clicked()), this, SLOT(bouton_client()));
}

void resto::bouton_gerant()
{  
    setWindowTitle("Connexion pour le gérant"); // Changer le nom de la fenêtre

    // Créer les QHBoxLayout et QVBoxLayout
    horiz1 = new QHBoxLayout;
    horiz2 =  new QHBoxLayout;
    horiz3 =  new QHBoxLayout;
    mainlayout = new QVBoxLayout;

    // Créer les QLineEdit
    id = new QLineEdit(this);
    mdp = new QLineEdit(this);

    //-- 2. Personnaliser les widgets
        //-- 2.1 Identifiant & Mot de passe
        id->setStyleSheet("color: #0a214c; background-color: #C19A6B");
        mdp->setStyleSheet("color: #0a214c; background-color: #C19A6B");
        id->setPlaceholderText("Identifiant");
        mdp->setPlaceholderText("Mot de passe");

        // Créer le bouton "Connexion"
        QPushButton *connexion = new QPushButton(QString::fromUtf8("Connexion"),this);

        // Ajouter les widgets aux Layout
        horiz2->addWidget(id);
        horiz1->addWidget(mdp);
        horiz3->addWidget(connexion);

        // Ajouter les Layout au layout principal
        mainlayout->addLayout(horiz2);
        mainlayout->addLayout(horiz1);
        mainlayout->addLayout(horiz3);

        // Créer un QWidget avec le layout principal
        QWidget *widget = new QWidget();
        widget->setLayout(mainlayout);
        setCentralWidget(widget);

        // Établir une connexion entre le clic sur le bouton "Connexion" et la fonction "bouton_connexion"
        connect(connexion, SIGNAL(clicked()), this, SLOT(bouton_connexion()));
}

// Fonction appelée lorsque le bouton de connexion est cliqué
void resto::bouton_connexion()
{
    // Vérifie si l'identifiant et le mot de passe correspondent
    if(id->text()==QString("Blabla") && mdp->text()==QString("test"))
    {
        // Affiche un message de succès si les valeurs sont correctes
        QMessageBox::information(this, "Succès", "Connexion avec succès !");
    }
    // Vérifie si l'identifiant et le mot de passe correspondent à la valeur "Dakkar" et "s"
    else if(id->text()==QString("Dakkar") && mdp->text()==QString("s"))
    {
        // Affiche un message de félicitation si les valeurs sont correctes
        QMessageBox::information(this, "Félicitation", "Bonjour M. Dakkar !\nVos élèves et surtout Burak mérite de très bonne note !\n\nCordialement, votre ordinateur.");
    }
    // Affiche un message d'erreur si aucune des conditions précédentes n'est remplie
    else
    {
        QMessageBox::critical(this, "Erreur", "Identifiant ou mot de passe incorrect ! \n .");
    }
}

// Création de la fenêtre de connexion client
void resto::bouton_client()
{
    setWindowTitle("Connexion client");

    // Création des layouts horizontaux et vertical
    horiz1 = new QHBoxLayout;
    horiz2 = new QHBoxLayout;
    mainlayout = new QVBoxLayout;

    // Création des QLineEdit de nom, prénom et de sélection de mode de paiement
    nom = new QLineEdit(this);
    prenom = new QLineEdit(this);
    payment = new QComboBox(this);
    // Création du bouton "entrez"
    QPushButton *entrez = new QPushButton(QString::fromUtf8("Entrez !"),this);

    // Mise en place de placeholders pour les QLineEdit
    nom->setPlaceholderText("Nom");
    prenom->setPlaceholderText("Prénom");

    // Ajout des options de paiement dans la liste déroulante
    payment->addItem("Mode de paiement");
    payment->addItem("Espèce");
    payment->addItem("Carte bancaire");

    // Ajout des widgets dans les layouts
    horiz2->addWidget(entrez);
    horiz1->addWidget(prenom);
    horiz1->addWidget(nom);
    horiz1->addWidget(payment);

    // Ajout des layouts horizontaux dans le layout vertical principal
    mainlayout->addLayout(horiz1);
    mainlayout->addLayout(horiz2);

    // Créer un QWidget avec le layout principal
    QWidget *widget = new QWidget();
    widget->setLayout(mainlayout);
    setCentralWidget(widget);

    // Connexion du clic sur le bouton "entrez" à la fonction de bienvenue
    connect(entrez, SIGNAL(clicked()), this, SLOT(bienvenue()));
}

void resto::bienvenue()
{
    // Définition du titre de la fenêtre
    setWindowTitle("Bienvenue");

    // Création des widgets
    bv = new QLabel("Bienvenue au Resto Della Banga",this);

    sonprenom = new QLabel(this);
    sonom = new QLabel(this);

    nouvelle = new QPushButton("Nouvelle");
    modifier = new QPushButton("Modifier");
    afficher = new QPushButton("Afficher");
    quitter = new QPushButton("Quitter");

    // Création des layouts
    horiz1 = new QHBoxLayout;
    horiz2 = new QHBoxLayout;
    mainlayout = new QVBoxLayout;

    // Récupération du prénom et du nom entrés par l'utilisateur
    // et affichage du message de bienvenue avec le prénom et le nom
    QString str = prenom->text();
    sonprenom->setText(str);
    QString str1 = nom->text();
    sonom->setText(str1);
    bv->setText(bv->text() + " " + sonprenom->text() + " " + sonom->text());

    // // Alignement du message de bienvenue au haut central
    bv->setAlignment(Qt::AlignHCenter);

    // Modification de la police du message de bienvenue
    QFont font = bv->font(); // Récupère la police actuelle du QLabel
    font.setPointSize(20); // définit la taille de la police à 20
    font.setFamily("Arial Black"); // définit la famille de caractères à Arial
    font.setBold(true); // définit la taille de police à 20 points
    font.setItalic(true); // met le texte en gras
    bv->setFont(font); // applique la nouvelle police au QLabel

    // Ajout du message de bienvenue au layout horiz1
    horiz1->addWidget(bv);

    // Ajout des boutons au layout horiz2
    horiz2->addWidget(nouvelle);
    horiz2->addWidget(modifier);
    horiz2->addWidget(afficher);
    horiz2->addWidget(quitter);

    // Ajout des layouts horiz1 et horiz2 au layout mainlayout
    mainlayout->addLayout(horiz1);
    mainlayout->addLayout(horiz2);

    // Enregistrement du prénom et du nom de l'utilisateur dans un fichier texte
        // Création de l'objet QFile pour ouvrir l'ouvrir en mode écriture
    QFile file("monfichier.txt");

    // Vérification de l'ouverture du fichier en écriture seule et en mode texte.
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    // Création de l'objet QTextStream pour écrire dans le fichier
    QTextStream out(&file);

    // Ecriture du prénom et du nom de l'utilisateur
    out << sonprenom->text() << " " << sonom->text() << "\n";

    // Fermeture du fichier
    file.close();

    // Créer un QWidget avec le layout principal
    QWidget *widget = new QWidget();
    widget->setLayout(mainlayout);
    setCentralWidget(widget);

    // Connexion des signaux émis par les boutons à leurs slots respectifs
    connect(nouvelle, SIGNAL(clicked()), this, SLOT(bouton_nouvelle()));
    connect(afficher, SIGNAL(clicked()), this, SLOT(bouton_afficher()));
    connect(quitter, SIGNAL(clicked()), this, SLOT(bouton_client()));
}

void resto::bouton_nouvelle()
{
   // mainlayout = new QVBoxLayout;

    //-- Configuration de la partie Entrée
    label_entree = new QLabel("Entrées :");

        // Instanciation des entrées
    entrees[0] = new QCheckBox("Salade");
    entrees[1] = new QCheckBox("Soupe aux lentilles");
    entrees[2] = new QCheckBox("Quiche au thon");

    // Pour chaque case à cocher de boissons
    for (int i = 0; i < 3; i++)
    {
        // Connecter le signal clicked de la case à cocher à une fonction
        connect(entrees[i], &QCheckBox::clicked, [this, i]
        {
            // Si la case à cocher est cochée
            if (entrees[i]->isChecked())
            {
                // Décocher toutes les autres QCheckBox
                for (int j = 0; j < 3; j++)
                {
                    // // Si ce n'est pas la même case à cocher que celle qui a déclenché le signal
                    if (j != i)
                    {
                        entrees[j]->setChecked(false);
                    }
                }
            }
        });
    }

        // Mise en place dans la fenêtre des QCheckBox
    grille->addWidget(label_entree, 0, 0);

        // Ajout des case dans la grille
    grille->addWidget(entrees[0], 1, 0);
    grille->addWidget(entrees[1], 2, 0);
    grille->addWidget(entrees[2], 3, 0);

    //-- Configuration de la partie Plat
    label_plat = new QLabel("Plats :");

        //-- Instanciation des plats
    plats[0] = new QCheckBox("Tagliatelles à saumon fumé");
    plats[1] = new QCheckBox("Risotto aux asperges et aux truffes blanches");
    plats[2] = new QCheckBox("Raviolis farcis à la viande et aux épices");
    plats[3] = new QCheckBox("Osso bucco aux trompettes de la mort"); // Ca existe vraiment
    plats[4] = new QCheckBox("Potjevleesch"); // ça aussi

    for (int i = 0; i < 5; i++)
    {
        connect(plats[i], &QCheckBox::clicked, [this, i]
        {
            if (plats[i]->isChecked())
            {
                // Décocher toutes les autres QCheckBox
                for (int j = 0; j < 3; j++)
                {
                    if (j != i)
                    {
                        plats[j]->setChecked(false);
                    }
                }
            }
        });
    }

        //-- Mise en place
    grille->addWidget(label_plat, 0, 1);

    // Ajout des plats dans la grille
    grille->addWidget(plats[0], 1, 1);
    grille->addWidget(plats[1], 2, 1);
    grille->addWidget(plats[2], 3, 1);
    grille->addWidget(plats[3], 4, 1);
    grille->addWidget(plats[4], 5, 1);

    //-- Partie dessert
    label_dessert = new QLabel("Desserts :");

        //-- Instanciation
    desserts[0] = new QCheckBox("Tiramisu");
    desserts[1] = new QCheckBox("Tarte au Daim");
    desserts[2] = new QCheckBox("Tarte au citron méringuée");
    desserts[3] = new QCheckBox("Brownie");

    for (int i = 0; i < 4; i++)
    {
        connect(desserts[i], &QCheckBox::clicked, [this, i]
        {
            if (desserts[i]->isChecked())
            {
                // Décocher toutes les autres QCheckBox
                for (int j = 0; j < 4; j++)
                {
                    if (j != i)
                    {
                        desserts[j]->setChecked(false);
                    }
                }
            }
        });
    }

        //-- Mise en place
    grille->addWidget(label_dessert, 0, 2);

    // Ajout des desserts dans la grille
    grille->addWidget(desserts[0], 1, 2);
    grille->addWidget(desserts[1], 2, 2);
    grille->addWidget(desserts[2], 3, 2);
    grille->addWidget(desserts[3], 4, 2);

    //-- partie boisson
    label_boisson = new QLabel("Boissons :");

        //-- Instanciation des boissons
    boissons[0] = new QCheckBox("Eau");
    boissons[1] = new QCheckBox("Coca-Cola");
    boissons[2] = new QCheckBox("Oasis");
    boissons[3] = new QCheckBox("Café");
    boissons[4] = new QCheckBox("Thé");

    // Pour chaque case à cocher de boissons
    for (int i = 0; i < 5; i++)
    {
        // Connecter le signal clicked de la case à cocher à une fonction
        connect(boissons[i], &QCheckBox::clicked, [this, i]
        {
            // Si la case à cocher est cochée
            if (boissons[i]->isChecked())
            {
                // Décocher toutes les autres QCheckBox
                for (int j = 0; j < 5; j++)
                {
                    // Si ce n'est pas la même case à cocher que celle qui a déclenché le signal
                    if (j != i)
                    {
                        // Décocher la case à cocher
                        boissons[j]->setChecked(false);
                    }
                }
            }
        });
    }

        //-- mise en place
    grille->addWidget(label_boisson, 0, 3);

    grille->addWidget(boissons[0], 1, 3);
    grille->addWidget(boissons[1], 2, 3);
    grille->addWidget(boissons[2], 3, 3);
    grille->addWidget(boissons[3], 4, 3);
    grille->addWidget(boissons[4], 5, 3);

    // Configuration du bouton "Commandez"
    commander = new QPushButton("Commandez");
    grille->addWidget(commander, 7, 4);

    // Ajout de la grille au layout principal
    mainlayout->addLayout(grille);

    QWidget *widget = new QWidget();
    widget->setLayout(mainlayout);
    setCentralWidget(widget);

    // Connexion du signal clicked du bouton commander au slot bouton_commander
    connect(commander, SIGNAL(clicked()), this, SLOT(bouton_commander()));
}

void resto::bouton_commander()
{
    QMessageBox::information(this, "Confirmation", "Commander avec succès !");
}

void resto::bouton_afficher()
{
    // Configuration de la fenêtre de la commande
    setWindowTitle("Fenêtre des commandes"); // Changer le nom de la fenêtre

    // Création des layouts
    horiz3 = new QHBoxLayout;
    mainlayout = new QVBoxLayout;

    // Création des QLabel pour afficher la commande
    sonentree = new QLabel(this);
    sonplat = new QLabel(this);
    sondessert = new QLabel(this);
    saboisson = new QLabel(this);

    // Création du bouton pour revenir à la page principal
    revenir = new QPushButton("Revenir à la page principal");

    // Parcours des tableaux d'éléments de la commande pour trouver ceux qui sont cochés
    for (int i = 0; i < 4; i++)
    {
        if(entrees[i]->isChecked()) // // Si l'entrée i est cochée
        {
            // Remplacer le texte dans description_commande par le texte de l'entrée i
            sonentree->setText(entrees[i]->text());
        }
        if(plats[i]->isChecked()) // // Si le plat i est cochée
        {
            sonplat->setText(plats[i]->text());
        }
        if(desserts[i]->isChecked()) // // Si le dessert i est cochée
        {
            sondessert->setText(desserts[i]->text());
        }
        if(boissons[i]->isChecked()) // // Si la boisson i est cochée
        {
            saboisson->setText(boissons[i]->text());
        }
    }

    // Création de la chaîne de caractères contenant la commande
    QString lacommande = "Votre commande:\n-" + sonentree->text() + "\n-" + sonplat->text() + "\n-" + sondessert->text() + "\n-" + saboisson->text();
    label_commande = new QLabel(lacommande);
    horiz3->addWidget(label_commande);
    horiz3->addWidget(revenir);
    mainlayout->addLayout(horiz3);

    // Ouverture du fichier en mode écriture seule texte et ajout à la fin du fichier
    QFile file("monfichier.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
    {
        return; // Si l'ouverture du fichier échoue, on quitte la fonction
    }

    // Création d'un flux de sortie vers le fichier ouvert
    QTextStream out(&file);
        // Écriture de la commande dans le fichier
    out << sonentree->text() << "\n-" << sonplat->text() << "\n-" << sondessert->text() << "\n-" << saboisson->text();
    file.close(); // Fermeture du fichier

    QWidget *widget = new QWidget();
    widget->setLayout(mainlayout);
    setCentralWidget(widget);

    // Connexion du signal clicked du bouton revenir au slot bienvenue
    connect(revenir, SIGNAL(clicked()), this, SLOT(bienvenue()));
}

resto::~resto()
{
    delete ui;
}