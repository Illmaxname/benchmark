#include <QApplication>
#include <QPainter>
#include "print.h"

RadialGradient::RadialGradient(QWidget *parent) : QWidget(parent)
{}

void RadialGradient::paintEvent(QPaintEvent *e){
    Q_UNUSED(e);

    doPainting();
}

void RadialGradient::doPainting(){
    QPainter painter(this);

    int h = height();
    int w = width();


    QRadialGradient grad1(w/2, h/2, 500);
    QRadialGradient grad2(100, 100, 100);

    grad1.setColorAt(0, Qt::yellow);
    grad1.setColorAt(0.3, QColor("#ffa500"));
    grad1.setColorAt(1, Qt::black);

    grad2.setColorAt(0, Qt::white);
    grad2.setColorAt(0.3, Qt::blue);
    grad2.setColorAt(1, Qt::black);

    painter.fillRect(0, 0, w, h, grad1);
    //painter.fillRect(0, 0, 200, 200, grad2);
}
