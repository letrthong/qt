import QtQuick 2.0

Rectangle { // size controlled by height
    id: root

// public
    property string text: 'text'
    signal clicked(); // onClicked: print('onClicked')

    property string buttonName: "pushButton"

    function getButtonName(name){
         return  "pushButton/" + buttonName;
    }

// private
    width: 250;  height: 50 // default size
    border.width: 0.05 * root.height
    radius:       0.5  * root.height
    opacity:      enabled? 1: 0.3 // disabled state

    Text {
        text: root.text
        font.pixelSize: 0.5 * root.height
        anchors.centerIn: parent
    }

    MouseArea {
        anchors.fill: parent
        onPressed:  parent.opacity = 0.5 // down state
        onReleased: parent.opacity = 1
        onCanceled: parent.opacity = 1
        onClicked:    qmlSignalButton(0, getButtonName()) // emit
    }
}
