
  #ifndef ITEM_CHECK_BOX_TEXT_H
  #define ITEM_CHECK_BOX_TEXT_H

  #include <QObject>

  class ItemCheckBoxText : public QObject
  {
        Q_OBJECT

        Q_PROPERTY(QString getText READ getText WRITE setDescription NOTIFY descriptionChanged)
        Q_PROPERTY(QString getValue READ getValue WRITE setValue NOTIFY valueChanged)
        Q_PROPERTY(QString getType READ getType WRITE setValue NOTIFY typeChanged)
        Q_PROPERTY(QString getIcon READ getIcon WRITE setType NOTIFY iconChanged)

        Q_PROPERTY(int getIndex READ getIndex WRITE setIndex NOTIFY indexChanged)

  public:
        ItemCheckBoxText(QObject *parent=0);
        ItemCheckBoxText(const QString &value, const QString &text, const QString &type,  const QString &icon = 0, QObject *parent=0);

        QString getText() const;
        void setDescription(const QString &text);

        QString getValue() const;
        void setValue(const QString &value);

        QString getType() const;
        void setType(const QString &type);

        QString getIcon() const;
        void setIcon(const QString &path);

        int getIndex() const;
        void setIndex(int &index);

  signals:
      void descriptionChanged();
      void valueChanged();
      void typeChanged();
       void iconChanged();

      void indexChanged();
      void sendListViewSignal(int index,const  QString state);

  private:
      QString m_text;
      QString m_icon;

      QString m_value;
      QString m_type;

      int  m_index;
  };

  #endif // ITEM_CHECK_BOX_TEXT_H

  //https://stuff.mit.edu/afs/athena/software/texmaker_v5.0.2/qt57/doc/qtquick/qtquick-models-objectlistmodel-example.html


/*
    property string itemType: "bool"
    property string itemText: "N/A"
    property string itemRange: "[0:1]"
    property string itemFormula: "1x"
    property string itemValue: "true"
  */
