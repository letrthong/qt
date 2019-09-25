
  #ifndef ITEM_CHECK_BOX_TEXT_H
  #define ITEM_CHECK_BOX_TEXT_H

  #include <QObject>

  class ItemCheckBoxText : public QObject
  {
      Q_OBJECT

      Q_PROPERTY(QString getText READ getText WRITE setDescription NOTIFY descriptionChanged)
      Q_PROPERTY(bool getCheckBox READ getCheckBox WRITE setCheckBox NOTIFY checkBoxChanged)
      Q_PROPERTY(int getIndex READ getIndex WRITE setIndex NOTIFY indexChanged)

  public:
      ItemCheckBoxText(QObject *parent=0);
      ItemCheckBoxText(const bool &done, const QString &description, QObject *parent=0);

      QString getText() const;
      void setDescription(const QString &text);

      bool getCheckBox() const;
      void setCheckBox(const bool &state);

      int getIndex() const;
      void setIndex(int &index);

  signals:
      void descriptionChanged();
      void checkBoxChanged();
      void indexChanged();
      void sendListViewSignal(int index, bool state);

  private:
      QString m_description;
      bool m_done;
      int  m_index;
  };

  #endif // ITEM_CHECK_BOX_TEXT_H

  //https://stuff.mit.edu/afs/athena/software/texmaker_v5.0.2/qt57/doc/qtquick/qtquick-models-objectlistmodel-example.html
