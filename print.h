#ifndef RADIAL_GRADIENT_H
#define RADIAL_GRADIENT_H

#include <QWidget>

class RadialGradient : public QWidget
{
public:
    explicit RadialGradient(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *e);

private:
    void doPainting();

signals:

};

#endif // RADIAL_GRADIENT_H
