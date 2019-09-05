#ifndef QML_BACK_BUTTON_H_
#define QML_BACK_BUTTON_H_

#include <QObject>
#include <QString>

class QmlBackButton : public QObject
{
    Q_OBJECT
   // Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)

public:
    explicit QmlBackButton(QObject *parent = nullptr);

    QString userName();
    void setUserName(const QString &userName);
     
signals:
    void userNameChanged();

private:
    QString m_userName;
};

#endif // QML_BACK_BUTTON_H_
