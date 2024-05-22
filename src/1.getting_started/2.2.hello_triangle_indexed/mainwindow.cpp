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


void MainWindow::on_comboBoxPolygonMode_currentIndexChanged(int index)
{
    switch (index)
    {
    case 1:
        ui->openGLWidget->setPolygonMode(GLWidget::PolygonMode::POINT);
        break;
    case 2:
        ui->openGLWidget->setPolygonMode(GLWidget::PolygonMode::LINE);
        break;
    case 3:
        ui->openGLWidget->setPolygonMode(GLWidget::PolygonMode::FILL);
        break;
    default:
        break;
    }
}

