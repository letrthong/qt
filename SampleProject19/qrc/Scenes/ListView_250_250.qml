import QtQuick 2.0
import QtQuick.Controls  1.2


ListView {
    id: listView1
    x: 8
    y: 8
    width: 151
    height: 165
    boundsBehavior: Flickable.StopAtBounds
    contentWidth: 1
    flickableDirection: Flickable.HorizontalFlick
    highlightRangeMode: ListView.StrictlyEnforceRange
	
    property string listModelType: "string int"
    property int   listId: 0

	delegate: Item {
        x: 5
        width: 80
        height: 40
        Row {
            id: id_row
            Text {
                text: model.modelData
                font.bold: true
                anchors.verticalCenter: parent.verticalCenter
            }
            spacing: 10
        }
    }
	
    model: myModel


    function resetElement(id_list){
        for(var i = 0; i < id_list.contentItem.children.length; i++) {
            var listItem = id_list.contentItem.children[i];
            listItem.listId = 0

        }
    }
}




