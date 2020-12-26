#pragma once
#ifndef CANVAS
#define CANVAS
#include <qwidget.h>
#include <QtWidgets>
#include "mMainWindow.h"



class Pile {
public:
    Pile(int a, int b) : x(a), y(b) {}
    ~Pile();
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }

private:
    int x;
    int y;
};

class Canvas : public QWidget
{
    Q_OBJECT

public:

    Canvas(mMainWindow* p);
    //~Canevas();

    void draw();
    void drawRectangle();
    void drawProvisoirRectangle();
    void drawCercle();
    void drawProvisoirCercle();
    void drawTrait();
    void drawProvisoirTrait();
    void fillUp();
    int filling(int x, int y, QRgb colcible, QRgb colrep);

    void paintEvent(QPaintEvent* event);

    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
public slots:
    void newCanvas();
    void saveCanvas();
    void openCanvas();
    void back_to_Canvas();

private:

    int xMove;
    int yMove;
    int xPress;
    int yPress;
    int xRelease;
    int yRelease;

    int pixActuel;
    int xMax;
    int yMax;

    QPainter* painter;
    QLabel* label;
    mMainWindow* pere;
    QGraphicsScene* scene;
    QGraphicsView* view;
    QImage* image;
    QVector<QPixmap*> pixmapListe;
    QPainterPath* path;
};

#endif
