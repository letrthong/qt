import QtQuick 2.0

Rectangle { // size controlled by height
    id: id_PushButton_250_50

// public
    property string textId: 'PushButton'

    property string pushButtonName: "PushButton"

    function getButtonName(name){
         return  "PushButton/" + pushButtonName;
    }

// private
    width: 250;  height: 50 // default size
    border.width: 0.05 * id_PushButton_250_50.height
    radius:       0.5  * id_PushButton_250_50.height
    opacity:      enabled? 1: 0.3 // disabled state

    Text {
        text: id_PushButton_250_50.textId
        font.pixelSize: 0.5 * id_PushButton_250_50.height
        anchors.centerIn: parent
    }

    MouseArea {
        anchors.fill: parent
        onPressed:  parent.opacity = 0.5 // down state
        onReleased: parent.opacity = 1
        onCanceled: parent.opacity = 1
        onClicked: {
               qmlSignalButton(0, getButtonName()) // emit
        }
    }
}
