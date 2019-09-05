import QtQuick 2.0
import QtQuick.Controls  1.2
import io.qt.examples.backend 1.0

Item {
    id: backgroud
    x: 0
    y: 0
    width: 160
    height: 80
    property BackEnd backEnd: null


    Rectangle {
        id: rectangle
        x: 5
        y: 5
        width: 150
        height: 70
        color: "#c4cfc2"

        Button {
            x: 5
            y: 5
            width: 140
            height: 60
            Image {
                id: image
                x: 0
                y: 0
                width: 140
                height: 60
                source: "../../qrc/images/backButton.png"
            }

            onClicked: {
                 id_root.qmlSignal("Click on Back Button")
            }
         }
    }
}


