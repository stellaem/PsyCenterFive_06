#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QLocale>
#include <QTranslator>
#include <QQmlContext>
#include <QSqlDatabase>
#include <QSqlQueryModel>

#include "persons/client.h"
#include "settings/settings.h"

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
    Settings *settings = new Settings();
    QSqlQueryModel *qMCabinet = new QSqlQueryModel();
    qMCabinet->setQuery("select id, name from cabinet");
/*------------------------------------------------------------------------------------------------*/
    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "PsyCenterFive_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            app.installTranslator(&translator);
            break;
        }
    }
/*------------------------------------------------------------------------------------------------*/
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/QML/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.rootContext()->setContextProperty("settings", settings);
    engine.rootContext()->setContextProperty("qMCabinet", qMCabinet);
    engine.load(url);
/*------------------------------------------------------------------------------------------------*/
    return app.exec();
/**************************************************************************************************/
}
