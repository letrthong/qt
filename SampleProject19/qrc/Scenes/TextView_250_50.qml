import QtQuick 2.0

Item {
    id: name
     width: 250
     height: 50
     property string textViewText: "text"
     property string textVievName: "TextView"
     Text {
         id: element
         x: 17
         y: 8
         width: 225
         height: 34
         text: qsTr(textViewText)
         font.pixelSize: 25
     }


}
