#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonDrawRectangle_clicked()
{
    ui->openGLWidget->drawShape(GLWidget::Shape::RECTANGLE);
}


void MainWindow::on_pushButtonClearScreen_clicked()
{
    ui->openGLWidget->drawShape(GLWidget::Shape::NONE);
}


void MainWindow::on_checkBoxWireFrame_stateChanged(int state)
{
    if (state == Qt::Checked)
    {
        ui->openGLWidget->setWireFrame(true);
    }
    else if (state == Qt::Unchecked)
    {
        ui->openGLWidget->setWireFrame(false);
    }
}

