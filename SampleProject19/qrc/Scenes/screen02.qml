import QtQuick 2.0
import QtQuick.Controls  1.2
import io.qt.examples.backend 1.0

Item {
    id: id_screen1
    width: 300
    height: 480
    visible: true

    signal qmlSignalButton(int sendTo, string msg)

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

    BackButton_160_80 {
        id: backButton_160_80
        x: 33
        y: 26
    }
}
