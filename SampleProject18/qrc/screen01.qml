import QtQuick 2.0
import QtQuick.Controls  1.2
import io.qt.examples.backend 1.0
import QtQml.StateMachine 1.0 as DSM


ApplicationWindow {
    id: id_root
    width: 300
    height: 480
    visible: true

    signal qmlSignal(string msg)
    

    BackEnd {
        id: backend
    }

    TextField {
        text: backend.userName
        placeholderText: qsTr("User name")
        anchors.centerIn: parent

        onTextChanged: backend.userName = text
    }
  
    Button {
        text: "Quit"
        onClicked: Qt.quit()

    }
    
    Button {
        
        text: "Button"
        
        onClicked: id_root.qmlSignal("screen1/button01")
    }

}