#pragma once
#ifndef HEADER_FENTAILLE
#define HEADER_FENTAILLE
#include <QtWidgets>
#include "Canvas.h"
class WindowSize : public QWidget
{
    Q_OBJECT
public:
    WindowSize(Canvas* canvas);
    static int getlength();
    static int getHeight();


public slots:
    void createClick();
    void getlengthLine(QString lLine);
    void getheightLine(QString hLine);

private:
    static int length;
    static int height;
    QLineEdit* lengthLine;
    QLineEdit* heightLine;
    QPushButton* create;
};

#endif


