#include "mMainWindow.h"
#include "Canvas.h"
#include "WindowSize.h"

mMainWindow::mMainWindow()
{
    resize(500, 500);
    //Initialisation variables
    drawEnable = 0;
    rectangleEnable = 0;
    cercleEnable = 0;
    traitEnable = 0;
    valueSlider = 1;


    Canvas* canvas = new Canvas(this);
    WindowSize* window = new WindowSize(canvas);
    setCentralWidget(canvas);

    //File menu
    QMenu* menuFichier = menuBar()->addMenu("File");

    QAction* actionNouveau = new QAction("New", this);
    menuFichier->addAction(actionNouveau);
    QAction* actionSauvegarder = new QAction("Save", this);
    menuFichier->addAction(actionSauvegarder);
    QAction* actionOuvrir = new QAction("Open", this);
    menuFichier->addAction(actionOuvrir);

    connect(actionNouveau, SIGNAL(triggered(bool)), window, SLOT(createClick()));
    connect(actionSauvegarder, SIGNAL(triggered(bool)), canvas, SLOT(saveCanvas()));
    connect(actionOuvrir, SIGNAL(triggered(bool)), canvas, SLOT(openCanvas()));

    //Menu forme
    QMenu* menuForme = menuBar()->addMenu("&Form");

    QAction* actionDraw = new QAction("Draw", this);
    menuForme->addAction(actionDraw);
    QAction* actionRectangle = new QAction("Rectangle", this);
    menuForme->addAction(actionRectangle);
    QAction* actionCercle = new QAction("Circle", this);
    menuForme->addAction(actionCercle);
    QAction* actionTrait = new QAction("Line", this);
    menuForme->addAction(actionTrait);


    connect(actionDraw, SIGNAL(triggered(bool)), this, SLOT(slotDraw()));
    connect(actionRectangle, SIGNAL(triggered(bool)), this, SLOT(slotRectangle()));
    connect(actionCercle, SIGNAL(triggered(bool)), this, SLOT(slotCercle()));
    connect(actionTrait, SIGNAL(triggered(bool)), this, SLOT(slotTrait()));

    //Menu outils
    QMenu* menuOutils = menuBar()->addMenu("Tools");

    QAction* actionFill = new QAction("Fill", this);
    menuOutils->addAction(actionFill);
    QAction* actionRetour = new QAction("Go back", this);
    actionRetour->setShortcut(QKeySequence("Ctrl+Z"));
    menuOutils->addAction(actionRetour);

    connect(actionFill, SIGNAL(triggered(bool)), this, SLOT(slotFill()));
    connect(actionRetour, SIGNAL(triggered(bool)), canvas, SLOT(retourCanevas()));
    //Barre d'outil
    QToolBar* toolBar = addToolBar("Color");

    QPushButton* boutonColor = new QPushButton;
    boutonColor->setText("Color");
    ColorDialogue = new QColorDialog;
    toolBar->addWidget(boutonColor);

    QSlider* slider = new QSlider(Qt::Horizontal);
    slider->setRange(1, 15);
    toolBar->addWidget(slider);

    connect(boutonColor, SIGNAL(clicked(bool)), this, SLOT(slotColor()));
    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(slotSlider(int)));
}
//FONCTIONS

bool mMainWindow::getDrawEnable()
{
    return drawEnable;
}
bool mMainWindow::getRectangleEnable()
{
    return rectangleEnable;
}
bool mMainWindow::getCercleEnable()
{
    return cercleEnable;
}
bool mMainWindow::getTraitEnable()
{
    return traitEnable;
}

bool mMainWindow::getFillEnable()
{
    return FillEnable;
}

QColor mMainWindow::getColor()
{
    return Color;
}
int mMainWindow::getValueSlider()
{
    return valueSlider;
}

//SLOTS
void mMainWindow::slotDraw()
{
    drawEnable = 1;
    rectangleEnable = 0;
    cercleEnable = 0;
    FillEnable = 0;
    traitEnable = 0;
}
void mMainWindow::slotRectangle()
{
    drawEnable = 0;
    rectangleEnable = 1;
    cercleEnable = 0;
    FillEnable = 0;
    traitEnable = 0;
}
void mMainWindow::slotCercle()
{
    drawEnable = 0;
    rectangleEnable = 0;
    cercleEnable = 1;
    FillEnable = 0;
    traitEnable = 0;
}
void mMainWindow::slotFill()
{
    drawEnable = 0;
    rectangleEnable = 0;
    cercleEnable = 0;
    FillEnable = 1;
    traitEnable = 0;
}

void mMainWindow::slotTrait()
{
    drawEnable = 0;
    rectangleEnable = 0;
    cercleEnable = 0;
    FillEnable = 0;
    traitEnable = 1;
}

void mMainWindow::slotColor()
{
    Color = ColorDialogue->getColor();
}

void mMainWindow::slotSlider(int x)
{
    valueSlider = x;
}