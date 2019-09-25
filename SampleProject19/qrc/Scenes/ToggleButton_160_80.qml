import QtQuick 2.0
import QtQuick.Controls  1.2

Item {
    id: id_toggle_button
    x: 0
    y: 0
    width: 160
    height: 80

    property string toggleButtonName: "ToggleButton"
    property bool isChecked: true
    property bool enabledButton: true

    function getButtonName(){
           return  "ToggleButton/" + toggleButtonName;
    }

    function getChecked(){
        if(isChecked == true){
            return  "ON"
        }
        else{
            return "OFF"
        }
    }

    function sendSingal(){
        if(enabledButton == true){
            qmlSignalButton(1, getButtonName())
        }else{
        }
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

            Text {
                id: id_text
                text: getChecked()
                font.family: "Helvetica"
                font.pointSize: 18
                color: "red"
            }

            onClicked: {
               sendSingal()
                id_rectangle.color= "lightsteelblue"
                if( isChecked == true){
                    isChecked = false
                } else{
                  isChecked = true
                }
            }

            onPressedChanged: {
                if (pressed){
                    id_rectangle.color= "red"
                }else{
                    id_rectangle.color= "lightsteelblue"
                }
            }
         }
    }
}


