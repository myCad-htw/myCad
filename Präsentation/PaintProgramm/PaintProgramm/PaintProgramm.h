#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_PaintProgramm.h"

class PaintProgramm : public QMainWindow
{
    Q_OBJECT

public:
    PaintProgramm(QWidget *parent = Q_NULLPTR);

private:
    Ui::PaintProgrammClass ui;
};
