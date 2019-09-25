import QtQuick 2.0

Item {
    id: root
    
// public
    property string text:    'text'
    property bool   checked: false
    
    signal clicked(bool checked);   //onClicked:{root.checked = checked;  print('onClicked', checked)}

// private
    property real padding: 0.1    // around rectangle: percent of root.height
    property bool radio:   false  // false: check box, true: radio button
    
    width: 250;  height: 50                          // default size
    opacity: enabled  &&  !mouseArea.pressed? 1: 0.3 // disabled/pressed state
      
    Rectangle { // check box (or circle for radio button)
        id: rectangle
        
        height: root.height * (1 - 2 * padding);  width: height // square
        x: padding * root.height
        anchors.verticalCenter: parent.verticalCenter
        border.width: 0.05 * root.height
        radius: (radio? 0.5: 0.2) * height
        
        Text { // check
            visible: checked  &&  !radio
            anchors.centerIn: parent
            text: '\u2713' // CHECK MARK
            font.pixelSize: parent.height
        }
        
        Rectangle { // radio dot
            visible: checked  &&  radio
            color: 'black'
            width: 0.5 * parent.width;  height: width // square
            anchors.centerIn: parent
            radius: 0.5 * width // circle
        }
    }

    Text {
        id: text
        
        text: root.text
        anchors {left: rectangle.right;  verticalCenter: rectangle.verticalCenter;  margins: padding * root.height}
        font.pixelSize: 0.5 * root.height
    }
    
    MouseArea {
        id: mouseArea

        anchors.fill: parent

        onClicked: root.clicked(!checked) // emit
    }
}
