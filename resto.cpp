#include "resto.h"
#include "ui_resto.h"

// TESTTTTTT

resto::resto(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::resto)
{
    ui->setupUi(this);

    setWindowTitle("Fenêtre de choix"); // Changer le nom de la fenêtre
   // resize(200,100); // Redimensionner la page

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

    //-- 2. Bouton Client
    QPushButton *client = new QPushButton("Client");
    QPushButton *gerant = new QPushButton("Gérant");

    horiz2->addWidget(client);
    horiz2->addWidget(gerant);
    horiz1->addWidget(question);

    mainlayout->addLayout(horiz1);
    mainlayout->addLayout(horiz2);

    // setLayout(mainlayout); //
    adjustSize(); // Ajuster la fenêtre automatiquement

    QWidget *widget = new QWidget();
    widget->setLayout(mainlayout);
    setCentralWidget(widget);

    //-- Signal - Slot des boutons
    connect(gerant, SIGNAL(clicked()),this, SLOT(bouton_gerant()));
    connect(client, SIGNAL(clicked()), this, SLOT(bouton_client()));
}

void resto::bouton_gerant()
{
    setWindowTitle("Connexion pour le gérant"); // Changer le nom de la fenêtre

    horiz1 = new QHBoxLayout;
    horiz2 =  new QHBoxLayout;
    horiz3 =  new QHBoxLayout;
    mainlayout = new QVBoxLayout;

    id = new QLineEdit(this);
    mdp = new QLineEdit(this);

    //-- 2. Personnaliser les widgets
        //-- 2.1 Identifiant & Mot de passe
        id->setStyleSheet("color: #0a214c; background-color: #C19A6B");
        mdp->setStyleSheet("color: #0a214c; background-color: #C19A6B");
        id->setPlaceholderText("Identifiant");
        mdp->setPlaceholderText("Mot de passe");

        QPushButton *connexion = new QPushButton(QString::fromUtf8("Connexion"),this);

        horiz2->addWidget(id);
        horiz1->addWidget(mdp);
        horiz3->addWidget(connexion);

        mainlayout->addLayout(horiz2);
        mainlayout->addLayout(horiz1);
        mainlayout->addLayout(horiz3);

        QWidget *widget = new QWidget();
        widget->setLayout(mainlayout);
        setCentralWidget(widget);

        connect(connexion, SIGNAL(clicked()), this, SLOT(bouton_connexion()));
}

void resto::bouton_connexion()
{
    if(id->text()==QString("Blabla") && mdp->text()==QString("test"))
    {
        QMessageBox::information(this, "Succès", "Connexion avec succès !");
    }
    else if(id->text()==QString("Dakkar") && mdp->text()==QString("s"))
    {
        QMessageBox::information(this, "Félicitation", "Bonjour M. Dakkar !\nVos élèves et surtout Burak mérite de très bonne note !\n\nCordialement, votre ordinateur.");
    }

    else
    {
    QMessageBox::critical(this, "Erreur", "Identifiant ou mot de passe incorrect ! \n .");
    }
}

void resto::bouton_client()
{
    setWindowTitle("Connexion client");

    horiz1 = new QHBoxLayout;
    horiz2 = new QHBoxLayout;
    mainlayout = new QVBoxLayout;

    nom = new QLineEdit(this);
    prenom = new QLineEdit(this);
    payment = new QComboBox(this);
    QPushButton *entrez = new QPushButton(QString::fromUtf8("Entrez !"),this);

    nom->setPlaceholderText("Nom");
    prenom->setPlaceholderText("Prénom");

    payment->addItem("Mode de paiement");
    payment->addItem("Espèce");
    payment->addItem("Carte bancaire");

    horiz2->addWidget(entrez);
    horiz1->addWidget(prenom);
    horiz1->addWidget(nom);
    horiz1->addWidget(payment);

    mainlayout->addLayout(horiz1);
    mainlayout->addLayout(horiz2);

    QWidget *widget = new QWidget();
    widget->setLayout(mainlayout);
    setCentralWidget(widget);

    connect(entrez, SIGNAL(clicked()), this, SLOT(bienvenue()));
}

