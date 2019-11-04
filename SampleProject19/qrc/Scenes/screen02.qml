import QtQuick 2.0
import QtQuick.Controls  1.2

Item {
    id: id_screen1
    width: 300
    height: 480
    visible: true
    property string screenName: "screen02"
    signal qmlSignalButton(int sendTo, string msg)

    Text { x: 23; y: 17; text: currentDateTime }

    EditText_250_50{
        x: 15
        y: 382

    }


    BackButton_160_80 {
        id: backButton_160_801
        x: 123
        y: 315
    }


    TextView_250_50 {
        id: textView_250_50
        x: 23
        y: 430
    }

    Background_ListView_250_250 {
        id: background_ListView_250_250
        x: 23
        y: 54

        ListView_250_250 {
            listviewId: 100
            id: listView_250_250
            x: 0
            y: 0
            width: 239
            height: 240
            interactive: true
            boundsBehavior: Flickable.DragOverBounds
            clip: true
            highlightRangeMode: ListView.ApplyRange
            spacing: 2
            delegate: ListView_Item_Button_250_50{
                itemText : model.modelData
            }
        }
    }
}
