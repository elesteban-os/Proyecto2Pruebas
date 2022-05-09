#include "createcanvasdialog.h"
#include "ui_createcanvasdialog.h"

createCanvasDialog::createCanvasDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::createCanvasDialog)
{
    ui->setupUi(this);
}

createCanvasDialog::~createCanvasDialog()
{
    delete ui;
}

