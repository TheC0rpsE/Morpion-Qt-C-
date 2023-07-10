#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QMessageBox>
#include <QInputDialog>
#include <iostream>
int score_x=0;
int score_o=0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connectButtons();
    resetGame();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Score(QString s){
    if(s=="X"){
        score_x++;
        ui->SCORE_X->setText(s+" : "+QString::number(score_x));
    }else{
        score_o++;
        ui->SCORE_O->setText(s+" : "+QString::number(score_o));
    }
}

bool MainWindow::verifierEgaliter(){
    if(ui->B1->text()!="" && ui->B2->text()!="" && ui->B3->text()!="" && ui->B4->text()!="" && ui->B5->text()!="" && ui->B6->text()!="" && ui->B7->text()!="" && ui->B8->text()!="" && ui->B9->text()!=""){
        return true;
    }
    else{
        return false;
    }
}
bool MainWindow::verifierVictoire(QString symbole){
    if(ui->B1->text()==symbole && ui->B2->text()==symbole && ui->B3->text()==symbole ){
        return true;
    }
    if(ui->B4->text()==symbole && ui->B5->text()==symbole && ui->B6->text()==symbole){
        return true;
    }
    if(ui->B7->text()==symbole && ui->B8->text()==symbole && ui->B9->text()==symbole){
        return true;
    }

    if(ui->B1->text()==symbole && ui->B4->text()==symbole && ui->B7->text()==symbole ){
        return true;
    }
    if(ui->B2->text()==symbole && ui->B5->text()==symbole && ui->B8->text()==symbole){
        return true;
    }
    if(ui->B3->text()==symbole && ui->B6->text()==symbole && ui->B9->text()==symbole){
        return true;
    }

    if(ui->B1->text()==symbole && ui->B5->text()==symbole && ui->B9->text()==symbole ){
        return true;
    }
    if(ui->B3->text()==symbole && ui->B5->text()==symbole && ui->B7->text()==symbole){
        return true;
    }
    return false;
}

void MainWindow::handleButtonClick()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (!button)
        return;

    // Vérifier si la case est déjà jouée
    if (button->text() != "")
        return;

    button->setText(currentPlayer);

    if(verifierVictoire(currentPlayer)){
        QMessageBox::information(this, "", "Victoire joueur "+currentPlayer+" a gagné !");
        Score(currentPlayer);
        resetGame();
        return;
    }else if(verifierEgaliter()){
        QMessageBox::information(this, "","Egalité !!!");
        resetGame();
        return;
}
    // Passer au joueur suivant
    currentPlayer = (currentPlayer == "X") ? "O" : "X";
}
void MainWindow::connectButtons()
{
    // Connecter les signaux des boutons cliqués aux slots
    connect(ui->B1, &QPushButton::clicked, this, &MainWindow::handleButtonClick);
    connect(ui->B2, &QPushButton::clicked, this, &MainWindow::handleButtonClick);
    connect(ui->B3, &QPushButton::clicked, this, &MainWindow::handleButtonClick);
    connect(ui->B4, &QPushButton::clicked, this, &MainWindow::handleButtonClick);
    connect(ui->B5, &QPushButton::clicked, this, &MainWindow::handleButtonClick);
    connect(ui->B6, &QPushButton::clicked, this, &MainWindow::handleButtonClick);
    connect(ui->B7, &QPushButton::clicked, this, &MainWindow::handleButtonClick);
    connect(ui->B8, &QPushButton::clicked, this, &MainWindow::handleButtonClick);
    connect(ui->B9, &QPushButton::clicked, this, &MainWindow::handleButtonClick);

    connect(ui->B_RECOMMENCER, &QPushButton::clicked, this, &MainWindow::resetGame);
    connect(ui->RESET_SCORE,&QPushButton::clicked, this, &MainWindow::resetScore);
}

void MainWindow::resetScore(){
      ui->SCORE_X->setText("X : 0");
      ui->SCORE_O->setText("O : 0");
}

void MainWindow::resetGame()
{
    // Remettre à zéro le plateau de jeu et le joueur actuel
    currentPlayer = "X";
    ui->B1->setText("");
    ui->B2->setText("");
    ui->B3->setText("");
    ui->B4->setText("");
    ui->B5->setText("");
    ui->B6->setText("");
    ui->B7->setText("");
    ui->B8->setText("");
    ui->B9->setText("");
}
