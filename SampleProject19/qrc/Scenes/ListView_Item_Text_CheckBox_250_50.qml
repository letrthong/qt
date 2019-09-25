import QtQuick 2.0
import QtQuick.Controls  1.2
MouseArea  {
    id: name
    width: 250
    height: 50
    property string itemText: ""
    property bool itemCheckBox: false

    CheckBox {
        x: 25
        y: 10
        width: 40
        height: 32
        transformOrigin: Item.Center
            checked: itemCheckBox
            onClicked: {
                itemCheckBox = checked
            }
    }
    TextField {
        x: 84
        y: 15
        width: 143
        height: 20
        text: itemText
        onEditingFinished: itemText = text
    }

    onClicked: {
             console.log("ListView_Item_Button_250_50 index=" + index)
    }
}

/*##^## Designer {
    D{i:1;anchors_height:32;anchors_width:40;anchors_x:25;anchors_y:10}
}
 ##^##*/
