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
        x: 15
        y: 346

    }

    Button {
        x: 15
        y: 7
        text: "Quit"
        onClicked: Qt.quit()
    }

    Button {
        x: 189
        y: 7

        text: "NextPage"
        // 1 -> send model
        onClicked: id_screen1.qmlSignalButton(1, "screen1/netpage")
    }

    BackButton_160_80 {
        id: backButton
        x: 15
        y: 387
    }

    ToggleButton_160_80 {
        id: pushButton
        x: 50
        y: 181
        toggleButtonName: "button01"
    }

    ToggleButton_160_80 {
        id: pushButton1
        x: 27
        y: 260
        toggleButtonName: "button02"
    }

    PushButton_250_50 {
        id: pushButton_250_50
        x: 27
        y: 44
        pushButtonName: "button01"
    }

    PushButton_250_50 {
        id: pushButton_250_501
        x: 15
        y: 112
         pushButtonName: "button02"
    }

}
