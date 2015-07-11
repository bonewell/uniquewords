#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include "counter.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    qmlRegisterType<Counter>("Counter", 1, 0, "Counter");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
