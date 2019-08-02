#ifndef MAINWINDOW_H
 #define MAINWINDOW_H
 
 #include <QMainWindow>
 #include <QPushButton>
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
    std::string getDate();
 };
 
 #endif // MAINWINDOW_H