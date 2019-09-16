import QtQuick 2.0
import QtQuick.Controls  1.2


ListView {
    id: listView1
    x: 8
    y: 8
    width: 151
    height: 165
    boundsBehavior: Flickable.StopAtBounds
    contentWidth: 1
    flickableDirection: Flickable.HorizontalFlick
    highlightRangeMode: ListView.StrictlyEnforceRange
    delegate: Item {
        x: 5
        width: 80
        height: 40
        Row {
            id: row1
            Rectangle {
                width: 40
                height: 40
                color: model.colorCode
            }

            Text {
                text: model.name
                font.bold: true
                anchors.verticalCenter: parent.verticalCenter
            }
            spacing: 10
        }
    }
    model: ListModel {
        ListElement {
            name: "Grey"
            colorCode: "grey"
        }

        ListElement {
            name: "Red"
            colorCode: "red"
        }

        ListElement {
            name: "Blue"
            colorCode: "blue"
        }

        ListElement {
            name: "Green"
            colorCode: "green"
        }
    }
}




