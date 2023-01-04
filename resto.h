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
#include <QPushButton>
#include <QStackedLayout>
#include <QComboBox>
#include <QString>
#include <QCheckBox>
#include <QDebug>
#include <QMessageBox>
#include <QSpinBox>

QT_BEGIN_NAMESPACE
namespace Ui { class resto; }
QT_END_NAMESPACE

class resto : public QMainWindow
{
    Q_OBJECT

public:
    resto(QWidget *parent = nullptr);
    ~resto();

    //-- Instancier les layouts
    QVBoxLayout *mainlayout;
    QHBoxLayout *horiz1;
    QHBoxLayout *horiz2;
    QHBoxLayout *horiz3;
    QGridLayout *grille = new QGridLayout;

    QLabel *question = new QLabel(this);
    QLabel *bv;
    QLabel *sonprenom;
    QLabel *sonom;
    QLabel *label_entree;
    QLabel *label_plat;
    QLabel *label_dessert;
    QLabel *label_boisson;
    QLabel *label_commande;
    QLabel *sonentree;
    QLabel *sonplat;
    QLabel *sondessert;
    QLabel *saboisson;

    QLineEdit *id;
    QLineEdit *mdp;
    QLineEdit *nom;
    QLineEdit *prenom;

    QPushButton *nouvelle;
    QPushButton *afficher;
    QPushButton *modifier;
    QPushButton *quitter;
    QPushButton *commander;

    QComboBox *payment;

    //-- Création des entrées
    QCheckBox *salade;
    QCheckBox *soupe_lentille;
    QCheckBox *quiche;

    //-- Création des plats
    QCheckBox *tagliatelle;
    QCheckBox *osso_bucco;
    QCheckBox *potjevleesch;
    QCheckBox *risotto;
    QCheckBox *raviolis;

    //-- Création des desserts
    QCheckBox *tiramisu;
    QCheckBox *daim;
    QCheckBox *citron_meringuee;
    QCheckBox *brownie;

    //-- Création des boissons
    QCheckBox *eau;
    QCheckBox *coca;
    QCheckBox *oasis;
    QCheckBox *cafe;
    QCheckBox *the;
    QCheckBox *entrees[3];
    QCheckBox *plats[5];
    QCheckBox *desserts[4];
    QCheckBox *boissons[5];

public slots:
    void bouton_gerant();
    void bouton_client();
    void bouton_connexion();
    void bienvenue();
    void bouton_commander();
//-- boutons principaux
    void bouton_nouvelle();
    //void bouton_modifier();
    void bouton_afficher();
   //void bouton_quitter();

    /*void tabChanged(int index);*/

private:
    Ui::resto *ui;

};
#endif // RESTO_H
