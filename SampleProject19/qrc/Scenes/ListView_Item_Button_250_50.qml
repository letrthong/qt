import QtQuick 2.0

MouseArea  {
    id: name
    width: 250
    height: 50
    property string itemText: "n.a"
    Text {
        id: element
        x: 34
        y: 8
        width: 220
        height: 34
        text: qsTr(itemText)
        font.bold: true
        font.italic: true
        font.pixelSize: 27
    }

    Rectangle {
        id: line
        x: 17
        y: 41
        width: 230
        height: 5
        color: "#828798"
    }
    onClicked: {
             console.log("ListView_Item_Button_250_50 index=" + index)
    }
}
