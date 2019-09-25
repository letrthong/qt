import QtQuick 2.0

ListView{
    id: root
    
// public
    model:          []//'zero', 'one', 'two'] // right to left (backwards)
    currentIndex:   0
    
//private
    width: 250;  height: 50 // default size

    orientation: ListView.Horizontal
    layoutDirection: Qt.RightToLeft
    interactive: false
    spacing: 0.1 * height
    clip: true // horizontal line
    header: Item{width: root.spacing} // small space at right

    delegate: Item{ // tab
        width: 2 * height;  height: 0.7 * root.height
        y: root.height - height            // align bottom
        opacity: mouseArea.pressed? 0.3: 1 // pressed state
    
        Item{ // don't clip horizontal line
            anchors.fill: parent
            clip: true
            
            Rectangle{ // background
                width: parent.width;  height: 2 * parent.height
                border.width: 0.02 * root.height
                radius: 0.2 * root.height
            }
        }

        Text{
            text: modelData
            font{pixelSize: 0.3 * root.height;  bold: currentIndex == index} // selected
            anchors.centerIn: parent
        }
        
        Rectangle{ // horizontal line at bottom
            visible: currentIndex != index
            anchors.bottom: parent.bottom
            width: parent.width;  height: 0.02 * root.height
            color: 'black'//red'
        }
        
        Rectangle{ // horizontal line at bottom left
            visible: currentIndex == index;  
            anchors{bottom: parent.bottom;  right: parent.left}
            width: root.width;    height: 0.02 * root.height
            color: 'black'//green'
        }
        
        Rectangle{ // horizontal line at bottom right
            visible: currentIndex == index;
            anchors{bottom: parent.bottom;  left:  parent.right}
            width: root.width;    height: 0.02 * root.height
            color: 'black'//blue'
        }
        
        MouseArea {
            id: mouseArea
            
            anchors.fill: parent
            enabled: currentIndex != index
            
            onClicked:  currentIndex = index
        }
    }
}
