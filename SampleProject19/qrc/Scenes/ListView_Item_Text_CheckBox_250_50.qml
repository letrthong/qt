import QtQuick 2.0
import QtQuick.Controls 1.5
import io.qt.examples.backend 1.0

import "../js/my_button_impl.js" as MyScript

MouseArea  {
    id: name
    width: 250
    height: 50

    property bool itemCheckBox: false

    property string itemType: "text"
    property string itemText: "N/A"
    property string itemIcon: ""
    property string itemRange: "[0:1]"
    property string itemFormula: "1x"
    property string itemValue: "true"


    ListViewBackEnd {
        id: backend
        getIndex: index;
    }


    Rectangle {
        id: rectangle
        width: 250
        height: 50
        color: "#eef0e6"

        Background_250_50 {
            id: background_250_50

            Rectangle {
               id: id_rectangle_press
               x: 10
               y: 40
               width: 234
               height: 1
               color: "#ab1414"
               border.color: "#00000000"
               border.width: 4
               visible: name.pressed
            }

            Text {
                x: 109
                y: 8
                width: 128
                height: 34
                text: itemText
                horizontalAlignment: Text.AlignHCenter
                font.bold: true
                font.pointSize: 19
                // onEditingFinished: itemText = text
            }

            CheckBox {
                id: id_check_box
                visible: false
                x: 25
                y: 10
                width: 40
                height: 32
                clip: true
                transformOrigin: Item.Center
                checked:  getValueBool()
                onClicked: {

                    if(checked == true){
                        itemValue = "true"
                    }else{
                         itemValue = "false"
                    }
                    backend.getValue = itemValue
                    console.log("backend.done index=" + index + " "  + checked)
                }
            }

            Switch {
                  id: id_switch
                  x: 2
                  y: 17
                  height: 20
                  visible: false
                   checked:  getValueBool()
                   onClicked: {

                       if(checked == true){
                           itemValue = "true"
                       }else{
                            itemValue = "false"
                       }
                       backend.getValue = itemValue
                       console.log("backend.done index=" + index + " "  + checked)
                   }
            }

            Image {
                id: id_image
                visible: false
                x: 77
                y: 8
                width: 35
                height: 35
                opacity: 0.2
                source:  getIconPath()
                fillMode: Image.PreserveAspectFit
            }

            ComboBox {
                id: id_comboBox
                visible: false
                x: 2
                y: 8
                width: 101
                height: 29
                currentIndex: getValueIndex()
                model: ["First", "Second", "Third"]

                onCurrentIndexChanged: {
                     console.log("onCurrentIndexChanged  currentIndex=" + currentIndex)
                    backend.getValue = currentIndex.toString();
                }
            }

            SpinBox {
               id: id_spinBox
                visible: false

               value: 1 // "Medium"

               property var items: ["Small", "Medium", "Large"]
               x: 13
               y: 8
               width: 66
               height: 29



            }


        }
    }

    function getValueBool(){
        if( itemValue === "true"){
             return  true
        }
        return false;
    }

    function getIconPath(){
        return itemIcon;
    }

    function getValueIndex(){
        return   parseInt(itemValue)
    }

   Component.onCompleted: {
       console.log("onCompleted  itemType=" + itemType)
        if(itemType == "text" ){
        }else  if(itemType == "checkbox" ) {
            id_check_box.visible = true
        }else  if(itemType == "switch" ) {
            id_switch.visible = true
        }else if(itemType == "comboBox" ) {
            id_comboBox.visible = true
        }else if(itemType == "spinBox" ) {
            id_spinBox.visible = true
        }else{

        }

        if(getIconPath() === ""){

        }
        else{
            id_image.visible = true
        }
   }

   onClicked: {
       var text = MyScript.clickOnItemOfList();
       qmlSignalButton(0, text);
   }
}


