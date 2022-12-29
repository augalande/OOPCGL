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

    //Add all function slots under public
    void dda(int,int,int,int); //
    void rectangle(int,int,int,int); //
    void rhombus(int,int,int,int); //
    void bresenham(int,int,int,int); //
    void draw_circle(int,int,int,int); //

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
