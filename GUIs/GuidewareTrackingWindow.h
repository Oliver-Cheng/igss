#ifndef GUIDEWARETRACKINGWINDOW_H
#define GUIDEWARETRACKINGWINDOW_H

#include <Patient.h>
#include <SystemDispatcher.h>

class GuidewareTrackingWindow : public QWidget
{
    Q_OBJECT
public:
    explicit GuidewareTrackingWindow(int x,
                                     int y,
                                     int width,
                                     int height,
                                     SystemDispatcher* systemDispatcher);
    ~GuidewareTrackingWindow();
    void displayWindow();

private:
    int x;
    int y;
    int width;
    int height;
    Patient* patientHandling;
    SystemDispatcher* systemDispatcher;
};

#endif // GUIDEWARETRACKINGWINDOW_H
