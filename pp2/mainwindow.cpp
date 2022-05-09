#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QThread>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->label, SIGNAL(sendMousePosition(QPoint&)), this, SLOT(printMousePosition(QPoint&)));
    //connect(createcanvasDialog, SIGNAL(accept()), this, SLOT(receiveCanvas));
    //connect(labelCreate, SIGNAL(sendMousePosition(QPoint&)), this, SLOT(printMousePosition(QPoint&)));

    QImage *image = new QImage(300, 300, QImage::Format_RGB32);

    for (int i = 0 ; i < 300; i++) {
        for (int j = 0; j < 300; j++) {
            image->setPixel(i, j, qRgb(255, 255, 255));
        }
    }

    ui->label->setPixmap(QPixmap::fromImage(*image));

    //ui->label.
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::receiveCanvas(int& x, int& y) {
    qDebug() << "fromWindowAccept";
    qDebug() << x << y;
}

void MainWindow::printMousePosition(QPoint &pos) {
    qDebug() << pos.x() << pos.y();

    QPixmap labelImage = ui->label->pixmap();
    QImage imageLabel = labelImage.toImage();


    //       i = - x  i < x

    int grosor = 10;

    for (int i = -grosor; i < grosor; i++) {
        for (int j = -grosor; j < grosor; j++) {
            imageLabel.setPixel(pos.x() + i, pos.y() + j, qRgb(220, 123, 110));
        }
    }

    /*
    for (int i = -10; i < 10; i++) {
        imageLabel.setPixel(pos.x(), pos.y() + i, qRgb(220, 123, 110));
    } */

    ui->label->setPixmap(QPixmap::fromImage(imageLabel));
}


void MainWindow::on_pushButton_clicked()
{
    QImage *image = new QImage(500, 500, QImage::Format_ARGB32);
    labelCreate->setText("OOOOnvjbjbbubububu");
    labelCreate->setGeometry(10, 10, 1000, 1000);
    image->fill(0);
    labelCreate->setPixmap(QPixmap::fromImage(*image));
    qDebug();
}


void MainWindow::on_pushButton_2_clicked()
{
    QPixmap labelImage = labelCreate->pixmap();
    QImage imageLabel = labelImage.toImage();
    for (int i = 0 ; i < 500; i++) {
        for (int j = 0; j < 500; j++) {
            imageLabel.setPixel(i, j, qRgba(i % 200, j % 200, i + j % 200, 28));
        }
    }
    labelCreate->setPixmap(QPixmap::fromImage(imageLabel));
}


void MainWindow::on_pushButton_3_clicked()
{
    createcanvasDialog = new createCanvasDialog();
    connect(createcanvasDialog, SIGNAL(accept(int&, int&)), this, SLOT(receiveCanvas(int&, int&)));
    createcanvasDialog->setModal(true);
    createcanvasDialog->exec();
}


void MainWindow::on_pushButton_4_clicked()
{
    QImage *image = new QImage(300, 300, QImage::Format_RGB32);


    for (int i = 0 ; i < 300; i++) {
        for (int j = 0; j < 300; j++) {
            image->setPixel(i, j, qRgb(255, 255, 255));
        }
    }


    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < 40; j++) {
            image->setPixel(i, j, ui->label->matrix[0][0]);
        }
    }

    for (int i = 40; i < 80; i++) {
        for (int j = 0; j < 40; j++) {
            image->setPixel(i, j, ui->label->matrix[0][1]);
        }
    }

    for (int i = 0; i < 40; i++) {
        for (int j = 40; j < 80; j++) {
            image->setPixel(i, j, ui->label->matrix[1][0]);
        }
    }

    for (int i = 40; i < 80; i++) {
        for (int j = 40; j < 80; j++) {
            image->setPixel(i, j, ui->label->matrix[1][1]);
        }
    }

    ui->label->setPixmap(QPixmap::fromImage(*image));

}

