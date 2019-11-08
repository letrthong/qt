import QtQuick 2.0
//import QtQuick.Controls  1.2

Item {
    id: id_screen1

    width: 300
    height: 480
    visible: true

    property string screenName: "screen05"

    signal qmlSignalButton(int sendTo, string msg)

    PushButton_250_50 {
        id: pushButton_250_50
        x: 25
        y: 149
        pushButtonName: "button01"
    }

    BackButton_160_80 {
        id: backButton_160_80
        x: 0
        y: 0
    }

}
