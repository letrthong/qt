import QtQuick 2.0
import QtQuick.Controls  1.2

Item {
    id: id_push_button
    x: 0
    y: 0
    width: 160
    height: 80

    property string buttonName: "unknow"
    function getButtonName(){
           return  "pushButton/" + buttonName;
    }



    function setVisible( text){
         console.log("PushButton::setvisible " + text);
        if("pushButton/button02" == text)
        {
            console.log("PushButton::visible ");
           // pushButton1.visible = false;
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
                text: "ON"
                font.family: "Helvetica"
                font.pointSize: 18
                color: "red"
            }

            onClicked: {
                qmlSignalButton(1, getButtonName())
                id_rectangle.color= "lightsteelblue"
                if(id_text.text == "ON"){
                    id_text.text=   "OFF"
                }
                else{
                id_text.text =  "ON"
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


