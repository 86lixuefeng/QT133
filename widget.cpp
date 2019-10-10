#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setGeometry(0,0,1280,800);
    this->setAttribute(Qt::WA_StyledBackground);
    this->setObjectName("main");
    this->setStyleSheet("Widget#main{border-image:url(:/image/image/bg_main.jpg);}");
    ui->logo->setStyleSheet("border-image:url(:/image/image/xiao_logo.png);");
//超载
    QPixmap pixmap_overload(":/image/image/icon_overload.png");
    pixmap_overload.scaled(ui->overload->width(),ui->overload->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);//按比例填充
    //pixmap.scaled(with, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
    ui->overload->setFixedSize(90,50);
    ui->overload->setPixmap(pixmap_overload);
//禁止吸烟
    QPixmap pixmap_smoke(":/image/image/ic_no_smoking.png");
    pixmap_overload.scaled(ui->smoke->width(),ui->smoke->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);//按比例填充
    ui->smoke->setScaledContents(true);
    ui->smoke->setFixedSize(50,50);
    ui->smoke->setPixmap(pixmap_smoke);
//消防
    QPixmap pixmap_fire(":/image/image/icon_fire.png");
    pixmap_overload.scaled(ui->fire->width(),ui->fire->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);//按比例填充
    ui->fire->setFixedSize(50,50);
    ui->fire->setPixmap(pixmap_fire);

//日期时间
    ft.setFamily(":/font/FreeSans.ttf");
    ft.setPointSize(20);
    ui->date->setFont(ft);
//    ui->date->setFont(QFont("Roman times",20));
    ui->date->setStyleSheet("color:#592d31;");
    timer_date = new QTimer(this);
    timer_date->start(100);
    connect(timer_date,&QTimer::timeout,ui->date,[=](){
        timer_date->stop();
        QDateTime time = QDateTime::currentDateTime();
        QString str = time.toString("yyyy/MM/dd  hh:mm:ss dddd  ");
        ui->date->setText(str);
        timer_date->start(1000);
    });
//天气
    QPixmap pixmap_weather(":/weather/image/rain.png");
    pixmap_weather.scaled(ui->weather->width()/3,ui->weather->height()/3, Qt::KeepAspectRatio, Qt::SmoothTransformation);//按比例填充
    ui->weather->setScaledContents(true);
    ui->weather->setPixmap(pixmap_weather);
    ui->weather->setFixedSize(40,30);

    ui->temp->setFont(ft);
    ui->temp->setText(QString("20℃"));
//楼层
    QPixmap pixmap_shi(":/floor/0");
    pixmap_shi.scaled(ui->shi->width(),ui->shi->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);//按比例填充
    ui->shi->setFixedSize(75,120);
    ui->shi->setScaledContents(true);
    ui->shi->setPixmap(pixmap_shi);
    QPixmap pixmap_ge(":/floor/0");
    pixmap_ge.scaled(ui->ge->width(),ui->ge->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);//按比例填充
    ui->ge->setFixedSize(75,120);
    ui->ge->setScaledContents(true);
    ui->ge->setPixmap(pixmap_ge);
//箭头
    QPixmap pixmap_arrow(":/arrow/image/upa.png");
    pixmap_shi.scaled(ui->arrow->width(),ui->arrow->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);//按比例填充
    ui->arrow->setFixedSize(120,120);
    ui->arrow->setScaledContents(true);
    ui->arrow->setPixmap(pixmap_arrow);
}

Widget::~Widget()
{
    delete timer_date;
    delete ui;
}
