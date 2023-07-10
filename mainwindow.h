#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handleButtonClick();
    void resetGame();
    bool verifierVictoire(QString);
    bool verifierEgaliter();
    void Score(QString s);
    void resetScore();

private:
    Ui::MainWindow *ui;
    QString currentPlayer;  // Variable pour stocker le joueur actuel
    void connectButtons();
};


#endif // MAINWINDOW_H
