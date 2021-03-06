import QtQuick 2.0
import QtQuick.Layouts 1.15
import QtQuick.Controls 1.4
import QtQuick.Controls 2.15
import "qrc:/QML/_widgets/" as Widgets

Rectangle {
    property alias _calendar: _calendar
    ColumnLayout {
        anchors.fill: parent
        spacing: 6

        ComboBox {
            id: _selectPeriod
            Layout.fillWidth: true
            model: ["День", "Неделя", "Месяц"]
        }



        Calendar {
            id: _calendar
            onClicked:
            {
                admProperty.setDate(date)
            }

        }
        Widgets.Tasks {
            id: _task
            _listViewTask.model: admProperty.getModelTask()
        }
    }
}
