import QtQuick 2.0
import QtQuick.Controls  1.2


Item {
    id: id_back_button
    x: 0
    y: 0
    width: 160
    height: 80

    property string buttonName: "back"
    function getButtonName(name){
           return  "backbutton/" + buttonName;
    }

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
                 qmlSignalButton(getButtonName())
                 id_rectangle.color= "lightsteelblue"
            }

            onPressedChanged: {
                if (pressed){
                    id_rectangle.color= "red"
                    id_image.source =  "../../qrc/images/backButton_pressed.png"
                }else{
                    id_rectangle.color= "lightsteelblue"
                    id_image.source =  "../../qrc/images/backButton.png"
                }
            }
         }
    }
}


