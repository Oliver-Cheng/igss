#ifndef PATIENTSWIDGET_H
#define PATIENTSWIDGET_H

#include <QWidget>
#include <SystemDispatcher.h>

class PatientsWidget : public QWidget
{
public:
    explicit PatientsWidget(SystemDispatcher* dispatcher);


private:
    SystemDispatcher* dispatcher;

signals:

public slots:

};

#endif // PATIENTSWIDGET_H
