import QtQuick 2.0

ListView {
    id: root
    
    width: 255;  height: 290 // default size
    spacing: 0.01 * height
    
    model: VisualItemModel {
        Button {
            width: 0.98 * root.width;  height: 0.2 * root.width // resize
            text: 'Button'

            onClicked: dialog.visible = true
        }
        
        CheckBox {
            property bool backend: false

            width: 0.98 * root.width;  height: 0.2 * root.width // resize
            text: 'CheckBox'
            checked:   backend
            
            onClicked: backend = checked
        }
        
        ListView { // RadioButton
            id: radioButtons
            
            width: 0.98 * root.width;  height: 0.2 * root.width * count
            interactive: false
            
            model: [{text: 'RadioButton 0'}, {text: 'RadioButton 1'}]
            
            delegate: RadioButton {
                width: 0.98 * root.width;  height: 0.2 * root.width // resize
                text:      modelData.text
                checked:   radioButtons.currentIndex == index // equality

                onClicked: radioButtons.currentIndex  = index // assignment
            }
        }
        
        Switch {
            property bool backend: false
            
            width: 0.98 * root.width;  height: 0.2 * root.width // resize
            checked:   backend
            
            onClicked: backend = checked
        }
        
        Slider {
            property double backend: 0
            
            width: 0.98 * root.width;  height: 0.2 * root.width // resize
            minimum:  -10
            value:     backend
            maximum:   10
            
            onClicked: backend = value
        }
        
        ProgressBar {
            width: 0.98 * root.width;  height: 0.2 * root.width // resize
            minimum:  -10
            value:      0
            maximum:   10
        }
        
        Spinner{
            width: 0.98 * root.width;  height: 0.2 * root.width // resize
        }
        
        ListView{ // PageDots
            id: listView
            
            width: 0.98 * root.width;  height: 0.4 * root.width // resize
            snapMode: ListView.SnapOneItem
            orientation: Qt.Horizontal
            
            model: 3
            
            delegate: Item{
                width: listView.width;  height: listView.height
                
                Text{
                    text: index
                    font.pixelSize: 0.9 * listView.height
                    anchors.centerIn: parent
                }
            }
            
            onMovementEnded: listView.currentIndex = listView.indexAt(contentX, 0)
            
            PageDots{
                width: 0.25 * parent.width;  height: 0.1 * parent.height
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.bottom
                page:  listView.currentIndex
                pages: listView.count
            }
        }
        
        Tabs{
            width: 0.98 * root.width;  height: 0.2 * root.width // resize
            model:          ['zero', 'one', 'two'] // right to left (backwards)
            currentIndex:   0
        }
    }
    
    ScrollBar{}
    
    Dialog{
        id: dialog
        
        anchors.fill: parent
        text: 'Are you sure?'
        buttons: ['No', 'Yes']
        visible: false
        
        onClicked: visible = false
    }
}
