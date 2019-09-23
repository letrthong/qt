import QtQuick 2.0
import QtQuick.Controls  1.2

Item {
    id: id_screen1
    width: 300
    height: 480
    visible: true

    signal qmlSignalButton(int sendTo, string msg)

    Text { x: 23; y: 35; text: currentDateTime }

    EditText_250_50{
        x: 15
        y: 346

    }


    BackButton_160_80 {
        id: backButton_160_801
        x: 70
        y: 229
    }

    ListView_250_250 {
        listId: 100
        id: listView_250_2501
        x: 48
        y: 89
    }

    TextView_250_50 {
        id: textView_250_50
        x: 15
        y: 409
    }
}
