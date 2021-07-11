import QtQuick 2.0
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import "qrc:/QML/Dia/" as Dia
import "qrc:/QML/Adm/" as Adm
import "qrc:/QML/Sp/" as Sp
import "qrc:/QML/Dev/" as Dev

ApplicationWindow {
    id: _parent
    visible: true
    width: 800
    height: 600
    title: qsTr("Программа \"Детский Центр\"")

    Dia.DiaPrgSelect {
        id: _diaSelect
        visible: true
        onAccepted:
            {
                switch(_diaSelect.numProg)
                {
                case 0:
                    _parent.hide();
                    _windowSp.show();
                    break;
                case 1:
                    _parent.hide();
                    _windowAdm.show();
                    break;
                case 2:
                    _parent.hide();
                    _windowDev.show();
                    break;
                }
            }
        }

    Adm.MainAdm {
        id: _windowAdm
        onSignalExit: {
            _windowAdm.close()
            _parent.show()
            _diaSelect.open()
        }
    }

    Sp.MainSp {
        id: _windowSp
        onSignalExit: {
            _windowSp.close()
            _parent.show()
            _diaSelect.open()
        }
    }

    Dev.MainDev {
        id: _windowDev
        onSignalExit: {
            _windowDev.close()
            _parent.show()
            _diaSelect.open()
        }
    }

}


