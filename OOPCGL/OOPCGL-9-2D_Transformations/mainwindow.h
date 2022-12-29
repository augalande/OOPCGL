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

    void dda(int x1, int y1, int x2, int y2);
    void mousePressEvent(QMouseEvent *ev);
private slots:
    void on_clear_clicked();

    void on_translate_clicked();

    void on_scale_clicked();

    void on_rotate_clicked();

private:
    Ui::MainWindow *ui;
    bool start;
    int ver,a[10],b[10];
};
#endif // MAINWINDOW_H
