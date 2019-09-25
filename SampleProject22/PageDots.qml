import QtQuick 2.0

Item{
    id: root

// public
    property int page:  0 // current
    property int pages: 3 // total
    
// private
    width: 250;  height: 50 // default size
    
    Row{
        spacing: (root.width - pages * root.height) / (pages - 1)
        
        Repeater{
            model: pages
            
            Rectangle{ // circle
                width:  root.height;  height: width
                radius: 0.5 * width
                color:  index == page? 'black': 'white'
                border.width: 0.05 * root.height
            }
        }
    }
}
