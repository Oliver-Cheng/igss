#ifndef PATIENTSWIDGET_H
#define PATIENTSWIDGET_H

#include <QWidget>
#include <QListWidget>
#include <QVBoxLayout>
#include <SystemDispatcher.h>

class PatientsWidget : public QWidget
{
public:
    explicit PatientsWidget(SystemDispatcher* dispatcher);
    void constructIHM();

private:
    SystemDispatcher* dispatcher;
    QHBoxLayout* patientsWidgetLayout;
    QWidget* controlBar;
    QListWidget* patientListWidget;

signals:

public slots:

};

#endif // PATIENTSWIDGET_H
