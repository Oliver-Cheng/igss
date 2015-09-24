#ifndef ALGORITHMTESTPLATFORM_H
#define ALGORITHMTESTPLATFORM_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QLineEdit>
#include <SystemDispatcher.h>

class AlgorithmTestPlatform : public QWidget
{
    Q_OBJECT
public:
    explicit AlgorithmTestPlatform(SystemDispatcher* dispatcher, int appWidth, int appHeight);

    void setSystemStatus(QString status);
    void getPatientsStatus();

private:
    void initVariable();
    void constructIHM();
    void setConnections();

private:
    QHBoxLayout* platformLayout;
    QWidget* unknownArea;
    QWidget* terminalWindow;
    QVBoxLayout* terminalWindowLayout;
    QTextEdit* systemStatus;
    QLineEdit* systemCommand;
    SystemDispatcher* dispatcher;

    int appWidth;
    int appHeight;

signals:

public slots:
    void doParseCommand();
};

#endif // ALGORITHMTESTPLATFORM_H
