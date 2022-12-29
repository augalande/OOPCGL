#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"
#include <math.h>
using namespace std;
static QImage img(400,400,QImage::Format_RGB888);

void axes()
{
    for(int i{};i<400;i++)
    {
        img.setPixel(i,200,qRgb(255,255,255));
        img.setPixel(200,i,qRgb(255,255,255));
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    start = true;
    ver = 0;
    axes();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void clear()
{
    img.fill(qRgb(0,0,0));
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    if(start)
    {
        int p = ev->pos().x();
        int q = ev->pos().y();
        a[ver] = p;
        b[ver] = q;

        if(ev->button() == Qt::RightButton)
        {
            dda(a[0],b[0],a[ver-1],b[ver-1]);
            start = false;
        }
        else
        {
            if(ver > 0)
            {
                dda(a[ver],b[ver],a[ver-1],b[ver-1]);
            }
        }
        ver++;
    }
}

void MainWindow::dda(int x1,int y1,int x2,int y2)
{

    float x,y,dx,dy,l,i=1;
    QRgb value;
    value=qRgb(0,255,0);

    l=std::abs(x2-x1)>std::abs(y2-y1)?std::abs(x2-x1):std::abs(y2-y1);
    dx=(x2-x1)/l;
    dy=(y2-y1)/l;

    x=x1+0.5f;
    y=y1+0.5f;
    do
    {
       img.setPixel(static_cast<int>(x),static_cast<int>(y),value);
       x = x + dx;
       y = y + dy;
       i++;
      }while(i <= l);


    ui->label->setPixmap(QPixmap::fromImage(img));

}

void MainWindow::on_clear_clicked()
{
    clear();
    axes();
    start = true;
    ver = 0;
    ui->label->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::on_translate_clicked()
{
    int t1[ver],t2[ver];

    if(start == true)
        return;

    int tx = ui->lineEdit->text().toInt();
    int ty = ui->lineEdit_2->text().toInt();

    for(int i{};i<ver;i++)
    {
        int x = a[i] - 200;
        int y = 200 - b[i];

        t1[i] = x + tx;
        t2[i] = y + ty;

    }
    for(int i{};i<ver-1;i++)
    {
        dda(t1[i]+200,200-t2[i],t1[i+1]+200,200-t2[i+1]);
    }
    dda(t1[0]+200,200-t2[0],t1[ver-1]+200,200-t2[ver-1]);
}


void MainWindow::on_scale_clicked()
{
    int t1[ver],t2[ver];

    if(start == true)
        return;

    float theta = ui->doubleSpinBox->text().toFloat();

    for(int i{};i<ver;i++)
    {
        int x = a[i] - 200;
        int y = 200 - b[i];

        t1[i] = x * theta;
        t2[i] = y * theta;
    }
    for(int i{};i<ver-1;i++)
    {
        dda(t1[i]+200,200-t2[i],t1[i+1]+200,200-t2[i+1]);
    }
    dda(t1[0]+200,200-t2[0],t1[ver-1]+200,200-t2[ver-1]);
}


void MainWindow::on_rotate_clicked()
{
    clear();
    axes();
    int t1[ver],t2[ver];
    if(start == true)
        return;

    float theta = ui->lineEdit_3->text().toFloat();
    theta = theta*(3.14/180);

    for(int i{};i<ver;i++)
    {
        int x = a[i] - 200;
        int y = 200 - b[i];

        t1[i] = x*cos(theta) - y*sin(theta);
        t2[i] = x*sin(theta) + y*cos(theta);
    }
    for(int i{};i<ver-1;i++)
    {
        dda(t1[i]+200,200-t2[i],t1[i+1]+200,200-t2[i+1]);
    }
    dda(t1[0]+200,200-t2[0],t1[ver-1]+200,200-t2[ver-1]);
}

