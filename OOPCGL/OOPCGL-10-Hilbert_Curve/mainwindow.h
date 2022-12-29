#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void dda(int, int, int, int);
    int sign(int);
    void delay();

    void on_pushButton_3_clicked();
    void hilbert(int, int, int, int, int, int, int&, int&);
    void shift(int, int, int&, int&);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
