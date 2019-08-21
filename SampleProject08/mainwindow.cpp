#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHBoxLayout>
#include <QPushButton>
#include  <QCheckBox>
#include <QLabel>
#include "dialog.h"
#include<QDebug>
#include <QGroupBox>
#include  <QScrollArea>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


   initList();
   initWidget();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initList()
{
    for(int i= 0; i< 20; i++)
    {
        QListWidgetItem *item =new QListWidgetItem();
       // item->set
        item->setSizeHint(QSize(0, 40));


        QWidget *window =  createQListItem(i);

        ui->mylistWidget->addItem(item);
        ui->mylistWidget->setItemWidget(item, window);
    }
}


 void MainWindow::on_handleButton0()
 {
    qInfo( "on_handleButton0" );
    QVariant propertyV = sender()->property("id");
    if (propertyV.isValid()) {
       int property = propertyV.toInt();
         qInfo("id=%d" ,property);
     }
 }


  void MainWindow::on_handleButton1()
  {
      qInfo( "on_handleButton1" );
      QVariant propertyV = sender()->property("id");
      if (propertyV.isValid()) {
         int property = propertyV.toInt();
           qInfo("id=%d" ,property);
       }
  }

 QWidget* MainWindow::createQListItem(int id)
 {
     QWidget *pWidget = new QWidget;

     QHBoxLayout *pLayout  = new QHBoxLayout;
     QPushButton *pButton1 = new QPushButton("One");
     QPushButton *pButton2 = new QPushButton("Two");
     QCheckBox  *chekBox1 = new QCheckBox();
     QLabel      *label   = new QLabel(QString::number(id));


     pButton1->setProperty("id", id);
     connect(pButton1, SIGNAL (released()), this, SLOT (on_handleButton0()));

     pButton2->setProperty("id", id);
     connect(pButton2, SIGNAL (released()), this, SLOT (on_handleButton1()));

     pLayout->addWidget(pButton1);
     pLayout->addWidget(pButton2);
     pLayout->addWidget(chekBox1);
     pLayout->addWidget(label);
     pLayout->setSizeConstraint(QLayout::SetFixedSize);
     pWidget->setLayout(pLayout);
     pWidget->setBaseSize(QSize(0, 40));
     return  pWidget;
 }

  void MainWindow::initWidget()
  {
      QHBoxLayout *pLayout  = new QHBoxLayout;
      QPushButton *pButton1 = new QPushButton("1");
      pButton1->setStyleSheet("color: blue;"
                              "background-color: yellow;"
                              "border-width: 2px;"
                              "selection-background-color: blue;");

      QPushButton *pButton2 = new QPushButton("2");
      QPushButton *pButton3 = new QPushButton("3");
      QPushButton *pButton4 = new QPushButton("4");

      pButton1->setFixedSize(QSize(100, 100));

      pButton2->setFixedSize(QSize(100, 100));
      pButton3->setFixedSize(QSize(100, 100));
      pButton4->setFixedSize(QSize(100, 100));

      pLayout->addWidget(pButton1);
      pLayout->addWidget(pButton2);
      pLayout->addWidget(pButton3);
      pLayout->addWidget(pButton4);

      pLayout->setSizeConstraint(QLayout::SetFixedSize);


      QScrollArea *scrollarea = new QScrollArea(this);
      scrollarea->setGeometry(600,100,300,135);

      scrollarea->setBackgroundRole(QPalette::Shadow);


      ui->myWidget->setLayout(pLayout);
     scrollarea->setWidget( ui->myWidget);
     scrollarea->show();
}

