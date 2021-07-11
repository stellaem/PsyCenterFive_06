import QtQuick 2.0
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    id: _parent
    signal signalExit   // Задаём сигнал
    width: 800
    height: 600

    // Кнопка для открытия главного окна приложения
    Button {
        text: qsTr("Главное окно")
        width: 180
        height: 50
        anchors.centerIn: parent
        onClicked: {
            _parent.signalExit() // Вызываем сигнал
        }
    }
}
