	
import QtQuick 2.0

import "./composite" as MyComposite


Item {
    id: id_item
   width: 400; height: 200
  
   signal qmlSignal(string msg)

  MouseArea {
	  anchors.fill: parent
	  onClicked: id_item.qmlSignal("Hello from QML")
  }
  
    
	MyComposite.MyButton {
	   width: 100; height: 100
	   color: "blue"
	}


	MyComposite.MyButton {
		x: 100
		y: 10
		width: 100; height: 100
		color:  'red'
	}
	  
	MyComposite.MyItem{
		x: 200
		y: 10
	}
}
