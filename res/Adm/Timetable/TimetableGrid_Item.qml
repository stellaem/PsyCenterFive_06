import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Rectangle {
    id: _parent
    property string typeName: ""
    property int idClass: 0
    property date time: new Date()
    property var place: new Place()
    property var specialist: new Specialist()
    property int type: 0
    property var listClient: []
    color: "red"
    Drag.active: _mouseAreaTransfer.drag.active
    Drag.hotSpot.x: width / 2

    MouseArea {
        id: _mouseAreaTransfer
        anchors.fill:  _parent
        drag.target: _parent
        drag.minimumX : 0
        drag.maximumX: width * qMPlace.rowCount() - width
        drag.minimumY: 0
        drag.maximumY: _parent.parent.height - height
        onReleased: {
            var tile =_parent.Drag.target.parent.children[_parent.Drag.target.objectName]
            var columns = _parent.Drag.target.parent.columns
            var rows = _parent.Drag.target.parent.rows
            var column = Math.floor(_parent.Drag.target.objectName / rows)
            var row = _parent.Drag.target.objectName - column * rows
            _parent.x = tile.x
            _parent.y = tile.y
            _parent.Layout.column = column
            _parent.Layout.row = row
        }

        acceptedButtons: Qt.LeftButton | Qt.RightButton
        hoverEnabled : true
        onClicked: (mouse) => mouse.button & Qt.RightButton ? _contextMenu.popup(): console.log( "left click")

//        onDoubleClicked: (mouse) => mouse.button & Qt.leftButton ? _diaChengItem.open() : console.log( "asd")

    }
    Item {
        id: _dilator
        width:  _parent.width
        height: 10
        anchors.bottom: _parent.bottom
        anchors.horizontalCenter: _parent.horizontalCenter
        MouseArea {
            anchors.fill: _dilator
            cursorShape : Qt.SizeVerCursor
            drag.target: _dilator
            onMouseYChanged: {
                if(drag.active){
                    if (mouseY - ( _parent.height/ _parent.Layout.rowSpan) > _parent.height/ _parent.Layout.rowSpan)
                    {_parent.Layout.rowSpan++}
                    else if(mouseY - ( _parent.height/ _parent.Layout.rowSpan) < 0)
                    {_parent.Layout.rowSpan--}
                }
            }
        }

    }

    Menu {
        id: _contextMenu
        width: 100
        MenuItem { text: qsTr("Изменить") }
        MenuItem { text: qsTr("Удалить") }
    }




}


