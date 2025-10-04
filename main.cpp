#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "LedController.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    LedController controller;
    engine.rootContext()->setContextProperty("ledController", &controller);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}
