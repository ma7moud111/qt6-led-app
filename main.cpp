#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "LedController.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    LedController controller;
    engine.rootContext()->setContextProperty("ledController", &controller);

            // 👇 IMPORTANT: must include the URI path prefix here!
    const QUrl url(u"qrc:/LedSimulation/main.qml"_qs);

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
                     &app, []() { QCoreApplication::exit(-1); },
                     Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
