#ifndef SURGERYPLANWINDOW_H
#define SURGERYPLANWINDOW_H

#include <QWidget>

class SurgeryPlanWindow : public QWidget
{
    Q_OBJECT
public:
    explicit SurgeryPlanWindow(QWidget *parent = 0);
    void display();

signals:

public slots:
};

#endif // SURGERYPLANWINDOW_H
