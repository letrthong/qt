import QtQuick 2.0

Item{
    id: root
    
// public
    
// private
    width: 250;  height: 50 // default size
    
    Item{ // square
        id: square
        
        anchors.centerIn: parent
        property double minimum: Math.min(root.width, root.height)
        width: minimum;  height: minimum
        
        Repeater{
            id: repeater
            
            model: 8
            
            delegate: Rectangle{
                color: 'black'
                
                property double b: 0.1
                property double a: 0.25
                
                width: ((b - a) / repeater.count * index + a) * square.height;  height: width
                radius: 0.5 * height
                
                x: 0.5 * square.width  + 0.5 * (square.width  - width )  * Math.cos(2 * Math.PI / repeater.count * index) - 0.5 * width
                y: 0.5 * square.height - 0.5 * (square.height - height)  * Math.sin(2 * Math.PI / repeater.count * index) - 0.5 * height
            }
        }
    }
    
    Timer {
        interval: 10
        running: true
        repeat:  true
        
        onTriggered: square.rotation += 1 // degree
    }
}
