#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QListWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:



    void on_handleButton0();
    void on_handleButton1();


private:
    QWidget* createQListItem(int id);

    Ui::MainWindow *ui;

    void initList();
    void initWidget();
};

#endif // MAINWINDOW_H
