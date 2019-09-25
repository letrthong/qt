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
        y: 368

    }


    BackButton_160_80 {
        id: backButton_160_801
        x: 127
        y: 296
    }

    ListView_250_250 {
        listId: 100
        id: listView_250_2501
        x: 23
        y: 89
        width: 239
        height: 177
        delegate: ListView_Item_Button_250_50{
            itemText : model.modelData
        }
    }

    TextView_250_50 {
        id: textView_250_50
        x: 15
        y: 409
    }
}
