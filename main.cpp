#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QLocale>
#include <QTranslator>
#include <QQmlContext>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QQuickStyle>

#include "persons/client.h"

#include "translator.h"
#include "engine.h"
#include "objects/cellclass.h"


int main(int argc, char *argv[])
{
/**************************************************************************************************/
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);
    QQuickStyle::setStyle("Material");
/*------------------------------------------------------------------------------------------------*/
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".//db.sqlite");
    db.open();
/*------------------------------------------------------------------------------------------------*/
    // Translator *translator = new Translator(&app);
/*------------------------------------------------------------------------------------------------*/
    qmlRegisterType<CellClass>("Objects", 1, 0, "CellClass");
    const QUrl url(QStringLiteral("qrc:/QML/main.qml"));
    Engine *engine = new Engine(app, url);
    engine->load("qrc:/QML/main.qml");

/*------------------------------------------------------------------------------------------------*/
    return app.exec();
/**************************************************************************************************/
}
