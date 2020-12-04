#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_myCad.h"

class myCad : public QMainWindow
{
    Q_OBJECT

public:
    myCad(QWidget *parent = Q_NULLPTR);

private:
    Ui::myCadClass ui;
};
