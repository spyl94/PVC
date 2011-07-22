#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <iostream>
#include <time.h>
#include "pvc.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public: //m�thodes
    MainWindow();
    ~MainWindow();

    void verifConfig();
    void displayTab();
    void displayFin(QString nomFichier);

private: //m�thodes
    void creerActions();
    void creerMenus();
    void creerBarresOutils();
    void creerBarreEtat();
    QLabel *messageStatus;

    QAction *actionQuitter;
    QAction *actionOuvrirFichier;
    QAction *actionPropos;
    QAction *actionOptions;
    QAction *actionLancer;
    QAction *actionChangerDepart;

    QProgressBar *progression;
    QStatusBar *barreEtat;

    QTableWidget *tableWidget;

private slots:
    void ouvrirFichier();
    void ouvrirOptions();
    void ouvrirPropos();
    void ouvrirChangerDepart();
    void saveOptions();
    void lancer();

private:
    bool lancerEnable; //autorise ou non le lancement.
    PVC c_pvc; //contient le pvc actuel
    long nombreVilles;
    QTime time; //permet de calculer le temps d'�x�cution.

    /*  Options  */
    QWidget fenetreOptions; //fen�tre pour saisir les param�tres
    QPushButton *valider;
    QSpinBox *cardinalite_pop, *nbIteration;
    QDoubleSpinBox *tauxMutation;
    QComboBox *methodeSelection;
    QString conf[5];

    /*  Cr�dits  */
    QWidget fenetrePropos;
    QLabel *label;

};

#endif // MAINWINDOW_H
