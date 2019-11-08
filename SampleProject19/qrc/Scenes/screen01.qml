import QtQuick 2.0
import QtQuick.Controls  1.2

Item {
    id: id_screen1

    width: 300
    height: 480
    visible: true

    property string screenName: "screen01"

    signal qmlSignalButton(int sendTo, string msg)


    function setTextField(text){
        console.log("screen1.qml::setTextField: " + text)
    }


    EditText_250_50{
        x: 25
        y: 402

    }

    ToggleButton_160_80 {
        id: pushButton
        x: 40
        y: 205
        toggleButtonName: "button01"
    }

    ToggleButton_160_80 {
        id: pushButton1
        x: 27
        y: 316
        width: 158
        height: 80
        toggleButtonName: "button02"
    }

    PushButton_250_50 {
        id: pushButton_250_50
        x: 27
        y: 44
        color: "#00ff00"
        pushButtonName: "button01"
    }

    PushButton_250_50 {
        id: pushButton_250_501
        x: 15
        y: 112
         pushButtonName: "button02"
    }

}
