#include <QGuiApplication>
#include <QQmlApplicationEngine>

class my_double
{
public:
    explicit my_double(double x = 1.0, double y = 2.0) { m_x = x; m_y = y; }
    //my_double(double x, double y) { m_x = x; m_y = y; }

private:
    double m_x;
    double m_y;
};

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    my_double t1;
    my_double t2 = 0x54;

    return app.exec();
}
