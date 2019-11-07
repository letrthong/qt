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
        x: 27
        y: 79
       pushButtonName: "button01"
    }

}
