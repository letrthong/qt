#include "mainwindow.h"
 #include <ctime>

 #include <QCoreApplication>
 
 MainWindow::MainWindow(QWidget *parent)
   : QMainWindow(parent)
 { 
    Qt::WindowFlags flags = windowFlags();
 /*  flags |= Qt::CustomizeWindowHint;
  flags &= ~Qt::WindowContextHelpButtonHint;
  flags &= ~Qt::WindowSystemMenuHint;
  flags &= ~Qt::WindowMinMaxButtonsHint;
  flags &= ~Qt::WindowCloseButtonHint;*/

  flags = Qt::Window | Qt::FramelessWindowHint;
    setWindowFlags(flags);
    // Create the button, make "this" the parent
    m_button = new QPushButton("show date", this);
    // set size and location of the button
    m_button->setGeometry(QRect(QPoint(100, 100), QSize(200, 50)));
 
    // Connect button signal to appropriate slot
    connect(m_button, SIGNAL (released()), this, SLOT (handleButton()));

    m_label =  new QLabel("00:00:00", this);
    m_label->setGeometry(QRect(QPoint(500, 100),   QSize(500, 50)));

    m_QLineEdit =  new QLineEdit(this);
    m_QLineEdit->setPlaceholderText("Placeholder Text");
    m_QLineEdit->setGeometry(QRect(QPoint(100, 200),   QSize(500, 50)));
    m_label_Image =  new QLabel( this);
    m_label_Image->setGeometry(QRect(QPoint(100, 250),   QSize(400,400)));
 }
 
 void MainWindow::handleButton()
 {
    std::string text = m_QLineEdit->text().toStdString() +  " "  +  getDate();
     m_label->setText( text.c_str());

      m_QLineEdit->clear();
      static bool flag = false;
      if(true == flag)
      {
        QPixmap pm("resource/test01.jpg");
        int w = m_label_Image->width();
        int h = m_label_Image->height();
        m_label_Image->setPixmap(pm.scaled(w,h,Qt::KeepAspectRatio));
        flag = false;
      }
      else
      {
        QPixmap pm("resource/test02.jpg");
        int w = m_label_Image->width();
        int h = m_label_Image->height();
        m_label_Image->setPixmap(pm.scaled(w,h,Qt::KeepAspectRatio));
        flag = true;
      }
 }


 std::string MainWindow::getDate()
 {
   time_t now = time(0);
   tm *ltm = localtime(&now);
   char  buffer[11] ={0};

   sprintf( buffer, "%d:%d:%d",  1 + ltm->tm_hour, 1 + ltm->tm_min  ,1 + ltm->tm_sec );
    
   return  std::string(buffer);
 }