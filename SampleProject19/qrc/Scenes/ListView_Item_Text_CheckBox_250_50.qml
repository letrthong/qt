import QtQuick 2.0
import QtQuick.Controls  1.2
import io.qt.examples.backend 1.0

MouseArea  {
    id: name
    width: 250
    height: 50
    property string itemText: ""
    property bool itemCheckBox: false

    ListViewBackEnd {
        id: backend
        getIndex: index;
    }


    Rectangle {
        id: rectangle
        width: 250
        height: 50
        color: "#eef0e6"



        Background_250_50 {
            id: background_250_50

            Text {
                x: 56
                y: 8
                width: 186
                height: 34
                text: itemText
                font.bold: true
                font.pointSize: 19
                // onEditingFinished: itemText = text
            }

            CheckBox {
                x: 25
                y: 10
                width: 40
                height: 32
                transformOrigin: Item.Center
                checked: itemCheckBox
                onClicked: {
                    itemCheckBox = checked
                    backend.getCheckBox = checked
                     console.log("backend.done index=" + index + " "  + checked)
                }
            }
        }
    }


    onClicked: {
        console.log("ListView_Item_Button_250_50 index=" + index)

    }
}


