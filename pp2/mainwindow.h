#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "canvasimage.h"
#include "createcanvasdialog.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    Ui::MainWindow *ui;
    ~MainWindow();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void printMousePosition(QPoint& pos);

    void receiveCanvas(int& x, int& y);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    canvasImage *labelCreate = new canvasImage(this);
    createCanvasDialog *createcanvasDialog;




};
#endif // MAINWINDOW_H
