import QtQuick 2.0
import QtQuick.Controls  1.2
import io.qt.examples.backend 1.0

ApplicationWindow {
    id: id_root
    width: 300
    height: 480
    visible: true
    objectName: "screen1"

    signal qmlSignal(string msg)


    BackEnd {
        id: backend
    }

    TextField {
        text: "#backend.userName#"
        placeholderText: qsTr("User name")
        anchors.centerIn: parent

        onTextChanged: backend.userName = text
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
