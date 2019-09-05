import QtQuick 2.0
import QtQuick.Controls  1.2

Item {
    id: backgroud
    x: 0
    y: 0
    width: 491
    height: 248

    Button {
        id: button
        x: 17
        y: 8
        width: 280
        height: 177
        text: qsTr("Button")

        Image {
            id: image
            x: 45
            y: 50
            width: 207
            height: 89
            source: "../../qrc/images/backButton.png"
        }
    }
}


