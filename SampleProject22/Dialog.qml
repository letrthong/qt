import QtQuick 2.0

Rectangle{ // white background
    id: root
    
// public
    property string text:   'text'
    property var    buttons: []//'0', '1']
    
    signal clicked(int index);  //onClicked: print('onClicked', index)
    
// private
    width: 250;  height: 250 // default size
    
    MouseArea{anchors.fill: parent} // don't allow touches to pass to MouseAreas underneath
    
    Text{ // text
        text: root.text
        anchors{centerIn: parent;  verticalCenterOffset: -0.1 * root.height}
        font.pixelSize: 0.1 * root.height
        width: 0.9 * parent.width
        wrapMode: Text.WordWrap
        horizontalAlignment: Text.AlignHCenter
    }
    
    Row{ // buttons
        id: row
        
        anchors{bottom: parent.bottom;  horizontalCenter: parent.horizontalCenter;  bottomMargin: 0.1 * root.height}
        spacing: 0.03 * root.width
        
        Repeater{
            id: repeater
            
            model: buttons
            
            delegate: Button{
                width: Math.min(0.5 * root.width, (0.9 * root.width - (repeater.count - 1) * row.spacing) / repeater.count)
                height: 0.2 * root.height
                text:  modelData
                
                onClicked: root.clicked(index)
            }
        }
    }
}