void resto::bienvenue()
{
    setWindowTitle("Bienvenue");

    bv = new QLabel("Bienvenue au Resto Della Banga",this);

    sonprenom = new QLabel(this);
    sonom = new QLabel(this);

    nouvelle = new QPushButton("Nouvelle");
    modifier = new QPushButton("Modifier");
    afficher = new QPushButton("afficher");
    quitter = new QPushButton("quitter");

    horiz1 = new QHBoxLayout;
    horiz2 = new QHBoxLayout;
    mainlayout = new QVBoxLayout;

    QString str = prenom->text();
    sonprenom->setText(str);
    QString str1 = nom->text();
    sonom->setText(str1);
    bv->setText(bv->text() + " " + sonprenom->text() + " " + sonom->text());
    bv->setAlignment(Qt::AlignHCenter);

    bv->setAlignment(Qt::AlignHCenter);
    QFont font = bv->font(); // Récupère la police actuelle du QLabel
    font.setPointSize(20); // définit la taille de la police à 20
    font.setFamily("Arial Black"); // définit la famille de caractères à Arial
    font.setBold(true); // définit la taille de police à 20 points
    font.setItalic(true); // met le texte en gras
    bv->setFont(font); // applique la nouvelle police au QLabel

    horiz1->addWidget(bv);
    horiz2->addWidget(nouvelle);
    horiz2->addWidget(modifier);
    horiz2->addWidget(afficher);
    horiz2->addWidget(quitter);

    mainlayout->addLayout(horiz1);
    mainlayout->addLayout(horiz2);

    QWidget *widget = new QWidget();
    widget->setLayout(mainlayout);
    setCentralWidget(widget);

    connect(nouvelle, SIGNAL(clicked()), this, SLOT(bouton_nouvelle()));
    connect(afficher, SIGNAL(clicked()), this, SLOT(bouton_afficher()));
}

void resto::bouton_nouvelle()
{
   // mainlayout = new QVBoxLayout;

    //-- Configuration de la partie Entrée
    label_entree = new QLabel("Entrées :");

        //-- Instanciation des entrées
    /*QCheckBox *salade = new QCheckBox("Salade");
    QCheckBox *soupe_lentille = new QCheckBox("Soupe aux lentilles");
    QCheckBox *quiche = new QCheckBox("Quiche au thon");*/

    entrees[0] = new QCheckBox("Salade");
    entrees[1] = new QCheckBox("Soupe aux lentilles");
    entrees[2] = new QCheckBox("Quiche au thon");


        //-- Mise en place dans la fenêtre des QCheckBox
    grille->addWidget(label_entree, 0, 0);

    grille->addWidget(entrees[0], 1, 0);
    grille->addWidget(entrees[1], 2, 0);
    grille->addWidget(entrees[2], 3, 0);
    /*grille->addWidget(salade, 1, 0);
    grille->addWidget(soupe_lentille, 2, 0);
    grille->addWidget(quiche, 3, 0);*/


    //-- Configuration de la partie Plat
    label_plat = new QLabel("Plats :");

        //-- Instanciation des plats
    /*QCheckBox *tagliatelle = new QCheckBox("Tagliatelles à saumon fumé");
    QCheckBox *risotto = new QCheckBox("Risotto aux asperges et aux truffes blanches");
    QCheckBox *raviolis = new QCheckBox("Raviolis farcis à la viande et aux épices");
    QCheckBox *osso_bucco = new QCheckBox("Osso bucco aux trompettes de la mort"); // Ca existe vraiment
    QCheckBox *potjevleesch = new QCheckBox("Potjevleesch"); // ça aussi*/

    plats[0] = new QCheckBox("Tagliatelles à saumon fumé");
    plats[1] = new QCheckBox("Risotto aux asperges et aux truffes blanches");
    plats[2] = new QCheckBox("Raviolis farcis à la viande et aux épices");
    plats[3] = new QCheckBox("Osso bucco aux trompettes de la mort"); // Ca existe vraiment
    plats[4] = new QCheckBox("Potjevleesch"); // ça aussi


        //-- Mise en place
    grille->addWidget(label_plat, 0, 1);

    grille->addWidget(plats[0], 1, 1);
    grille->addWidget(plats[1], 2, 1);
    grille->addWidget(plats[2], 3, 1);
    grille->addWidget(plats[3], 4, 1);
    grille->addWidget(plats[4], 5, 1);

    /*grille->addWidget(tagliatelle, 1, 1);
    grille->addWidget(risotto, 2, 1);
    grille->addWidget(raviolis, 3, 1);
    grille->addWidget(osso_bucco, 4, 1);
    grille->addWidget(potjevleesch, 5, 1);*/


    //-- Partie dessert
    label_dessert = new QLabel("Desserts :");

        //-- Instanciation
    /*QCheckBox *tiramisu = new QCheckBox("Tiramisu");
    QCheckBox *daim = new QCheckBox("Tarte au Daim");
    QCheckBox *citron_meringuee = new QCheckBox("Tarte au citron méringuée");
    QCheckBox *brownie = new QCheckBox("Brownie");*/

    desserts[0] = new QCheckBox("Tiramisu");
    desserts[1] = new QCheckBox("Tarte au Daim");
    desserts[2] = new QCheckBox("Tarte au citron méringuée");
    desserts[3] = new QCheckBox("Brownie");


        //-- Mise en place
    grille->addWidget(label_dessert, 0, 2);

    grille->addWidget(desserts[0], 1, 2);
    grille->addWidget(desserts[1], 2, 2);
    grille->addWidget(desserts[2], 3, 2);
    grille->addWidget(desserts[3], 4, 2);

    /*grille->addWidget(tiramisu, 1, 2);
    grille->addWidget(daim, 2, 2);
    grille->addWidget(citron_meringuee, 3, 2);
    grille->addWidget(brownie, 4, 2);*/


    //-- partie boisson
    label_boisson = new QLabel("Boissons :");

        //-- Instanciation
    /*QCheckBox *eau = new QCheckBox("Eau");
    QCheckBox *coca = new QCheckBox("Coca-Cola");
    QCheckBox *oasis = new QCheckBox("Oasis");
    QCheckBox *cafe = new QCheckBox("Café");
    QCheckBox *the = new QCheckBox("Thé");*/

    boissons[0] = new QCheckBox("Eau");
    boissons[1] = new QCheckBox("Coca-Cola");
    boissons[2] = new QCheckBox("Oasis");
    boissons[3] = new QCheckBox("Café");
    boissons[4] = new QCheckBox("Thé");



        //-- mise en place
    grille->addWidget(label_boisson, 0, 3);

    grille->addWidget(boissons[0], 1, 3);
    grille->addWidget(boissons[1], 2, 3);
    grille->addWidget(boissons[2], 3, 3);
    grille->addWidget(boissons[3], 4, 3);
    grille->addWidget(boissons[4], 5, 3);

    /*grille->addWidget(eau, 1, 3);
    grille->addWidget(coca, 2, 3);
    grille->addWidget(oasis, 3, 3);
    grille->addWidget(cafe, 4, 3);
    grille->addWidget(the, 5, 3);*/

    commander = new QPushButton("Commandez");
    grille->addWidget(commander, 7, 4);

    mainlayout->addLayout(grille);

    QWidget *widget = new QWidget();
    widget->setLayout(mainlayout);
    setCentralWidget(widget);

    connect(commander, SIGNAL(clicked()), this, SLOT(bouton_commander()));
}

