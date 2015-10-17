#ifndef CURVEREFORMATIONWINDOW_H
#define CURVEREFORMATIONWINDOW_H

#include <QWidget>

#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

class CurveReformationWindow : public QWidget
{
    Q_OBJECT
public:
    explicit CurveReformationWindow(QWidget *parent = 0);
    ~CurveReformationWindow();
    void constructIHM();
    void setConnections();


signals:

public slots:
    void brea();


private:
    QGroupBox *sourceImgBox;
    QGroupBox *vesselBox;
    QGroupBox *slicerImgBox;
    QGroupBox *outComingcprImgBox;

    QWidget *topWidget;
    QWidget *middleWidget;
    QWidget *controlBarWidget;


    QVBoxLayout *mainLayout;
    QHBoxLayout *topLayout;
    QHBoxLayout *middleLayout;
    QHBoxLayout *controlBarLayout;

    QPushButton *OkBtn;
    QPushButton *ResetBtn;

    QSpacerItem *controlBarSpace;

};

#endif // CURVEREFORMATIONWINDOW_H
