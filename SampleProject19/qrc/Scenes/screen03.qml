import QtQuick 2.0
import QtQuick.Controls  1.2

Item {
    id: id_screen1
    width: 300
    height: 480
    visible: true

    signal qmlSignalButton(int sendTo, string msg)

    Text { x: 23; y: 35; text: currentDateTime }

    BackButton_160_80 {
        id: backButton_160_801
        x: 89
        y: 305
    }

    ListView_250_250 {
        id: listView_250_2501
        x: 48
        y: 89
    }
}
