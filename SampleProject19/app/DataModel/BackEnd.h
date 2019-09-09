#ifndef BACKEND_H_
#define BACKEND_H_

#include <QObject>
#include <QString>

class BackEnd : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString getUserName  READ getUserName  WRITE setUserName NOTIFY userNameChanged)

public:
    explicit BackEnd(QObject *parent = nullptr);

    QString getUserName();
    void setUserName(const QString &userName);


signals:
    void userNameChanged();

private:
    QString m_userName;
};

#endif // BACKEND_H