void resto::bouton_commander()
{
    QMessageBox::information(this, "Confirmation", "Commander avec succès !");
}

void resto::bouton_afficher()
{
    setWindowTitle("Fenêtre des commandes"); // Changer le nom de la fenêtre

    horiz1 = new QHBoxLayout;
    mainlayout = new QVBoxLayout;

    sonentree = new QLabel(this);
    sonplat = new QLabel(this);
    sondessert = new QLabel(this);
    saboisson = new QLabel(this);

    for (int i = 0; i < 4; i++)
    {
        if(entrees[i]->isChecked()) // // Si l'entrée i est cochée
        {
            // Remplacer le texte dans description_commande par le texte de l'entrée i
            sonentree->setText(entrees[i]->text());
        }
        if(plats[i]->isChecked()) // // Si l'entrée i est cochée
        {
            sonplat->setText(plats[i]->text());
        }
        if(desserts[i]->isChecked()) // // Si l'entrée i est cochée
        {
            sondessert->setText(desserts[i]->text());
        }
        if(boissons[i]->isChecked()) // // Si l'entrée i est cochée
        {
            saboisson->setText(boissons[i]->text());
        }
    }
    QString lacommande = "Votre commande:\n-" + sonentree->text() + "\n-" + sonplat->text() + "\n-" + sondessert->text() + "\n-" + saboisson->text();
    label_commande = new QLabel(lacommande);
    horiz1->addWidget(label_commande);
    mainlayout->addLayout(horiz1);

    QWidget *widget = new QWidget();
    widget->setLayout(mainlayout);
    setCentralWidget(widget);
}

/*void resto::tabChanged(int index)
{
// Traitement à effectuer lorsque l'onglet actif change
qDebug() << "Onglet actif : " << index;
}*/

resto::~resto()
{
    delete ui;
}
