import QtQuick 2.0
import QtQuick.Controls  1.2

Item {
    id: id_screen1
    width: 300
    height: 480
    visible: true

    signal qmlSignalButton(int sendTo, string msg)


    BackButton_160_80 {
        id: backButton_160_801
        x: 89
        y: 305
    }

    ListView_250_250 {
        listId: 100
        id: listView_250_2501
        x: 23
        y: 89
        width: 239
        height: 177
        delegate: ListView_Item_Text_CheckBox_250_50{
            itemText : model.getText
            itemValue: model.getValue
            itemType:  model.getType
            itemIcon:  model.getIcon
        }
        ScrollBar{}
    }
}
