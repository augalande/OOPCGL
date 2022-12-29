#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath> //Add this for sqrt()

QImage img(500,500,QImage::Format_RGB888); // Height=500, Width=500, Format= RGB888

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

void MainWindow::dda(int x1,int y1,int x2,int y2) //
{
    float x,y,xinc,yinc,dx,dy,step;

    x=x1;
    y=y1;

    dx=x2-x1;
    dy=y2-y1;

    if(abs(dx)>abs(dy))
    {
        step=abs(dx);
    }
    else
    {
        step=abs(dy);
    }

    xinc=dx/step;
    yinc=dy/step;

    img.setPixel(x,y,qRgb(255,255,255));

    for(int i=1;i<=step;i++)
    {
        x=x+xinc;
        y=y+yinc;

        img.setPixel(x,y,qRgb(255,255,255));
    }

}

void MainWindow::rectangle(int x1,int y1,int l,int b)  //
{
    int x2,y2;

    x2=x1+l;
    y2=y1+b;

    dda(x1,y1,x2,y1);
    dda(x2,y1,x2,y2);
    dda(x2,y2,x1,y2);
    dda(x1,y2,x1,y1);
}

void MainWindow::rhombus(int x1,int y1,int l,int b)  //
{
    int x2,y2;

    x2=x1+l;
    y2=y1+b;

    int m1,n1,m2,n2,m3,n3,m4,n4;

    m1=(x1+x2)/2;
    n1=(y1+y1)/2;

    m2=(x1+x2)/2;
    n2=(y2+y2)/2;

    m3=(x1+x1)/2;
    n3=(y1+y2)/2;

    m4=(x2+x2)/2;
    n4=(y1+y2)/2;

    dda(m1,n1,m4,n4);
    dda(m1,n1,m3,n3);
    dda(m2,n2,m3,n3);
    dda(m2,n2,m4,n4);
}

void MainWindow::draw_circle(int xc,int yc,int x,int y)  //
{
    img.setPixel(xc+x,yc+y,qRgb(255,255,255));
    img.setPixel(xc-x,yc+y,qRgb(255,255,255));
    img.setPixel(xc+x,yc-y,qRgb(255,255,255));
    img.setPixel(xc-x,yc+-y,qRgb(255,255,255));

    img.setPixel(xc+y,yc+x,qRgb(255,255,255));
    img.setPixel(xc+y,yc-x,qRgb(255,255,255));
    img.setPixel(xc-y,yc+x,qRgb(255,255,255));
    img.setPixel(xc-y,yc-x,qRgb(255,255,255));
}

void MainWindow::bresenham(int x1,int y1,int l,int b) //
{
    int xc,yc,r,d;

    xc=x1+(l/2);
    yc=y1+(b/2);

    r=((l*b)/(2*(sqrt(l*l+b*b))));

    d=3-(2*r);

    int x,y;

    x=0;
    y=r;

    while(x<=y)
    {
        if(d<0)
        {
            d+=(4*x)+6;
            x++;
        }

        else
        {
            d+=4*(x-y)+10;
            x++;
            y--;
        }
        draw_circle(xc,yc,x,y);
    }
}

void MainWindow::on_pushButton_clicked() //
{
    int x1,y1,l,b; // x1=100, y1=100, l=300, b=150
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    l=ui->textEdit_3->toPlainText().toInt();
    b=ui->textEdit_4->toPlainText().toInt();

    rectangle(x1,y1,l,b);
    rhombus(x1,y1,l,b);
    bresenham(x1,y1,l,b);

    ui->label->setPixmap(QPixmap::fromImage(img)); // Setting Pixmap for label from img
}


