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
        id: id_rectangle
        x: 5
        y: 5
        width: 150
        height: 70
        color: "lightsteelblue"

        Button {
            x: 5
            y: 5
            width: 140
            height: 60
            Image {
                id: id_image
                x: 0
                y: 0
                width: 140
                height: 60
                source: "../../qrc/images/backButton.png"
            }

            onClicked: {
                 id_root.qmlSignal("Click on Back Button")
                 id_rectangle.color= "lightsteelblue"

            }

            onPressedChanged: {
                   if (pressed){
                       id_rectangle.color= "red"
                       id_image.source =  "../../qrc/images/backButton_pressed.png"
                   }
                   else{
                       id_rectangle.color= "lightsteelblue"
                       id_image.source =  "../../qrc/images/backButton.png"
                   }
            }

         }
    }
}


