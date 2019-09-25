import QtQuick 2.0

Rectangle{// background
    id: root

// public
    property double minimum: 0
    property double value:   0
    property double maximum: 10
    
// private
    width: 250;  height: 50 // default size

    border.width: 0.05 * root.height
    radius: 0.5 * height
    
    Rectangle{ // foreground
        visible: value > minimum
        x: 0.1 * root.height;  y: 0.1 * root.height
        width: Math.max(height, 
               Math.min((value - minimum) / (maximum - minimum) * (parent.width - 0.2 * root.height), 
                        parent.width - 0.2 * root.height)) // clip
        height: 0.8 * root.height
        color: 'black'
        radius: parent.radius
    }
}
