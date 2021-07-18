#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QLocale>
#include <QTranslator>
#include <QQmlContext>
#include <QSqlDatabase>
#include <QSqlQueryModel>

#include "persons/client.h"

#include "translator.h"
#include "engine.h"


int main(int argc, char *argv[])
{
/**************************************************************************************************/
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);
/*------------------------------------------------------------------------------------------------*/
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".//db.sqlite");
    db.open();
/*------------------------------------------------------------------------------------------------*/
    // Translator *translator = new Translator(&app);
/*------------------------------------------------------------------------------------------------*/
    const QUrl url(QStringLiteral("qrc:/QML/main.qml"));
    Engine *engine = new Engine(app, url);
    engine->load("qrc:/QML/main.qml");
/*------------------------------------------------------------------------------------------------*/
    return app.exec();
/**************************************************************************************************/
}
