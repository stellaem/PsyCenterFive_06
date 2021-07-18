import QtQuick 2.0
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import "qrc:/QML/Adm/" as Adm

Window {
    id: _parent
    signal signalExit
    width: 800
    height: 600
    ColumnLayout {
        anchors.centerIn: parent
        spacing: 6
        Button {
            id: _buttonMain
            text: qsTr("Главное окно")
            width: 180
            height: 50
            onClicked: {
                _parent.signalExit()
            }
        }
        Button {
            id: _buttonTimetable
            text: qsTr("Расписание")
            width: 180
            height: 50
            onClicked: {
                _parent.close()
                _timetable.show()
            }
        }
        Button {
            id: _buttonClientList
            text: qsTr("Список Клиетов")
            width: 180
            height: 50

            onClicked: {
                _parent.signalExit()
            }
        }
        Adm.TimetableAdm {
                id: _timetable
            }

    }
}
