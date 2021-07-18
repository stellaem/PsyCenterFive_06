#ifndef ENGINE_H
#define ENGINE_H

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QCoreApplication>
#include <QSqlQueryModel>
#include <QQmlContext>

#include "settings/settings.h"
#include "WindowAdm/admproperty.h"

class Engine : public QQmlApplicationEngine
{
public:
    explicit Engine(QGuiApplication &app, const QUrl &url, QObject *parent = nullptr);
    void loadPropertyAdm(void);
private:
    Settings *settings;
    AdmProperty *admProperty;
};


#endif // ENGINE_H
