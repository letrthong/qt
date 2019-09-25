import QtQuick 2.0

Item {
    id: root
    
// public
    property double minimum:  0
    property double value:    0
    property double maximum: 10
    
    signal clicked(double value);  //onClicked:{root.value = value;  print('onClicked', value)}
       
// private
    width: 250;  height: 50  // default size
    opacity: enabled  &&  !mouseArea.pressed? 1: 0.3 // disabled/pressed state
    
    Repeater { // left and right trays (so tray doesn't shine through pill in disabled state)
        model: 2
        
        Rectangle {
            x:     !index?               0: pill.x + pill.width - radius
            width: !index? pill.x + radius: root.width - x;  height: 0.1 * root.height
            radius: 0.5 * height
            color: 'black'
            anchors.verticalCenter: parent.verticalCenter
        }
    }
    
    Rectangle { // pill
        id: pill
        
        x: (value - minimum) / (maximum - minimum) * (root.width - pill.width) // pixels from value
        width: parent.height;  height: width
        border.width: 0.05 * root.height
        radius: 0.5 * height
    }
    
    MouseArea {
        id: mouseArea

        anchors.fill: parent
    
        drag {
            target:   pill
            axis:     Drag.XAxis
            minimumX: 0
            maximumX: root.width - pill.width
        }
        
        onPositionChanged:  if(drag.active) setPixels(pill.x + 0.5 * pill.width) // drag pill
        onClicked:                          setPixels(mouse.x) // tap tray
    } 
    
    function setPixels(pixels) {
        var value = (maximum - minimum) / (root.width - pill.width) * (pixels - pill.width / 2) + minimum // value from pixels
        clicked(Math.min(Math.max(minimum, value), maximum)) // emit
    }
}
