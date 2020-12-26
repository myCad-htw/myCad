#include "WindowSize.h"


int WindowSize::length = 500;
int WindowSize::height = 500;

WindowSize::WindowSize(Canvas* canvas) : QWidget()
{

    QVBoxLayout* layout = new QVBoxLayout(this);
    lengthLine = new QLineEdit;
    heightLine = new QLineEdit;
    QFormLayout* donne = new QFormLayout;

    donne->addRow("Enter length (x)", lengthLine);
    donne->addRow("Enter height (y)", heightLine);


    create = new QPushButton("create");
    layout->addLayout(donne);
    layout->addWidget(create);
    connect(create, SIGNAL(clicked(bool)), canvas, SLOT(newCanvas()));
    connect(lengthLine, SIGNAL(textChanged(QString)), this, SLOT(getlengthLine(QString)));
    connect(heightLine, SIGNAL(textChanged(QString)), this, SLOT(getHeightLine(QString)));

    connect(create, SIGNAL(clicked(bool)), this, SLOT(close()));
}

void WindowSize::createClick()
{

    this->show();

}
//Functions slots
void WindowSize::getlengthLine(QString lLine)
{
    length = lLine.toInt();
}
void WindowSize::getheightLine(QString hLine)
{
    height = hLine.toInt();
}

//Functions
int WindowSize::getlength()
{
    return length;
}

int WindowSize::getHeight()
{
    return height;
}

