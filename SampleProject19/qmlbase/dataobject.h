
  /****************************************************************************
  **
  ** Copyright (C) 2015 The Qt Company Ltd.
  ** Contact: http://www.qt.io/licensing/
  **
  ** This file is part of the examples of the Qt Toolkit.
  **
  ** $QT_BEGIN_LICENSE:BSD$
  ** You may use this file under the terms of the BSD license as follows:
  **
  ** "Redistribution and use in source and binary forms, with or without
  ** modification, are permitted provided that the following conditions are
  ** met:
  **   * Redistributions of source code must retain the above copyright
  **     notice, this list of conditions and the following disclaimer.
  **   * Redistributions in binary form must reproduce the above copyright
  **     notice, this list of conditions and the following disclaimer in
  **     the documentation and/or other materials provided with the
  **     distribution.
  **   * Neither the name of The Qt Company Ltd nor the names of its
  **     contributors may be used to endorse or promote products derived
  **     from this software without specific prior written permission.
  **
  **
  ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
  ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
  ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
  ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
  ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
  ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
  ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
  ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
  **
  ** $QT_END_LICENSE$
  **
  ****************************************************************************/

  #ifndef DATAOBJECT_H
  #define DATAOBJECT_H

  #include <QObject>

  class DataObject : public QObject
  {
      Q_OBJECT

      Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)
      Q_PROPERTY(bool done READ done WRITE setDone NOTIFY doneChanged)

  public:
      DataObject(QObject *parent=0);
      DataObject(const bool &done, const QString &description, QObject *parent=0);

      QString description() const;
      void setDescription(const QString &text);

      bool done() const;
      void setDone(const bool &color);

  signals:
      void descriptionChanged();
      void  doneChanged();

  private:
      QString m_description;
      bool m_done;
  };

  #endif // DATAOBJECT_H

  //https://stuff.mit.edu/afs/athena/software/texmaker_v5.0.2/qt57/doc/qtquick/qtquick-models-objectlistmodel-example.html
