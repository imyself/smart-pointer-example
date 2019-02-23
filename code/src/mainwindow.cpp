#include "mainwindow.h"
#include <ui_mainwindow.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mygl->setFocus();

    connect(ui->translateXSpinBox, SIGNAL(valueChanged(int)), ui->mygl, SLOT(slot_setTranslateX(int)));
    connect(ui->translateYSpinBox, SIGNAL(valueChanged(int)), ui->mygl, SLOT(slot_setTranslateY(int)));
    connect(ui->rotateSpinBox, SIGNAL(valueChanged(int)), ui->mygl, SLOT(slot_setRotate(int)));
    connect(ui->scaleXSpinBox, SIGNAL(valueChanged(int)), ui->mygl, SLOT(slot_setScaleX(int)));
    connect(ui->scaleYSpinBox, SIGNAL(valueChanged(int)), ui->mygl, SLOT(slot_setScaleY(int)));

    connect(ui->scene1RadioButton, SIGNAL(clicked(bool)), ui->mygl, SLOT(slot_setScene1()));
    connect(ui->scene2RadioButton, SIGNAL(clicked(bool)), ui->mygl, SLOT(slot_setScene2()));
    connect(ui->scene3RadioButton, SIGNAL(clicked(bool)), ui->mygl, SLOT(slot_setScene3()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::exit();
}
