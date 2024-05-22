#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonDrawRectangle_clicked();
    void on_pushButtonClearScreen_clicked();
    void on_checkBoxWireFrame_stateChanged(int state);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
