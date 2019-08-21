	
import QtQuick 2.0

  
Item {
   id: id_item
  width: 200; height: 200
  
   signal qmlSignal(string msg)

  MouseArea {
	  anchors.fill: parent
	  onClicked: id_item.qmlSignal("Hello from QML")
  }
  
    
	MyButton {
	   width: 100; height: 100
	   color: "blue"
	}


	MyButton {
		x: 100
		y: 10
		width: 100; height: 100
		color: "red"
	}
	  
	  
}
