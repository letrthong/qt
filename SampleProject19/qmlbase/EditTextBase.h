/**************************************************
 *
 *  Copyright 2019 XXX Inc.  All rights reserved.
 *  AuThor: ThongLT
 *  Date:  23 Sep 2019
 *  FileName:  EditTextBase.h
 *
 *  EditTextBase.h  will be mapping with EditText_250_50.qml at qrc\Scenes
 *
 * *************************************************/

#ifndef EDIT_TEXT_BASE_H_
#define EDIT_TEXT_BASE_H_

#include <QObject>
#include <QString>

class EditTextBase : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString getEditText  READ getEditText  WRITE setEditText NOTIFY  TextEditChanged)

public:
    explicit EditTextBase(QObject *parent = nullptr);

    QString getEditText();
    void setEditText(const QString &text);
signals:
    /*
     * Send a signal to Qml file to sync databinding
     */
    void TextEditChanged();

private:
    QString m_userName;
};

#endif // EDIT_TEXT_BASE_H_
