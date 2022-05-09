#ifndef CREATECANVASDIALOG_H
#define CREATECANVASDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class createCanvasDialog; }
QT_END_NAMESPACE

class createCanvasDialog : public QDialog
{
    Q_OBJECT

public:
    createCanvasDialog(QWidget *parent = nullptr);
    ~createCanvasDialog();

private:
    Ui::createCanvasDialog *ui;
};
#endif // CREATECANVASDIALOG_H
