#ifndef CANVASIMAGE_H
#define CANVASIMAGE_H

#include <QLabel>
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QMouseEvent>

class canvasImage : public QLabel
{
    Q_OBJECT
public:
    canvasImage(QWidget *parent = 0);
    ~canvasImage();
    uint32_t matrix[2][2] = {{0xfcba03, 0x000000},
                             {0xff0000, 0xffff00}};

private:


protected:
    void mouseMoveEvent(QMouseEvent *event);

signals:
    void sendMousePosition(QPoint&);
};

#endif // CANVASIMAGE_H
