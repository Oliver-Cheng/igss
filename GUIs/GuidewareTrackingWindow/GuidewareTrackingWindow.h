#ifndef GUIDEWARETRACKINGWINDOW_H
#define GUIDEWARETRACKINGWINDOW_H

#include <Patient.h>
#include <SystemDispatcher.h>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QWidget>

class GuidewareTrackingWindow : public QWidget
{
    Q_OBJECT
public:
    explicit GuidewareTrackingWindow(int x,
                                     int y,
                                     int width,
                                     int height,
                                     QFont *caracterStyle,
                                     SystemDispatcher* systemDispatcher);
    ~GuidewareTrackingWindow();
    void initVariable();
    void displayWindow();
    void constructionIHM();


private:
    int x;
    int y;
    int width;
    int height;
    Patient* patientHandling;
    SystemDispatcher* systemDispatcher;

    QFont *caracterStyle;
    QString labelStyleSheet;

    QGridLayout* guidewareTrackingLayout;
    QHBoxLayout* vtkDisplayBoardLayout;
    QVBoxLayout* guideControlBoardLayout;
    QVBoxLayout* surgeryInformationLayout;

    QWidget* nameBar;
    QWidget* vtkDisplayBar;
    QWidget* guideControlBoard;
    QWidget* vtkDisplayBoard;
    QWidget* primaryDisplay;
    QWidget* guidewareTrackingDisplay;
    QWidget* surgeryInformation;
    QWidget* controlButtonArea;
    QWidget* unknownArea;

    QLabel* surgeryID;
    QLabel* patientName;
    QLabel* surgeryDate;
};

#endif // GUIDEWARETRACKINGWINDOW_H
