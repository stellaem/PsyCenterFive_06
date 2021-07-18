import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Item {
    id: _parent
    property string typeName: ""
    property int idClass: 0
    property date time: new Date()
    property var place: new Place()
    property var specialist: new Specialist()
    property int type: 0
    property var listClient: []
    MouseArea {
        id: _mouseArea
        anchors.fill: _parent
        drag.target: _clsTile
        onReleased: parent = _clsTile.Drag.target !== null ? _clsTile.Drag.target : _parent

        Rectangle {
           id: _clsTile
           width: _parent.width
           height: _parent.height
           color: "#CBF4DB"

           Drag.active: _mouseArea.drag.active
           Drag.hotSpot.x: width / 2
           states:
                State {
                   when: _mouseArea.drag.active
                   ParentChange { target: _clsTile; parent: _parent }
                   AnchorChanges { target: _clsTile; anchors.verticalCenter: undefined; anchors.horizontalCenter: undefined }
                }

           Text{
               id: _textSpecialist
               text: specialist.name + ' ' + specialist.surname

           }
           Text{
               anchors.top: _textSpecialist.bottom
               id: _textClient
               text: listClient.length > 1 ? 'группа' : listClient[0].name + ' ' + listClient[0].surname

           }
        }

        MouseArea {
            z:-1
            id: _aaa
            width:  parent.width
            height: _mouseAreaDilator.height + 50
            anchors.horizontalCenter: _mouseAreaDilator.horizontalCenter
            anchors.verticalCenter: _mouseAreaDilator.verticalCenter
            State {
                when: _mouseAreaDilator.drag.active
                PropertyChanges { target: _aaa; cursorShape : Qt.SizeVerCursor }
            }
        }
        MouseArea {
            id: _mouseAreaDilator
            width:  parent.width
            height:  (_parent.height/ _parent.Layout.rowSpan) * 3
            anchors.left: parent.left
            anchors.bottom: _clsTile.bottom
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

            Rectangle {
                id: _dilator
                anchors.fill: parent
                Drag.active: _mouseAreaDilator.drag.active
                opacity: 100
                color: "red"
            }
        }


        acceptedButtons: Qt.LeftButton | Qt.RightButton
        hoverEnabled : true
        onClicked: (mouse) => {
            if(mouse.button & Qt.RightButton)
            {
                _contextMenu.popup()
            }
            else
            {
                console.log("leftClicked");
            }
        }
    }

    Menu {
        id: _contextMenu
        width: 100
        MenuItem { text: qsTr("Cut") }
        MenuItem { text: qsTr("Copy") }
        MenuItem { text: qsTr("Paste") }
    }
}
