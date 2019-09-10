import QtQuick 2.0
import QtQuick.Controls  1.2
import io.qt.examples.backend 1.0

ApplicationWindow {
    id: id_screen1
    width: 300
    height: 480
    visible: true

    signal qmlSignalButton(int sendTo, string msg)


    function setTextField(text){
        console.log("screen1.qml::setTextField: " + text)
    }

    BackEnd {
        id: backend
    }

    TextField {
        text:  backend.getUserName
        anchors.verticalCenterOffset: 122
        anchors.horizontalCenterOffset: -49
        placeholderText: qsTr("User name")
        anchors.centerIn: parent

        onTextChanged: backend.getUserName = text
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

        text: "Button"

        onClicked: id_screen1.qmlSignalButton(1, "screen1/button01")
    }

    BackButton {
        id: backButton
        x: 15
        y: 387
    }

    PushButton {
        id: pushButton
        x: 50
        y: 181
        buttonName: "button01"
    }

    PushButton {
        id: pushButton1
        x: 27
        y: 260
        buttonName: "button02"
    }

    PushButton_250_50 {
        id: pushButton_250_50
        x: 27
        y: 79
        buttonName: "button01"
    }

    Component.onCompleted: {
            var JsonString = '{"a":"A whatever, run","b":"B fore something happens"}';
            var JsonObject= JSON.parse(JsonString);

            //retrieve values from JSON again
            var aString = JsonObject.a;
            var bString = JsonObject.b;

            console.log(aString);
            console.log(bString);
        }
}
