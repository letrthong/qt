import QtQuick 2.0
import QtQuick.Controls  1.2
import io.qt.examples.backend 1.0

ApplicationWindow {
    id: id_root
    width: 300
    height: 480
    visible: true

    signal qmlSignal(string msg)


    function setTextField(text){
        console.log("screen1.qml::setTextField: " + text)
    }

    BackEnd {
        id: backend
    }

    TextField {
        text:  backend.getUserName
        placeholderText: qsTr("User name")
        anchors.centerIn: parent

        onTextChanged: backend.getUserName = text
    }

    Button {
        x: 28
        y: 44
        text: "Quit"
        onClicked: Qt.quit()

    }

    Button {
        x: 180
        y: 44

        text: "Button"

        onClicked: id_root.qmlSignal("screen1/button01")
    }

    BackButton {
        id: backButton
        x: 83
        y: 313
    }

    PushButton {
        id: pushButton
        x: 59
        y: 116
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
