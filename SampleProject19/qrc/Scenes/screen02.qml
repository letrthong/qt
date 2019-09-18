import QtQuick 2.0
import QtQuick.Controls  1.2
import io.qt.examples.backend 1.0

Item {
    id: id_screen1
    width: 300
    height: 480
    visible: true

    signal qmlSignalButton(int sendTo, string msg)

    Text { x: 23; y: 35; text: currentDateTime }


    BackEnd {
        id: backend
    }

    TextField {
        text:  backend.getUserName
        anchors.verticalCenterOffset: 199
        anchors.horizontalCenterOffset: 9
        placeholderText: qsTr("User name")
        anchors.centerIn: parent

        onTextChanged: backend.getUserName = text
    }

    BackButton_160_80 {
        id: backButton_160_801
        x: 89
        y: 305
    }

    ListView_250_250 {
        listId: 100
        id: listView_250_2501
        x: 48
        y: 89
    }
}
