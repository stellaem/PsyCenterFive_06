#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <QTranslator>
#include <QGuiApplication>

class Translator : public QTranslator
{
public:
    explicit Translator(QGuiApplication *app, QObject *parent = nullptr );
};

#endif // TRANSLATOR_H
