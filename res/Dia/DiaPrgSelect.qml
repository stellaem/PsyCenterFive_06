import QtQuick 2.0
import QtQuick.Layouts 1.15
import QtQuick.Dialogs 1.3
import QtQuick.Controls 2.15

Dialog {
    anchors.centerIn: parent
    property int numProg: _selectSpecialist.currentIndex
    title: qsTr("Выберите программу")
    standardButtons:  StandardButton.Open | StandardButton.Close
    onRejected: { Qt.quit() }
    contentItem: Rectangle {
        ColumnLayout {
            ComboBox {
                id: _selectSpecialist
                model: [qsTr("Специалист"), qsTr("Администратор"), qsTr("Разработчик программ")]
            }
            RowLayout { Label { text: qsTr("Логин") } TextField { } }
            RowLayout { Label { text: qsTr("Аароль") } TextField { echoMode: TextInput.Password } }
        }
    }
}
