import QtQuick 2.0
import QtQuick.Controls  1.2
import io.qt.examples.backend 1.0


Item {
    id: name
     width: 250
     height: 50

    EditTextBackEnd {
        id: backend
    }

    TextField {
        width: 211
        height: 20
        text:  backend.getEditText
        anchors.verticalCenterOffset: 0
        anchors.horizontalCenterOffset: 7
        placeholderText: qsTr("User name")
        anchors.centerIn: parent

        onTextChanged: {
            backend.getEditText = text
        }
    }
}
