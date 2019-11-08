import QtQuick 2.0
//import QtQuick.Controls  1.2

Item {
    id: id_screen1

    width: 300
    height: 480
    visible: true

    property string screenName: "screen04"

    signal qmlSignalButton(int sendTo, string msg)

    PushButton_250_50 {
        id: pushButton_250_50
        x: 37
        y: 153
        pushButtonName: "button01"
    }

    BackButton_160_80 {
        id: backButton_160_80
        x: 8
        y: 0
    }

}
