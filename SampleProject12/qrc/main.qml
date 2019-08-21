
  import QtQuick 2.0

  Item {
	   id: id_item
      width: 100; height: 100
	  
	   signal qmlSignal(string msg)

      MouseArea {
          anchors.fill: parent
          onClicked: id_item.qmlSignal("Hello from QML")
      }
  }
