import QtQuick 2.0
import QtQuick.Controls  1.2


ListView {
    id: listView1
    x: 8
    y: 8
    width: 240
    height: 240

    contentWidth: 1
    flickableDirection: Flickable.VerticalFlick

    property int listviewId: 0

    model: myModel

    function resetElement(id_list){
        for(var i = 0; i < id_list.contentItem.children.length; i++) {
            var listItem = id_list.contentItem.children[i];
            listItem.listId = 0
        }
    }
}




