import QtQuick 2.3

Item {
    id: root
    width: 100
    height: 200
	
 
    Rectangle {
        width: 100
        height: 50
		border.color: "darkgray"

		Rectangle {
			x: 0
			y: 0
			color: "blue"
			width: 100
			height: 50
			border.color: "slategrey"
        }

		 Text {
			x: 20
			y: 80
			text: 'My Button'
			color: "red"
    	}

    }

    
}