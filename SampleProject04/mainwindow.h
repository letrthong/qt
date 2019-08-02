#ifndef MAINWINDOW_H
#define MAINWINDOW_H
 
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

#include <string>
 
 namespace Ui {
    class MainWindow;
 }
 
 class MainWindow : public QMainWindow
 {
    Q_OBJECT
 public:
    explicit MainWindow(QWidget *parent = 0);
 private slots:
    void handleButton();
 private:
    QPushButton *m_button;
    QLabel      *m_label;
    QLineEdit   *m_QLineEdit;
   
    std::string getDate();
 };
 
 #endif // MAINWINDOW_H