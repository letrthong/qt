#include <QtGui>
#include <QPushButton>
#include <QStateMachine>
#include <QApplication>
int main(int argc, char **argv)
{
      QApplication  app(argc, argv);

    QPushButton button;
    QStateMachine machine;

    QState *off = new QState();
    off->assignProperty(&button, "text", "Off");
    off->setObjectName("off");

    QState *on = new QState();
    on->setObjectName("on");
    on->assignProperty(&button, "text", "On");

    off->addTransition(&button, SIGNAL(clicked()), on);
    on->addTransition(&button, SIGNAL(clicked()), off);

    machine.addState(off);
    machine.addState(on);

    machine.setInitialState(off);
    machine.start();

#if defined(Q_OS_SYMBIAN)
    button.showMaximized();
#elif defined(Q_WS_MAEMO_5) || defined(Q_WS_SIMULATOR)
    button.show();
#else
    button.resize(100, 50);
    button.show();
#endif
    return app.exec();
}