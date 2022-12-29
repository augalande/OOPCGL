#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include<math.h>
#include<QTime>

using namespace std;

QImage img(500, 500, QImage::Format_RGB888);

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

void MainWindow::dda(int x1, int y1, int x2, int y2)
{
    float dx, dy, len, x, y;
    float i = 0;

    dx = x2- x1;
    dy = y2 - y1;

    if(abs(dx) >= abs(dy)){
        len = abs(dx);
    }
    else{
        len = abs(dy);
    }

    dx = dx/len;
    dy = dy/len;

    x = x1 + 0.5*sign(x2 - x1);
    y = y1 + 0.5*sign(y2 - y1);

    while(i <= len){
        img.setPixel(x, y, qRgb(255,0,0));
        x = x + dx;
        y = y + dy;
        i++;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

int MainWindow::sign(int x){
    if(x>0) return 1;
    else if(x<0) return -1;
    else return 0;
}

void MainWindow::delay(){
    QTime dieTime= QTime::currentTime().addMSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 50);
}

void MainWindow::hilbert(int a,int b,int c, int d, int e,int f,int& x,int& y){
    if(f<=0){
        return;
    }
    f--;
    hilbert(b,a,d,c,e,f,x,y);
    shift(a,e,x,y);
    hilbert(a,b,c,d,e,f,x,y);
    shift(b,e,x,y);
    hilbert(a,b,c,d,e,f,x,y);
    shift(c,e,x,y);
    hilbert(d,c,b,a,e,f,x,y);
}

void MainWindow::shift(int j,int h,int& x,int& y){
    int x1=x,y1=y;
    switch(j){
        case 1:
            y-=h; //up
            break;
        case 2:
            x+=h;  //right
            break;
        case 3 :
            y+=h;//down
            break;
        case 4:
            x-=h;  //left
            break;
    }
    dda(x1,y1,x,y);
    delay();
}

void MainWindow::on_pushButton_3_clicked()
{
    int x=100;int y=400;
    hilbert(1,2,3,4,5,6,x,y);
}
