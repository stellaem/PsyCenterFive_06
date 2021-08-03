#include "engine.h"

Engine::Engine(QGuiApplication &app, const QUrl &url, QObject *parent) : QQmlApplicationEngine(parent),
    settings(new Settings()),
    admProperty(new AdmProperty())
{

    QObject::connect(this, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    loadPropertyAdm();
}

void Engine::loadPropertyAdm()
{
    this->rootContext()->setContextProperty("settings", settings);
//    this->rootContext()->setContextProperty("qMPlace", admProperty->getQueryModelPlace());
    this->rootContext()->setContextProperty("admProperty", admProperty);
}

