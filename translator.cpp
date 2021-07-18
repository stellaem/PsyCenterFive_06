#include "translator.h"
#include <QLocale>
Translator::Translator(QGuiApplication *app, QObject *parent) : QTranslator(parent)
{
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "PsyCenterFive_" + QLocale(locale).name();
        if (this->load(":/i18n/" + baseName)) {
            app->installTranslator(this);
            break;
        }
    }
}
