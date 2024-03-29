#include <QtQml>
#include <QScreen>
#include <QQmlContext>
#include <QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "cameraselector.h"
#include "storagemanager.h"
#include "settings.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Settings *settings = new Settings();
    StorageManager::checkFolders();

    qmlRegisterType<StorageManager>("StorageManager", 1, 0, "StorageManager");
    qmlRegisterType<CameraSelector>("CameraSelector", 1, 0, "CameraSelector");
    QQmlApplicationEngine engine;

    QQmlContext *context = engine.rootContext();
    context->setContextProperty("settings", settings);
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
