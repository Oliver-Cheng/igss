#include "AlgorithmTestPlatform.h"

AlgorithmTestPlatform::AlgorithmTestPlatform(SystemDispatcher* dispatcher,
                                             QFont *caracterStyle,
                                             int appWidth,
                                             int appHeight)
{
    this->dispatcher = dispatcher;
    this->caracterStyle = caracterStyle;
    this->appWidth = appWidth;
    this->appHeight = appHeight;
    this->setFixedHeight(this->appHeight*0.18);
    this->setFont(*this->caracterStyle);
    this->constructIHM();
    this->setConnections();
}

void AlgorithmTestPlatform::initVariable(){

}

void AlgorithmTestPlatform::constructIHM(){


    unknownArea = new QWidget();
    unknownArea->setFixedWidth(this->appWidth*0.13);

    terminalWindow = new QWidget();
    terminalWindowLayout = new QVBoxLayout(terminalWindow);

    systemStatus = new QTextEdit();
    systemStatus->setFont(*this->caracterStyle);
    systemStatus->setStyleSheet("border: 1px solid aliceBlue;border-radius: 0px;padding: 2 2px;background-color: transparent; color: AliceBlue");

    systemCommand = new QLineEdit();
    systemCommand->setFont(*this->caracterStyle);
    systemCommand->setStyleSheet("border: 1px solid aliceBlue;border-radius: 0px;padding: 2 2px;background-color: transparent; color: AliceBlue");


    terminalWindowLayout->addWidget(systemStatus);
    terminalWindowLayout->addWidget(systemCommand);
    terminalWindowLayout->setSpacing(2);
    terminalWindowLayout->setMargin(0);

    platformLayout = new QHBoxLayout(this);
    platformLayout->addWidget(unknownArea);
    platformLayout->addWidget(terminalWindow);
    platformLayout->setSpacing(0);
    platformLayout->setMargin(0);
}

void AlgorithmTestPlatform::setConnections(){
    this->connect(systemCommand,SIGNAL(returnPressed()),this,SLOT(doParseCommand()));
}

void AlgorithmTestPlatform::setSystemStatus(QString status){
    this->systemStatus->setText(status);
}

//!----------------------------------------------------------------------------------------
//!
//! \brief AlgorithmTestPlatform::doParseCommand
//!
void AlgorithmTestPlatform::doParseCommand(){

    QString cmd = systemCommand->text();
    setSystemStatus(cmd);
    QString msg;

    if(cmd.contains("vef")){
        if(cmd.contains("mri")){
            QStringList temp = cmd.split(" mri ");
            int id = temp[1].toInt(0,10);
            msg = this->dispatcher->doImageProcessingByMethodType(id, 3, "vef");
        }
        else{
            //!do 2d vessel enhancement
        }
        this->setSystemStatus(msg);
    }
    else if(cmd.contains("check")){
        if(cmd.contains("mri")){
            if(cmd.contains("states")){
                this->getPatientsStatus();
            }
        }
    }
}

//!----------------------------------------------------------------------------------------
//!doParseCommand
//! \brief AlgorithmTestPlatform::getPatientsStatus
//!
void AlgorithmTestPlatform::getPatientsStatus(){
    QStringList s = this->dispatcher->getPatientsStatus();
    QString info = "";
    for(int i = 0; i < s.length(); i++){
        info += s[i]+"\n";
    }
    this->setSystemStatus(info);
}

