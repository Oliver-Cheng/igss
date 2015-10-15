#include "GuidewareTrackingWindow.h"

GuidewareTrackingWindow::GuidewareTrackingWindow(int x,
                                                 int y,
                                                 int width,
                                                 int height,
                                                 SystemDispatcher* systemDispatcher) : QWidget(){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->systemDispatcher = systemDispatcher;

    this->resize(this->width, this->height);
    this->move(this->x, this->y);
}

//!----------------------------------------------------------------------------------------------------
//!
//! \brief GuidewareTrackingWindow::~GuidewareTrackingWindow
//!
GuidewareTrackingWindow::~GuidewareTrackingWindow(){

}

//!----------------------------------------------------------------------------------------------------
//!
//! \brief GuidewareTrackingWindow::displayWindow
//!
void GuidewareTrackingWindow::displayWindow(){
    this->resize(this->width, this->height);
    this->move(this->x, this->y);
    this->show();
}
