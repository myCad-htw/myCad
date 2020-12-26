#pragma once
#ifndef HEADER_FENPRINCIPALE
#define HEADER_FENPRINCIPALE
#include <QtWidgets>

//QT Desiging 
class mMainWindow : public QMainWindow
{

    Q_OBJECT

public:
    mMainWindow();
    bool getDrawEnable();
    bool getRectangleEnable();
    bool getCercleEnable();
    bool getTraitEnable();
    bool getFillEnable();
    QColor getColor();
    int getValueSlider();

public slots:

    void slotDraw();
    void slotRectangle();
    void slotCercle();
    void slotTrait();
    void slotFill();
    void slotColor();

    void slotSlider(int x);

private:
    bool drawEnable;
    bool rectangleEnable;
    bool cercleEnable;
    bool traitEnable;
    bool FillEnable;
    int valueSlider;
    QColorDialog* ColorDialogue;
    QColor Color;
};

#endif

