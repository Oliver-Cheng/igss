#include "SurgeryPlanWindow.h"

SurgeryPlanWindow::SurgeryPlanWindow(QWidget *parent) : QWidget(parent)
{

    this->constructPatientInformationWidget();
    this->constructDoctorInformationWidget();
    this->regroupAllComponents();

    this->initialisation();
    this->setConnections();
}

void SurgeryPlanWindow::displayWindow(){
    this->showFullScreen();
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::setConnections
//!
void SurgeryPlanWindow::setConnections(){

    this->connect(mainSplitter, SIGNAL(splitterMoved(int,int)),this, SLOT(mainSplitterMoved(int, int)));

    // switch the volume rendering options
    this->connect(opacityTransferChoice, SIGNAL(toggled(bool)), this, SLOT(opacityTransformationStateChanged(bool)));
    this->connect(colorTransferChoice, SIGNAL(toggled(bool)), this, SLOT(colorTransformationStateChanged(bool)));
    this->connect(gradientTransferChoice, SIGNAL(toggled(bool)), this, SLOT(gradientTransformationStateChanged(bool)));

    // actions of the mouse's pointer on the plotting board
    this->connect(transformationPlottingBoard, SIGNAL(mouseDoubleClick(QMouseEvent*)), this, SLOT(generateNewTransformationPoint(QMouseEvent*)));
    this->connect(transformationPlottingBoard, SIGNAL(mouseMove(QMouseEvent*)), this, SLOT(transformPointTracking(QMouseEvent*)));
    this->connect(transformationPlottingBoard, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(lockTargetPoint(QMouseEvent*)));
    this->connect(transformationPlottingBoard, SIGNAL(mouseRelease(QMouseEvent*)), this, SLOT(positioningTransformPoint(QMouseEvent*)));

    // ....
    this->connect(this->originalOption, SIGNAL(mouseHover()), this, SLOT(originalOptionHovered()));
    this->connect(this->originalOption, SIGNAL(mouseLeftButtonClicked()), this, SLOT(originalOptionClicked()));
    this->connect(this->originalOption, SIGNAL(mouseLeftButtonReleased()), this, SLOT(originalOptionReleased()));
    this->connect(this->originalOption, SIGNAL(mouseLeaved()), this, SLOT(originalOptionLeaved()));

    this->connect(this->transparentBrainOption, SIGNAL(mouseHover()), this, SLOT(transparentBrainOptionHovered()));
    this->connect(this->transparentBrainOption, SIGNAL(mouseLeftButtonClicked()), this, SLOT(transparentBrainOptionClicked()));
    this->connect(this->transparentBrainOption, SIGNAL(mouseLeftButtonReleased()), this, SLOT(transparentBrainOptionReleased()));
    this->connect(this->transparentBrainOption, SIGNAL(mouseLeaved()), this, SLOT(transparentBrainOptionLeaved()));

    this->connect(this->greyMatterOption, SIGNAL(mouseHover()), this, SLOT(greyMatterOptionHovered()));
    this->connect(this->greyMatterOption, SIGNAL(mouseLeftButtonClicked()), this, SLOT(greyMatterOptionClicked()));
    this->connect(this->greyMatterOption, SIGNAL(mouseLeftButtonReleased()), this, SLOT(greyMatterOptionReleased()));
    this->connect(this->greyMatterOption, SIGNAL(mouseLeaved()), this, SLOT(greyMatterOptionLeaved()));

    this->connect(this->whiteMatterOption, SIGNAL(mouseHover()), this, SLOT(whiteMatterOptionHovered()));
    this->connect(this->whiteMatterOption, SIGNAL(mouseLeftButtonClicked()), this, SLOT(whiteMatterOptionClicked()));
    this->connect(this->whiteMatterOption, SIGNAL(mouseLeftButtonReleased()), this, SLOT(whiteMatterOptionReleased()));
    this->connect(this->whiteMatterOption, SIGNAL(mouseLeaved()), this, SLOT(whiteMatterOptionLeaved()));

    this->connect(this->vesselOption, SIGNAL(mouseHover()), this, SLOT(vesselOptionHovered()));
    this->connect(this->vesselOption, SIGNAL(mouseLeftButtonClicked()), this, SLOT(vesselOptionClicked()));
    this->connect(this->vesselOption, SIGNAL(mouseLeftButtonReleased()), this, SLOT(vesselOptionReleased()));
    this->connect(this->vesselOption, SIGNAL(mouseLeaved()), this, SLOT(vesselOptionLeaved()));

    this->connect(this->interventionalRouteOption, SIGNAL(mouseHover()), this, SLOT(interventionalRouteOptionHovered()));
    this->connect(this->interventionalRouteOption, SIGNAL(mouseLeftButtonClicked()), this, SLOT(interventionalRouteOptionClicked()));
    this->connect(this->interventionalRouteOption, SIGNAL(mouseLeftButtonReleased()), this, SLOT(interventionalRouteOptionReleased()));
    this->connect(this->interventionalRouteOption, SIGNAL(mouseLeaved()), this, SLOT(interventionalRouteOptionLeaved()));

    this->connect(this->imageConfigurationButton, SIGNAL(mouseLeftButtonClicked()), this, SLOT(displayConfigurationBoard()));

    this->connect(this->sugeryEndnessButton, SIGNAL(clicked()), this, SLOT(close()));
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::updateCoords
//! \param obj
//!
void SurgeryPlanWindow::updateCoords(vtkObject* obj){
  // get interactor
  vtkRenderWindowInteractor* iren = vtkRenderWindowInteractor::SafeDownCast(obj);
  // get event position
  int event_pos[2];
  iren->GetEventPosition(event_pos);
  // update label
  QString str;
  str.sprintf("x=%d : y=%d", event_pos[0], event_pos[1]);
  qDebug()<<str;
  //coord->setText(str);
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::updatePatientMRAImageStatistics
//!
void SurgeryPlanWindow::updatePatientMRAImageStatistics(){
    /*
     QStringList statisticsList = medicalImageHandler->getHistogramStatisticsFrom(patientHandling->getMRAImage());

     grayscaleValueNumberLineEdit->setText(QString::number(patientHandling->getMRAImage()->GetNumberOfPoints()));
     grayscaleValueMaximumValueLineEdit->setText(statisticsList[0]);
     grayscaleValueMinimumValueLineEdit->setText(statisticsList[1]);
     grayscaleValueMeanLineEdit->setText(statisticsList[2]);
     grayscaleValueMedianLineEdit->setText(statisticsList[3]);
     grayscaleValueStandardDeviationLineEdit->setText(statisticsList[4]);
     this->patientHandling->setHistogramStatisticsList(statisticsList);

     this->patientHandling->setMaximumGrayscaleValue(grayscaleValueMaximumValueLineEdit->text());
     this->patientHandling->setMinimumGrayscaleValue(grayscaleValueMinimumValueLineEdit->text());*/
}


//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::initialRendering
//!
void SurgeryPlanWindow::initialRendering(){
    /*
    int max = this->patientHandling->getMaximumGrayscaleValue();
    int min = this->patientHandling->getMinimumGrayscaleValue();
    int interval = max - min;

    //! doit etre calibrer selons les differentes valeurs maximaux
    this->opacityTransferChoice->setChecked(true);
    this->generateNewOpacityPoint(min, 0.0);
    this->generateNewOpacityPoint(min + 0.3*interval, 0.0);
    this->generateNewOpacityPoint(min + 0.6*interval,1.8);
    this->generateNewOpacityPoint(max, 1.8);

    this->colorTransferChoice->setChecked(true);
    this->generateInitColorPoints(min, 4);
    this->generateInitColorPoints(min + 0.3*interval, 1);
    this->generateInitColorPoints(min + 0.5*interval, 2);
    this->generateInitColorPoints(min + 0.7*interval, 3);
    this->generateInitColorPoints(max, 4);

    this->gradientTransferChoice->setChecked(true);
    this->generateNewGradientPoint(min, 2);
    this->generateNewGradientPoint(min + 0.4*interval, 2.0);
    this->generateNewGradientPoint(min + 0.6*interval, 0.9);
    this->generateNewGradientPoint(min + 0.8*interval, 0.73);
    this->generateNewGradientPoint(max, 0.1);*/
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::transformationStateChanged
//!
void SurgeryPlanWindow::opacityTransformationStateChanged(bool state){
    transferOptionStates.opacityTransferOptionChoosen = state;
    if(transferOptionStates.opacityTransferOptionChoosen){
        this->updatePatientMRAImageTransformationCurves();
    }
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::ColorTransformationStateChanged
//! \param state
//!
void SurgeryPlanWindow::colorTransformationStateChanged(bool state){
    transferOptionStates.colorTransferOptionChoosen = state;
    if(transferOptionStates.colorTransferOptionChoosen){
        this->updatePatientMRAImageTransformationCurves();
    }
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::GradientTransformationStateChanged
//! \param state
//!
void SurgeryPlanWindow::gradientTransformationStateChanged(bool state){
    transferOptionStates.gradientTransferOptionChoosen = state;
    if(transferOptionStates.gradientTransferOptionChoosen){
        this->updatePatientMRAImageTransformationCurves();
    }
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::process
//!
void SurgeryPlanWindow::process(){

}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::updatePatientPersonelInformation
//!
void SurgeryPlanWindow::updatePatientPersonelInformation(){
    /*
    nameLineEdit->setText(this->patientHandling->getLastName() + ' ' + this->patientHandling->getFirstName());
    birthLineEdit->setText(this->patientHandling->getBirth());
    sexualLineEdit->setText(this->patientHandling->getSex());*/
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::updatePatientPersonelPhoto
//!
void SurgeryPlanWindow::updatePatientPersonelPhoto(){
    /*
    QString p = patientHandling->getPersonnelInfoPath() + patientHandling->getName() + ".png";
    photoWidget->setPixmap(QPixmap(p));
    photoWidget->setAutoFillBackground(true);
    photoWidget->setScaledContents(true);
    photoWidget->update();*/
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::updatePatientMRAImage
//!
void SurgeryPlanWindow::displayPatientMRAImage(){
     //display(this->patientHandling->getMRAImage());
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::updatePatientMRAImageHistogram
//!
void SurgeryPlanWindow::updatePatientMRAImageHistogram(){
    /*
    QVector<HistogramPoint*> frequencies = medicalImageHandler->getHistogramFrom(patientHandling->getMRAImage());

    int index = histogramPlottingBoard->addCurve("Histogram", "grayscale value", "", "cyan", 3);
    histogramPlottingBoard->doHistogramPlotting(index,frequencies);

    this->patientHandling->setGrayScaleValueFrequencies(frequencies);*/

}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::opacityPointTracking
//!
void SurgeryPlanWindow::opacityPointTracking(){
    /*
    //!---------
    if(!this->transformationPlottingBoard_Clicked){
            //! -------------
            int index = this->patientHandling->findPointInTolerentArea(this->transformationPlottingBoard_AbscissaValue, this->transformationPlottingBoard_OrdinateValue, "opacity");
            if(index  == -1){
                transformationPlottingBoard->setCursor(Qt::ArrowCursor);
            }
            else if(index>=0){
                transformationPlottingBoard->setCursor(Qt::PointingHandCursor);
                currentGrayScaleValueLineEdit->setText(QString::number(this->patientHandling->getGrayScaleValueByIndex(index, "opacity")));
                currentTransformationValueLineEdit->setText(QString::number(this->patientHandling->getOpacityValueByIndex(index)));
                currentTransformationValueLabel->setText("opacity: ");
            }
    }
    else{
            //! ---------------
            if(lockingTransformationPointIndex >= 0){
                this->transformationPlottingBoard->setCursor(Qt::PointingHandCursor);
                this->patientHandling->updateOpacityPoint(lockingTransformationPointIndex, int(this->transformationPlottingBoard_AbscissaValue),  this->transformationPlottingBoard_OrdinateValue);
                this->transformationPlottingBoard->doTransformationPlotting(0,this->patientHandling->getOpacityTransferPoints());
                this->updatePatientMRAImage();
            }
    }*/
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::colorPointTracking
//!
void SurgeryPlanWindow::colorPointTracking(){
    /*
    //!---------
    if(!this->transformationPlottingBoard_Clicked){
        //! In grayscale -> color mode choosen, while the mouse's pointer moving through the plotting board, fetch the current color while the mouse's  pointer over a color point
        int index = this->patientHandling->findPointInTolerentArea(this->transformationPlottingBoard_AbscissaValue, this->transformationPlottingBoard_OrdinateValue, "color");
        if(index  == -1){
            transformationPlottingBoard->setCursor(Qt::ArrowCursor);
        }
        else if(index>=0){
            transformationPlottingBoard->setCursor(Qt::PointingHandCursor);
            currentGrayScaleValueLineEdit->setText(QString::number(this->patientHandling->getGrayScaleValueByIndex(index, "color")));
            currentTransformationValueLineEdit->setText("("+QString::number(this->patientHandling->getRedValueByIndex(index)) +
                                                        ", " + QString::number(this->patientHandling->getGreenValueByIndex(index)) +
                                                        ", " + QString::number(this->patientHandling->getBlueValueByIndex(index)) + ")");

            currentTransformationValueLineEdit->setStyleSheet("background-color: rgb("+
                                                              QString::number(this->patientHandling->getRedValueByIndex(index)*255) +
                                                              ", " + QString::number(this->patientHandling->getGreenValueByIndex(index)*255) +
                                                              ", " + QString::number(this->patientHandling->getBlueValueByIndex(index)*255) + ")"
                                                              ";color:AliceBlue; border: 1px solid Gray;border-radius: 0px;padding: 0 8px;");
        }
    }
    else{
        //qDebug()<<lockingTransformationPointIndex;
        if(lockingTransformationPointIndex >= 0){
            this->transformationPlottingBoard->setCursor(Qt::PointingHandCursor);
            this->patientHandling->updateColorPoint(lockingTransformationPointIndex, int(this->transformationPlottingBoard_AbscissaValue));
            this->transformationPlottingBoard->doColorTransformationPlotting(this->patientHandling->getColorTransferPoints());
            this->updatePatientMRAImage();
        }
    }
    */
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::gradientPointTracking
//!
void SurgeryPlanWindow::gradientPointTracking(){
    /*
    //!---------
    if(!this->transformationPlottingBoard_Clicked){
        int index = this->patientHandling->findPointInTolerentArea(this->transformationPlottingBoard_AbscissaValue, this->transformationPlottingBoard_OrdinateValue, "gradient");
        if(index  == -1){
            transformationPlottingBoard->setCursor(Qt::ArrowCursor);
        }
        else if(index>=0){
            transformationPlottingBoard->setCursor(Qt::PointingHandCursor);
            currentGrayScaleValueLineEdit->setText(QString::number(this->patientHandling->getGrayScaleValueByIndex(index, "gradient")));
            currentTransformationValueLineEdit->setText(QString::number(this->patientHandling->getGradientValueByIndex(index)));
            currentTransformationValueLabel->setText("gradient: ");
        }
    }
    else{

        if(lockingTransformationPointIndex >= 0){
            this->transformationPlottingBoard->setCursor(Qt::PointingHandCursor);
            this->patientHandling->updateGradientPoint(lockingTransformationPointIndex, int(this->transformationPlottingBoard_AbscissaValue), this->transformationPlottingBoard_OrdinateValue);
            //this->transformationPlottingBoard->clearGraphs();
            this->transformationPlottingBoard->doTransformationPlotting(0,this->patientHandling->getGradientTransferPoints());
            this->updatePatientMRAImage();
        }
    }*/
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::tranformPointTracking
//!
void SurgeryPlanWindow::transformPointTracking(QMouseEvent*event){

    this->transformationPlottingBoard_AbscissaValue = transformationPlottingBoard->xAxis->pixelToCoord(event->pos().x());
    this->transformationPlottingBoard_OrdinateValue = transformationPlottingBoard->yAxis->pixelToCoord(event->pos().y());
    if(transferOptionStates.opacityTransferOptionChoosen){
       this->opacityPointTracking();
    }
    else if(transferOptionStates.colorTransferOptionChoosen){
       this->colorPointTracking();
    }
    else{
       this->gradientPointTracking();
    }
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::lockTargetPoint
//! \param event
//!
void SurgeryPlanWindow::lockTargetPoint(QMouseEvent* event){

    /*
    this->transformationPlottingBoard_AbscissaValue = transformationPlottingBoard->xAxis->pixelToCoord(event->pos().x());
    this->transformationPlottingBoard_OrdinateValue = transformationPlottingBoard->yAxis->pixelToCoord(event->pos().y());
    if(event->button() == Qt::LeftButton) {
        this->transformationPlottingBoard_Clicked = true;
        if(transferOptionStates.opacityTransferOptionChoosen){
            lockingTransformationPointIndex = this->patientHandling->findPointInTolerentArea(this->transformationPlottingBoard_AbscissaValue, this->transformationPlottingBoard_OrdinateValue,  "opacity");
        }
        else if(transferOptionStates.colorTransferOptionChoosen){
            lockingTransformationPointIndex = this->patientHandling->findPointInTolerentArea(this->transformationPlottingBoard_AbscissaValue, this->transformationPlottingBoard_OrdinateValue,  "color");
        }
        else{
            lockingTransformationPointIndex = this->patientHandling->findPointInTolerentArea(this->transformationPlottingBoard_AbscissaValue,  this->transformationPlottingBoard_OrdinateValue, "gradient");
        }
    }
    else{

    }*/
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::positioningTransformPoint
//! \param event
//!
void SurgeryPlanWindow::positioningTransformPoint(QMouseEvent* event){
    if(event->button() == Qt::LeftButton) {
        this->transformationPlottingBoard_AbscissaValue = transformationPlottingBoard->xAxis->pixelToCoord(event->pos().x());
        this->transformationPlottingBoard_OrdinateValue = transformationPlottingBoard->yAxis->pixelToCoord(event->pos().y());
        this->transformationPlottingBoard_Clicked = false;
        this->lockingTransformationPointIndex = -1;
    }
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::generateNewTransformationPoint
//! \param event
//!
void SurgeryPlanWindow::generateNewTransformationPoint(QMouseEvent* event){
    this->transformationPlottingBoard_AbscissaValue = transformationPlottingBoard->xAxis->pixelToCoord(event->pos().x());
    this->transformationPlottingBoard_OrdinateValue = transformationPlottingBoard->yAxis->pixelToCoord(event->pos().y());

    if(event->button() == Qt::LeftButton) {
        if(transferOptionStates.opacityTransferOptionChoosen){
            this->generateNewOpacityPoint(this->transformationPlottingBoard_AbscissaValue,  this->transformationPlottingBoard_OrdinateValue);
        }
        else if(transferOptionStates.colorTransferOptionChoosen){
            this->generateNewColorPoints(this->transformationPlottingBoard_AbscissaValue,  this->transformationPlottingBoard_OrdinateValue);
        }
        else{
            this->generateNewGradientPoint(this->transformationPlottingBoard_AbscissaValue,  this->transformationPlottingBoard_OrdinateValue);
        }
    }
    else{

    }



}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::generateNewOpacityPoint
//! \param abscissa
//! \param ordinate
//!
void SurgeryPlanWindow::generateNewOpacityPoint(double abscissa, double ordinate){
    /*
    TransferPoint*opacityPoint = new TransferPoint();
    opacityPoint->setAbscissaValue(abscissa);
    opacityPoint->setOrdinateValue(ordinate);
    this->patientHandling->setOpacityTransferPoint(opacityPoint);
    if(transferOptionStates.opacityTransferOptionChoosen){
        this->transformationPlottingBoard->doTransformationPlotting(0,this->patientHandling->getOpacityTransferPoints());
    }
    this->updatePatientMRAImage();*/
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::generateNewColorPoints
//! \param abscissa
//! \param ordinate
//!
void SurgeryPlanWindow::generateNewColorPoints(double abscissa, double ordinate){
    /*ColorPoint * colorPoint =  new ColorPoint();

    //TODO: display a widget for color chosen
    colorChooseWindow->exec();

    if(colorChooseWindow->colorChosen()){
        colorPoint->setAbscissaValue(abscissa);

        colorPoint->setRedValue(1.0*colorChooseWindow->getRedValue()/255);
        colorPoint->setGreenValue(1.0*colorChooseWindow->getGreenValue()/255);
        colorPoint->setBlueValue(1.0*colorChooseWindow->getBlueValue()/255);
        this->patientHandling->setColorTransferPoint(colorPoint);
        if(transferOptionStates.colorTransferOptionChoosen){
            this->transformationPlottingBoard->doColorTransformationPlotting(this->patientHandling->getColorTransferPoints());
        }
        this->updatePatientMRAImage();
    }*/

}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::generateNewGradientPoint
//! \param abscissa
//! \param ordinate
//!
void SurgeryPlanWindow::generateNewGradientPoint(double abscissa, double ordinate){
    /*TransferPoint*opacityPoint = new TransferPoint();
    opacityPoint->setAbscissaValue(abscissa);
    opacityPoint->setOrdinateValue(ordinate);
    this->patientHandling->setGradientTransferPoint(opacityPoint);
     if(transferOptionStates.gradientTransferOptionChoosen){
        this->transformationPlottingBoard->doTransformationPlotting(0,this->patientHandling->getGradientTransferPoints());
     }
    this->updatePatientMRAImage();*/
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief generateNewColorPoint
//! \param abscissa
//! \param ordinate
//! \param color
//!
void SurgeryPlanWindow::generateInitColorPoints(double abscissa, int colorCount){
    /*QColor *color =  new QColor(255, colorCount*51, 0);
    ColorPoint *colorPoint = new ColorPoint();
    colorPoint->setAbscissaValue(abscissa);
    colorPoint->setBlueValue(1.0*color->blue()/255);
    colorPoint->setRedValue(1.0*color->red()/255);
    colorPoint->setGreenValue(1.0*color->green()/255);
    this->patientHandling->setColorTransferPoint(colorPoint);
    if(transferOptionStates.colorTransferOptionChoosen){
        this->transformationPlottingBoard->doColorTransformationPlotting(this->patientHandling->getColorTransferPoints());
    }
   this->updatePatientMRAImage();*/
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::updatePatientMRAImage
//!
void SurgeryPlanWindow::updatePatientMRAImage(){
    /*if(transferOptionStates.opacityTransferOptionChoosen){
        this->opacityTransferFunction->RemoveAllPoints();
        QVector<TransferPoint*> points = this->patientHandling->getOpacityTransferPoints();
        for(unsigned char cpt = 0; cpt < points.size(); cpt++){
            this->opacityTransferFunction->AddPoint(int(points[cpt]->getAbscissaValue()), points[cpt]->getOrdinateValue());
        }
        this->volumeProperty->SetScalarOpacity(opacityTransferFunction);
    }
    else if(transferOptionStates.colorTransferOptionChoosen){
        this->colorTransferFunction->RemoveAllPoints();
        QVector<ColorPoint*> points = this->patientHandling->getColorTransferPoints();
        for(unsigned char cpt = 0; cpt < points.size(); cpt++){
            this->colorTransferFunction->AddRGBPoint(int(points[cpt]->getAbscissaValue()), points[cpt]->getRedValue(), points[cpt]->getGreenValue(), points[cpt]->getBlueValue());
        }
        volumeProperty->SetColor(colorTransferFunction);
    }
    else{
        this->gradientTransferFunction->RemoveAllPoints();
        QVector<TransferPoint*> points = this->patientHandling->getGradientTransferPoints();
        for(unsigned char cpt = 0; cpt < points.size(); cpt++){
            this->gradientTransferFunction->AddPoint(int(points[cpt]->getAbscissaValue()), points[cpt]->getOrdinateValue());
        }
        this->volumeProperty->SetGradientOpacity(gradientTransferFunction);
    }
    this->volume->SetProperty(volumeProperty);
    this->patientMRAImage->update();*/
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief CanalyserMainWindow::display
//! \param imgToBeDisplayed
//!
void SurgeryPlanWindow::display(vtkImageData *imgToBeDisplayed){
    /*this->volumeMapper->SetVolumeRayCastFunction(compositeFunction);
    this->volumeMapper->SetInputData(imgToBeDisplayed);

    this->volume->SetMapper(volumeMapper) ;
    //this->volume->SetProperty(volumeProperty);

    this->renderer->AddVolume(volume);
    this->renderer->SetBackground(58.0/255, 89.0/255, 92.0/255);

    this->renderWindow->AddRenderer(renderer);
    this->patientMRAImage->SetRenderWindow(renderWindow);

    QString humaBodyDataPath =this->patientHandling->getImageCenterPath()+"human_body.obj";
    vtkSmartPointer<vtkOBJReader> reader = vtkSmartPointer<vtkOBJReader>::New();
    reader->SetFileName(humaBodyDataPath.toLocal8Bit().data());
    reader->Update();
    vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputConnection(reader->GetOutputPort());
    vtkSmartPointer<vtkActor> actor =    vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);

    vtkOrientationMarkerWidget* axes = vtkOrientationMarkerWidget::New();
    axes->SetOrientationMarker(actor);
    vtkRenderWindowInteractor *iren = patientMRAImage->GetRenderWindow()->GetInteractor();
    axes->SetDefaultRenderer(this->renderer);
    axes->SetInteractor(iren);
    axes->EnabledOn();
    axes->InteractiveOn();

    this->renderer->ResetCamera();
    this->renderWindow->Render();
    this->patientMRAImage->update();*/

    /*
    //!------to be optimised..-----------------------------------------------
    vtkPiecewiseFunction*opacityTransferFunction=vtgradientTransferFunctionkPiecewiseFunction::New();//设置不透明度传递函数
    opacityTransferFunction->AddPoint(0, 0.0);
    opacityTransferFunction->AddPoint(800, 0.0);
    opacityTransferFunction->AddSegment (1500, 0.73, 1800, 0.9);
    opacityTransferFunction->AddPoint(2600, 2.0);

    vtkColorTransferFunction *colorTransferFunction = vtkColorTransferFunction::New();//设置颜色传递函数
    colorTransferFunction->AddRGBPoint(0, 0, 0, 0);//此处颜色设置为灰度值
    colorTransferFunction->AddRGBPoint((int)500*1985/1300, 0.1, 0.1, 0.1);
    colorTransferFunction->AddRGBPoint((int)600*1985/1300, 0.7, 0.7, 0.7);
    colorTransferFunction->AddRGBPoint((int)900*1985/1300, 0.85, 0.85, 0.85);
    colorTransferFunction->AddRGBPoint((int)1300*1985/1300, 1.0, 1.0, 1.0);

    vtkPiecewiseFunction *gradientTransferFunction = vtkPiecewiseFunction::New();//设置梯度传递函数
    gradientTransferFunction->AddPoint(0, 2.0);
    gradientTransferFunction->AddPoint((int)500*1985/1300, 2.0);
    gradientTransferFunction-> AddSegment ((int)600*1985/1300, 0.73, (int)900*1985/1300, 0.9);
    gradientTransferFunction->AddPoint((int)1300*1985/1300, 0.1);

    vtkVolumeProperty*volumeProperty=vtkVolumeProperty::New();//定义并设置相关体属性
    // volumeProperty->SetColor(colorTransferFunction);
    volumeProperty->SetScalarOpacity(opacityTransferFunction);
    // volumeProperty->SetGradientOpacity(gradientTransferFunction);
    //!--------

    //volumeMapper->SetVolumeRayCastFunction( compositeFunction );
    volumeMapper->SetInputData(imgToBeDisplayed);
    volume->SetMapper(volumeMapper);
    volume->SetProperty(volumeProperty);

    renderer->AddVolume(volume);
    renderer->SetBackground(58.0/255, 89.0/255, 92.0/255);//58,89,92
    renderWindow->AddRenderer(renderer);

    renderer->ResetCamera();

    patientMRAImage->SetRenderWindow(renderWindow);*/
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::updatePatientMRAImageTransformationCurves
//!
void SurgeryPlanWindow::updatePatientMRAImageTransformationCurves(){
    /*if(transformationPlottingBoard->getCurveNumber()>0){
        transformationPlottingBoard->clearGraphs();
    }

    transformationPlottingBoard->setAbscissaRange(this->patientHandling->getHistogramStatisticsList()[1].toInt(0,10), this->patientHandling->getHistogramStatisticsList()[0].toInt(0,10)*1.1 );

    if(transferOptionStates.opacityTransferOptionChoosen){
        currentTransformationValueLabel->setText("Opacity:  ");
        currentTransformationValueLineEdit->setStyleSheet("QLineEdit {background-color:transparent; color:AliceBlue; border: 1px solid Gray;border-radius: 0px;padding: 0 8px; selection-background-color: darkAliceBlue;}");
        transformationPlottingBoard->setOrdinateRange(-0.5, 2.5);
        transformationPlottingBoard->legendSetting(false);
        transferCurveIndex.opacityTransferCurveIndex = transformationPlottingBoard->addCurve("grayValue->opacity", "grayscale value", "", "gainsboro", 7);
        this->transformationPlottingBoard->doTransformationPlotting(0,this->patientHandling->getOpacityTransferPoints());
    }
    else if(transferOptionStates.colorTransferOptionChoosen){
        currentTransformationValueLabel->setText("Color:    ");
        transformationPlottingBoard->setOrdinateRange(-0.5, 2.5);
         transformationPlottingBoard->legendSetting(true);
        transferCurveIndex.colorTransferCurveIndex = transformationPlottingBoard->addCurve("grayValue->color", "grayscale value", "", "gainsboro", 7);
        this->transformationPlottingBoard->doColorTransformationPlotting(this->patientHandling->getColorTransferPoints());
    }
    else{
        currentTransformationValueLabel->setText("Gradient: ");
        currentTransformationValueLineEdit->setStyleSheet("QLineEdit {background-color:transparent; color:AliceBlue; border: 1px solid Gray;border-radius: 0px;padding: 0 8px; selection-background-color: darkAliceBlue;}");
        transformationPlottingBoard->legendSetting(false);
        transferCurveIndex.gradientTransferCurveIndex = transformationPlottingBoard->addCurve("grayValue->gradient", "grayscale value", "", "gainsboro", 7);
        this->transformationPlottingBoard->doTransformationPlotting(0,this->patientHandling->getGradientTransferPoints());
    }*/
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief Patient::removeCurveBy
//! \param index
//!
void SurgeryPlanWindow::removeCurveBy(int index){
    transformationPlottingBoard->removeGraph(index);
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::mainSplitterMoved
//! \param i
//! \param j
//!
void SurgeryPlanWindow::mainSplitterMoved(int i , int j){
    qDebug()<<i<<j;
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::constructControlBar
//!
void SurgeryPlanWindow::constructControlBar(){
    controlBar = new QFrame();
    controlBar->setFixedHeight(30);
    //controlBar->setStyleSheet("background-color: AliceBlue");

    controlBarLayout = new QHBoxLayout(controlBar);

    imageConfigurationButton = new CPushButton();
    imageConfigurationButton->move(0, 5);
    imageConfigurationButton->setIcon(QIcon(":/images/image_configuration.png"));
    imageConfigurationButton->setFixedSize(QSize(25, 25));
    imageConfigurationButton->setIconSize(QSize(23, 23));
    imageConfigurationButton->setFlat(true);

    imageUpdateButton = new CPushButton();
    imageUpdateButton->move(0, 5);
    imageUpdateButton->setIcon(QIcon(":/images/image_update.png"));
    imageUpdateButton->setFixedSize(QSize(25, 25));
    imageUpdateButton->setIconSize(QSize(23, 23));
    imageUpdateButton->setFlat(true);

    beginTherapyButton = new CPushButton();
    beginTherapyButton->move(0, 5);
    beginTherapyButton->setIcon(QIcon(":/images/begin_therapy.png"));
    beginTherapyButton->setFixedSize(QSize(30, 30));
    beginTherapyButton->setIconSize(QSize(23, 23));
    beginTherapyButton->setFlat(true);
    spacer_controlbar = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    controlBarLayout->addWidget(imageConfigurationButton);
    controlBarLayout->addWidget(imageUpdateButton);
    controlBarLayout->addItem(spacer_controlbar);
    controlBarLayout->addWidget(beginTherapyButton);
    controlBarLayout->setSpacing(0);
    controlBarLayout->setMargin(0);
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! Patient's information on the left, and doctor's information on the right;
//! And the control bar contains series of push button to manage the therapy.
//!
//! \brief SurgeryPlanWindow::regroupAllComponents
//!
void SurgeryPlanWindow::regroupAllComponents(){

    mainSplitter = new QSplitter();
    mainSplitter->setStyleSheet("QSplitter::handle {background-color: AliceBlue;}");
    mainSplitter->addWidget(patientInformationWidget);
    //mainSplitter->addWidget(doctorInformationWidget);
    //mainSplitter->handle(1)->installEventFilter(this);
    //mainSplitter->setHandleWidth(1);

    this->constructControlBar();

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(mainSplitter,0,0);
    mainLayout->addWidget(controlBar,1,0);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(1, 1, 2, 0);
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! Initialisation des composant necessaire pour l'affichage des images tridimensionelle
//!
//! \brief SurgeryPlanWindow::initialisation
//!
void SurgeryPlanWindow::initialisation(){
    /*volumeMapper = vtkVolumeRayCastMapper::New();
    compositeFunction = vtkVolumeRayCastCompositeFunction::New();
    volume = vtkVolume::New();
    renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
    renderer = vtkSmartPointer<vtkRenderer>::New();

    opacityTransferFunction=vtkPiecewiseFunction::New();
    gradientTransferFunction = vtkPiecewiseFunction::New();
    colorTransferFunction = vtkColorTransferFunction::New();

    volumeProperty=vtkVolumeProperty::New();

    imageOptionStates.originalOptionState = false;
    imageOptionStates.transparentBrainOptionState = false;
    imageOptionStates.greyMatterOptionState = false;
    imageOptionStates.whiteMatterOptionState = false;
    imageOptionStates.vesselOptionState = false;
    imageOptionStates.interventionalRouteOptionState = false;

    transformationPlottingBoard_Clicked = false;
    lockingTransformationPointIndex = -1;

    this->transformationPlottingBoard_AbscissaValue = 0.0;
    this->transformationPlottingBoard_OrdinateValue = 0.0;

    SurgeryPlanWindowConfigurationBoard = new SurgeryPlanWindowConfigurationBoard(this->patientHandling, this->medicalImageHandler);
    this->colorChooseWindow = new ColorChooseWindow();*/
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! Construct the widget which contains all the information about the patient in order to prepare the therapy
//!
//! \brief SurgeryPlanWindow::constructPatientInformationWidget
//!
void SurgeryPlanWindow::constructPatientInformationWidget(){
    patientInformationWidget = new QFrame();
    //patientInformationWidget->setStyleSheet("background-color: AliceBlue");
    patientInformationLayout = new QVBoxLayout(patientInformationWidget);

    patientTitleBar = new QFrame();
    patientTitleBar->setFixedSize(640, 100);

    briefWidget = new QWidget();

    briefWidget->setFixedSize(150, 100);
    patientTitleLabel = new QLabel("Patient's Information");
    patientTitleLabel->setStyleSheet("color: AliceBlue");
    patientTitleLabel->setFont(QFont("Segoe UI", 11, QFont::DemiBold, true));
    patientTitleLabel->setFixedSize(250, 100);

    photoWidget = new QLabel();
    photoWidget->setFixedSize(75, 100);
    spacer_1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    spacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    patientTitleBarLayout = new QHBoxLayout(patientTitleBar);
    patientTitleBarLayout->addWidget(briefWidget);
    patientTitleBarLayout->addItem(spacer_1);
    patientTitleBarLayout->addWidget(patientTitleLabel);
    patientTitleBarLayout->addItem(spacer_2);
    patientTitleBarLayout->addWidget(photoWidget);
    patientTitleBarLayout->setSpacing(0);
    patientTitleBarLayout->setMargin(2);
    // TODO,.......

    patientPersonelInformationBar = new QFrame();
    patientPersonelInformationBar->setFixedHeight(30);
    patientPersonelInformationBarLayout = new QHBoxLayout(patientPersonelInformationBar);
    nameLabel =  new QLabel("Name: ");
    birthLabel = new QLabel("Birth: ");
    sexualLabel = new QLabel("Sex: ");
    medicalDateLabel =  new QLabel("Medical Date: ");
    nameLineEdit =  new QLineEdit();
    birthLineEdit =  new QLineEdit();
    sexualLineEdit =  new QLineEdit();
    medicalDateLineEdit = new QLineEdit();

    nameLabel->setFont(QFont("Segoe UI", 8, QFont::AnyStyle, false));
    birthLabel->setFont(QFont("Segoe UI", 8, QFont::AnyStyle, false));
    sexualLabel->setFont(QFont("Segoe UI", 8, QFont::AnyStyle, false));
    medicalDateLabel->setFont(QFont("Segoe UI", 8, QFont::AnyStyle, false));
    nameLineEdit->setFont(QFont("Segoe UI", 8, QFont::AnyStyle, true));
    birthLineEdit->setFont(QFont("Segoe UI", 8, QFont::AnyStyle, true));
    sexualLineEdit->setFont(QFont("Segoe UI", 8, QFont::AnyStyle, true));
    medicalDateLineEdit->setFont(QFont("Segoe UI", 8, QFont::AnyStyle, true));

    nameLabel->setStyleSheet("color: AliceBlue");
    birthLabel->setStyleSheet("color: AliceBlue");
    sexualLabel->setStyleSheet("color: AliceBlue");
    medicalDateLabel->setStyleSheet("color: AliceBlue");

    nameLineEdit->setStyleSheet("QLineEdit {background-color:transparent; color:AliceBlue; border: 1px solid Gray;border-radius: 0px;padding: 0 8px; selection-background-color: darkAliceBlue; }");
    birthLineEdit->setStyleSheet("QLineEdit {background-color:transparent; color:AliceBlue; border: 1px solid Gray;border-radius: 0px;padding: 0 8px;selection-background-color: darkAliceBlue; }");
    sexualLineEdit->setStyleSheet("QLineEdit {background-color:transparent; color:AliceBlue; border: 1px solid Gray;border-radius: 0px;padding: 0 8px; selection-background-color: darkAliceBlue; }");
    medicalDateLineEdit->setStyleSheet("QLineEdit {background-color:transparent; color:AliceBlue; border: 1px solid Gray;border-radius: 0px;padding: 0 8px; selection-background-color: darkAliceBlue; }");

    nameLineEdit->setReadOnly(true);
    birthLineEdit->setReadOnly(true);
    sexualLineEdit->setReadOnly(true);
    medicalDateLineEdit->setReadOnly(true);

    patientPersonelInformationBarLayout->addWidget(nameLabel);
    patientPersonelInformationBarLayout->addWidget(nameLineEdit);
    patientPersonelInformationBarLayout->addWidget(birthLabel);
    patientPersonelInformationBarLayout->addWidget(birthLineEdit);
    patientPersonelInformationBarLayout->addWidget(sexualLabel);
    patientPersonelInformationBarLayout->addWidget(sexualLineEdit);
    patientPersonelInformationBarLayout->addWidget(medicalDateLabel);
    patientPersonelInformationBarLayout->addWidget(medicalDateLineEdit);
    patientPersonelInformationBarLayout->setSpacing(5);
    patientPersonelInformationBarLayout->setMargin(2);

    patientClinicalWidgetsContainer = new QFrame();
    patientClinicalWidgetsContainerLayout = new QHBoxLayout(patientClinicalWidgetsContainer);

    patientMRAImageOptionWidget =  new QWidget();

    patientMRAImageOptionWidget->setFixedWidth(450);
    patientMRAImageOptionWidgetLayout = new QVBoxLayout(patientMRAImageOptionWidget);

    patientImageInformationWidgetSpace = new QSpacerItem(0,10, QSizePolicy::Expanding, QSizePolicy::Expanding);
    sugeryEndnessButton = new QPushButton("X");

    patientImageInformationWidget = new QWidget();
    patientImageInformationWidget->setStyleSheet("background-color: BLUE");
    patientImageInformationWidget->setFixedHeight(40);
    patientImageInformationWidgetLayout = new QHBoxLayout(patientImageInformationWidget);
    patientImageInformationWidgetLayout->addWidget(sugeryEndnessButton);
    patientImageInformationWidgetLayout->addItem(patientImageInformationWidgetSpace);

    histogramGroupBox = new QGroupBox();
    histogramGroupBox->setStyleSheet("QGroupBox{background-color:transparent; color: Aliceblue; border: 1px solid gray; border-radius: 5px;margin-top: 1ex;} ");
    histogramGroupBox->setTitle("Image Statistics");
    histogramGroupBox->setFont(QFont("Segoe UI", 8, QFont::AnyStyle, true));

    histogramGroupBoxLayout = new QVBoxLayout(histogramGroupBox);

    imageStatisticsWidget = new QWidget();
    imageStatisticsWidget->setFixedHeight(140);
    imageStatisticsWidgetLayout = new QGridLayout(imageStatisticsWidget);

    grayscaleValueNumberLabel = new QLabel("Total Number: ");
    grayscaleValueMeanLabel = new QLabel("Mean: ");
    grayscaleValueMedianLabel = new QLabel("Median: ");
    grayscaleValueMaximumValueLabel = new QLabel("Maximum Value: ");
    grayscaleValueMinimumValueLabel = new QLabel("Minimum Value: ");
    grayscaleValueStandardDeviationLabel = new QLabel("Standard Deviation: ");

    grayscaleValueNumberLineEdit = new QLineEdit();
    grayscaleValueMeanLineEdit = new QLineEdit();
    grayscaleValueMedianLineEdit = new QLineEdit();
    grayscaleValueMaximumValueLineEdit = new QLineEdit();
    grayscaleValueMinimumValueLineEdit = new QLineEdit();
    grayscaleValueStandardDeviationLineEdit = new QLineEdit();

    grayscaleValueNumberLabel->setFont(QFont("Segoe UI", 8, QFont::AnyStyle, false));
    grayscaleValueMeanLabel->setFont(QFont("Segoe UI", 8, QFont::AnyStyle, false));
    grayscaleValueMedianLabel->setFont(QFont("Segoe UI", 8, QFont::AnyStyle, false));
    grayscaleValueMaximumValueLabel->setFont(QFont("Segoe UI", 8, QFont::AnyStyle, false));
    grayscaleValueMinimumValueLabel->setFont(QFont("Segoe UI", 8, QFont::AnyStyle, false));
    grayscaleValueStandardDeviationLabel->setFont(QFont("Segoe UI", 8, QFont::AnyStyle, false));

    grayscaleValueNumberLineEdit->setFont(QFont("Segoe UI", 8, QFont::AnyStyle, true));
    grayscaleValueMeanLineEdit->setFont(QFont("Segoe UI", 8, QFont::AnyStyle, true));
    grayscaleValueMedianLineEdit->setFont(QFont("Segoe UI", 8, QFont::AnyStyle, true));
    grayscaleValueMaximumValueLineEdit->setFont(QFont("Segoe UI", 8, QFont::AnyStyle, true));
    grayscaleValueMinimumValueLineEdit->setFont(QFont("Segoe UI", 8, QFont::AnyStyle, true));
    grayscaleValueStandardDeviationLineEdit->setFont(QFont("Segoe UI", 8, QFont::AnyStyle, true));

    grayscaleValueNumberLineEdit->setReadOnly(true);
    grayscaleValueMeanLineEdit->setReadOnly(true);
    grayscaleValueMedianLineEdit->setReadOnly(true);
    grayscaleValueMaximumValueLineEdit->setReadOnly(true);
    grayscaleValueMinimumValueLineEdit->setReadOnly(true);
    grayscaleValueStandardDeviationLineEdit->setReadOnly(true);

    grayscaleValueNumberLabel->setStyleSheet("color: AliceBlue");
    grayscaleValueMeanLabel->setStyleSheet("color: AliceBlue");
    grayscaleValueMedianLabel->setStyleSheet("color: AliceBlue");
    grayscaleValueMaximumValueLabel->setStyleSheet("color: AliceBlue");
    grayscaleValueMinimumValueLabel->setStyleSheet("color: AliceBlue");
    grayscaleValueStandardDeviationLabel->setStyleSheet("color: AliceBlue");

    grayscaleValueNumberLineEdit->setStyleSheet("QLineEdit {background-color:transparent; color:AliceBlue; border: 1px solid Gray;border-radius: 0px;padding: 0 8px; selection-background-color: darkAliceBlue;}");
    grayscaleValueMeanLineEdit->setStyleSheet("QLineEdit {background-color:transparent; color:AliceBlue; border: 1px solid Gray;border-radius: 0px;padding: 0 8px; selection-background-color: darkAliceBlue; }");
    grayscaleValueMedianLineEdit->setStyleSheet("QLineEdit {background-color:transparent; color:AliceBlue; border: 1px solid Gray;border-radius: 0px;padding: 0 8px; selection-background-color: darkAliceBlue; }");
    grayscaleValueMaximumValueLineEdit->setStyleSheet("QLineEdit {background-color:transparent; color:AliceBlue; border: 1px solid Gray;border-radius: 0px;padding: 0 8px; selection-background-color: darkAliceBlue; }");
    grayscaleValueMinimumValueLineEdit->setStyleSheet("QLineEdit {background-color:transparent; color:AliceBlue; border: 1px solid Gray;border-radius: 0px;padding: 0 8px; selection-background-color: darkAliceBlue; }");
    grayscaleValueStandardDeviationLineEdit->setStyleSheet("QLineEdit {background-color:transparent; color:AliceBlue; border: 1px solid Gray;border-radius: 0px;padding: 0 8px; selection-background-color: darkAliceBlue; }");

    imageStatisticsWidgetLayout->addWidget(grayscaleValueNumberLabel, 0, 0);
    imageStatisticsWidgetLayout->addWidget(grayscaleValueNumberLineEdit, 0, 1);
    imageStatisticsWidgetLayout->addWidget(grayscaleValueMaximumValueLabel, 1, 0);
    imageStatisticsWidgetLayout->addWidget(grayscaleValueMaximumValueLineEdit, 1, 1);
    imageStatisticsWidgetLayout->addWidget(grayscaleValueMinimumValueLabel, 2, 0);
    imageStatisticsWidgetLayout->addWidget(grayscaleValueMinimumValueLineEdit, 2, 1);
    imageStatisticsWidgetLayout->addWidget(grayscaleValueMeanLabel, 3, 0);
    imageStatisticsWidgetLayout->addWidget(grayscaleValueMeanLineEdit, 3, 1);
    imageStatisticsWidgetLayout->addWidget(grayscaleValueMedianLabel, 4, 0);
    imageStatisticsWidgetLayout->addWidget(grayscaleValueMedianLineEdit, 4, 1);
    imageStatisticsWidgetLayout->addWidget(grayscaleValueStandardDeviationLabel, 5, 0);
    imageStatisticsWidgetLayout->addWidget(grayscaleValueStandardDeviationLineEdit, 5, 1);
    imageStatisticsWidgetLayout->setSpacing(0);

    histogramPlottingBoard = new PlottingBoard();
    histogramPlottingBoard->setFixedHeight(200);
    histogramPlottingBoard->legendSetting(true);
    histogramGroupBoxLayout->addWidget(imageStatisticsWidget);
    histogramGroupBoxLayout->addWidget(histogramPlottingBoard);

    histogramGroupBoxLayout->setSpacing(0);
    histogramGroupBoxLayout->setContentsMargins(0,15,0,0);

    //!-------------------------------------
    volumeRenderingGroupBox = new QGroupBox();
    volumeRenderingGroupBox->setStyleSheet("QGroupBox{background-color:transparent; color: Aliceblue; border: 1px solid gray; border-radius: 5px;margin-top: 1ex;} ");
    volumeRenderingGroupBox->setTitle("Volume Rendering");
    volumeRenderingGroupBox->setFont(QFont("Segoe UI", 8, QFont::AnyStyle, true));
    volumeRenderingGroupBoxLayout = new QVBoxLayout(volumeRenderingGroupBox);

    transferChoicesWidget = new QWidget();
    transferChoicesLayout = new QHBoxLayout(transferChoicesWidget);

    transferChoiceLabel = new QLabel("transfer grayscale value to: ");
    opacityTransferChoice = new QRadioButton("opacity");
    colorTransferChoice = new QRadioButton("color");
    gradientTransferChoice = new QRadioButton("gradient");
    transferChoicesWidgetSpacer = new QSpacerItem(0,10, QSizePolicy::Expanding, QSizePolicy::Expanding);

    opacityTransferChoice->setFixedWidth(70);
    colorTransferChoice->setFixedWidth(60);
    gradientTransferChoice->setFixedWidth(70);

    transferChoiceLabel->setStyleSheet("color: AliceBlue");
    opacityTransferChoice->setStyleSheet("color: AliceBlue");
    colorTransferChoice->setStyleSheet("color: AliceBlue");
    gradientTransferChoice->setStyleSheet("color: AliceBlue");

    transferChoiceLabel->setFont(QFont("Segoe UI", 8, QFont::AnyStyle, true));
    opacityTransferChoice->setFont(QFont("Segoe UI", 8, QFont::AnyStyle, true));
    colorTransferChoice->setFont(QFont("Segoe UI", 8, QFont::AnyStyle, true));
    gradientTransferChoice->setFont(QFont("Segoe UI", 8, QFont::AnyStyle, true));

    transferChoicesLayout->addWidget(transferChoiceLabel);
    transferChoicesLayout->addWidget(opacityTransferChoice);
    transferChoicesLayout->addWidget(colorTransferChoice);
    transferChoicesLayout->addWidget(gradientTransferChoice);
    transferChoicesLayout->addItem(transferChoicesWidgetSpacer);
    transferChoicesLayout->setSpacing(0);

    transformationPlottingBoard = new PlottingBoard();

    transformationIndicationBar = new QWidget();
    transformationIndicationBarLayout = new QHBoxLayout(transformationIndicationBar);
    currentGrayScaleValueLabel = new QLabel("grascale value: ");
    currentTransformationValueLabel = new QLabel("opacity: ");
    transformationButton = new CPushButton(this);

    transformationButton->setIcon(QIcon(":/images/transformation.png"));
    transformationButton->setFixedSize(QSize(60, 30));
    transformationButton->setIconSize(QSize(53, 23));
    transformationButton->setFlat(true);

    currentGrayScaleValueLineEdit = new QLineEdit();
    currentTransformationValueLineEdit = new QLineEdit();

    currentGrayScaleValueLabel->setStyleSheet("color: AliceBlue");
    currentTransformationValueLabel->setStyleSheet("color: AliceBlue");

    currentGrayScaleValueLabel->setFont(QFont("Segoe UI", 8, QFont::AnyStyle, true));
    currentTransformationValueLabel->setFont(QFont("Segoe UI", 8, QFont::AnyStyle, true));

    grayscaleValueNumberLineEdit->setFont(QFont("Segoe UI", 8, QFont::AnyStyle, true));
    grayscaleValueMeanLineEdit->setFont(QFont("Segoe UI", 8, QFont::AnyStyle, true));
    grayscaleValueMedianLineEdit->setFont(QFont("Segoe UI", 8, QFont::AnyStyle, true));
    grayscaleValueMaximumValueLineEdit->setFont(QFont("Segoe UI", 8, QFont::AnyStyle, true));
    grayscaleValueMinimumValueLineEdit->setFont(QFont("Segoe UI", 8, QFont::AnyStyle, true));
    grayscaleValueStandardDeviationLineEdit->setFont(QFont("Segoe UI", 8, QFont::AnyStyle, true));

    currentGrayScaleValueLineEdit->setReadOnly(true);
    currentTransformationValueLineEdit->setReadOnly(true);

    currentGrayScaleValueLineEdit->setStyleSheet("QLineEdit {background-color:transparent; color:AliceBlue; border: 1px solid Gray;border-radius: 0px;padding: 0 8px; selection-background-color: darkAliceBlue;}");
    currentTransformationValueLineEdit->setStyleSheet("QLineEdit {background-color:transparent; color:AliceBlue; border: 1px solid Gray;border-radius: 0px;padding: 0 8px; selection-background-color: darkAliceBlue;}");

    transformationIndicationBarLayout->addWidget(currentGrayScaleValueLabel);
    transformationIndicationBarLayout->addWidget(currentGrayScaleValueLineEdit);
    transformationIndicationBarLayout->addWidget(transformationButton);
    transformationIndicationBarLayout->addWidget(currentTransformationValueLabel);
    transformationIndicationBarLayout->addWidget(currentTransformationValueLineEdit);
    transformationIndicationBarLayout->setSpacing(0);

    transformationPlottingBoard->setFixedHeight(200);
    transformationPlottingBoard->legendSetting(false);

    volumeRenderingGroupBoxLayout->addWidget(transferChoicesWidget);
    volumeRenderingGroupBoxLayout->addWidget(transformationPlottingBoard);
    volumeRenderingGroupBoxLayout->addWidget(transformationIndicationBar);

    volumeRenderingGroupBoxLayout->setSpacing(0);
    //!-------------------------------------

    patientMRAImageOptionWidgetSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    patientMRAImageOptionWidgetLayout->addWidget(patientImageInformationWidget);
    patientMRAImageOptionWidgetLayout->addWidget(histogramGroupBox);
    patientMRAImageOptionWidgetLayout->addWidget(volumeRenderingGroupBox);
    patientMRAImageOptionWidgetLayout->addItem(patientMRAImageOptionWidgetSpacer);

    patientMRAImageOptionWidgetLayout->setSpacing(0);
    patientMRAImageOptionWidgetLayout->setMargin(0);

    patientMRAImageConfigurationWidget =  new QWidget();
    patientMRAImageConfigurationWidgetLayout = new QVBoxLayout(patientMRAImageConfigurationWidget);
    patientMRAImageOption = new QWidget();

    patientMRAImageOptionLayout = new QHBoxLayout(patientMRAImageOption);

    originalOption = new CPushButton();
    originalOption->setText("Original Image");
    originalOption->setFixedSize(QSize(150, 30));
    originalOption->setFixedWidth(150);
    originalOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: grey  "  );
    originalOption->setFlat(true);
    originalOption->setFont(QFont("Segoe UI",10, QFont::AnyStyle, true));

    transparentBrainOption = new CPushButton();
    transparentBrainOption->setText("Transparent Brain");
    transparentBrainOption->setFixedSize(QSize(150, 30));
    transparentBrainOption->setFixedWidth(150);
    transparentBrainOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: grey  "  );
    transparentBrainOption->setFlat(true);
    transparentBrainOption->setFont(QFont("Segoe UI",10, QFont::AnyStyle, true));

    greyMatterOption = new CPushButton();
    greyMatterOption->setText("White Matter");
    greyMatterOption->setFixedSize(QSize(150, 30));
    greyMatterOption->setFixedWidth(150);
    greyMatterOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: grey  "  );
    greyMatterOption->setFlat(true);
    greyMatterOption->setFont(QFont("Segoe UI", 10, QFont::AnyStyle, true));

    whiteMatterOption = new CPushButton();
    whiteMatterOption->setText("Grey Matter");
    whiteMatterOption->setFixedSize(QSize(150, 30));
    whiteMatterOption->setFixedWidth(150);
    whiteMatterOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: grey  "  );
    whiteMatterOption->setFlat(true);
    whiteMatterOption->setFont(QFont("Segoe UI", 10, QFont::AnyStyle, true));

    vesselOption = new CPushButton();
    vesselOption->setText("Vessel Tree");
    vesselOption->setFixedSize(QSize(150, 30));
    vesselOption->setFixedWidth(150);
    vesselOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: grey  "  );
    vesselOption->setFlat(true);
    vesselOption->setFont(QFont("Segoe UI", 10, QFont::AnyStyle, true));

    interventionalRouteOption = new CPushButton();
    interventionalRouteOption->setText("Interventional Route");
    interventionalRouteOption->setFixedSize(QSize(150, 30));
    interventionalRouteOption->setFixedWidth(150);
    interventionalRouteOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: grey  "  );
    interventionalRouteOption->setFlat(true);
    interventionalRouteOption->setFont(QFont("Segoe UI", 10, QFont::AnyStyle, true));

    patientMRAImageOptionLabel = new QLabel();
    patientMRAImageOptionLabel->setFixedWidth(320);

    patientMRAImageOptionLayout->addWidget(originalOption);
    patientMRAImageOptionLayout->addWidget(transparentBrainOption);
    patientMRAImageOptionLayout->addWidget(greyMatterOption);
    patientMRAImageOptionLayout->addWidget(whiteMatterOption);
    patientMRAImageOptionLayout->addWidget(vesselOption);
    patientMRAImageOptionLayout->addWidget(interventionalRouteOption);
    patientMRAImageOptionLayout->addWidget(patientMRAImageOptionLabel);
    patientMRAImageOptionLayout->setSpacing(1);
    patientMRAImageOptionLayout->setMargin(0);

    patientMRAImageOption->setFixedHeight(40);

    patientMRAImageWidget = new QWidget();
    patientMRAImageWidgetLayout = new QHBoxLayout(patientMRAImageWidget);
    patientMRAImage = new QVTKWidget();

    //patientMRAImageManipulation = new QWidget();
    patientMRAImageWidgetLayout->addWidget(patientMRAImage);
    patientMRAImageWidgetLayout->setSpacing(0);
    patientMRAImageWidgetLayout->setMargin(0);

    patientMRAImageConfigurationWidgetLayout->addWidget(patientMRAImageOption);
    patientMRAImageConfigurationWidgetLayout->addWidget(patientMRAImageWidget);
    patientMRAImageConfigurationWidgetLayout->setSpacing(0);
    patientMRAImageConfigurationWidgetLayout->setMargin(0);

    patientClinicalWidgetsContainerLayout->addWidget(patientMRAImageOptionWidget);
    patientClinicalWidgetsContainerLayout->addWidget(patientMRAImageConfigurationWidget);
    patientClinicalWidgetsContainerLayout->setSpacing(2);
    patientClinicalWidgetsContainerLayout->setMargin(2);

    //patientInformationLayout->addWidget(patientTitleBar);
    //patientInformationLayout->addWidget(patientPersonelInformationBar);
    patientInformationLayout->addWidget(patientClinicalWidgetsContainer);
    patientInformationLayout->setSpacing(0);
    patientInformationLayout->setMargin(0);
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief CanalyserMainWindow::createRandomVtkImageData
//!
void SurgeryPlanWindow::createRandomVtkImageData(){
    vtkSmartPointer<vtkImageData> image = vtkSmartPointer<vtkImageData>::New();
    image->SetDimensions(448,448,128);
    image->SetSpacing(0.5, 0.5, 0.8);
    image->AllocateScalars(VTK_UNSIGNED_SHORT,1);

    int dims[3];
    image->GetDimensions(dims);
    for(int i = 0; i < dims[0]; i++){
      for(int j = 0; j < dims[1]; j++){
          for(int k = 0; k < dims[2]; k++){
            unsigned short* pixel = static_cast<unsigned short*>(image->GetScalarPointer(i,j,k));
            *pixel = 2000;
          }
        }
      }
     display(image);
}


//--------------------------------------------------------------------------------------------------------------------------------
//!
//!  the widget which contains all the information about the patient in order to prepare the therapy
//!
//! \brief SurgeryPlanWindow::constructDoctorInformationWidget
//!
void SurgeryPlanWindow::constructDoctorInformationWidget(){
    doctorInformationWidget =  new QFrame();
    doctorInformationWidget->setFixedWidth(400);
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::originalOptionHovered
//!
void SurgeryPlanWindow::originalOptionHovered(){
    originalOption->setStyleSheet("border: 1px solid grey;  border-radius: 0px; background-color: gainsboro;  min-width: 0px; color: AliceBlue");
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::originalOptionClicked
//!
void SurgeryPlanWindow::originalOptionClicked(){
    originalOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: AliceBlue  "  );
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::originalOptionReleased
//!
void SurgeryPlanWindow::originalOptionReleased(){

    originalOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: grey;  min-width: 0px; color: AliceBlue  "  );
    transparentBrainOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: grey  "  );
    greyMatterOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: grey  "  );
    whiteMatterOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: grey  "  );
    vesselOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: grey  "  );
    interventionalRouteOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: grey  "  );

    originalOption->setFont(QFont("Segoe UI",10, QFont::DemiBold, true));
    transparentBrainOption->setFont(QFont("Segoe UI",10, QFont::AnyStyle, true));
    greyMatterOption->setFont(QFont("Segoe UI", 10, QFont::AnyStyle, true));
    whiteMatterOption->setFont(QFont("Segoe UI", 10, QFont::AnyStyle, true));
    vesselOption->setFont(QFont("Segoe UI", 10, QFont::AnyStyle, true));
    interventionalRouteOption->setFont(QFont("Segoe UI", 10, QFont::AnyStyle, true));

    imageOptionStates.originalOptionState = true;
    imageOptionStates.transparentBrainOptionState = false;
    imageOptionStates.greyMatterOptionState = false;
    imageOptionStates.whiteMatterOptionState = false;
    imageOptionStates.vesselOptionState = false;
    imageOptionStates.interventionalRouteOptionState = false;
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::originalOptionLeaved
//!
void SurgeryPlanWindow::originalOptionLeaved(){
    if(imageOptionStates.originalOptionState){
        originalOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: grey;  min-width: 0px; color: AliceBlue");
    }
    else{
        originalOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: grey " );
    }

}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::transparentBrainOptionHovered
//!
void SurgeryPlanWindow::transparentBrainOptionHovered(){
    transparentBrainOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: gainsboro;  min-width: 0px; color: AliceBlue  "  );
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::transparentBrainOptionClicked
//!
void SurgeryPlanWindow::transparentBrainOptionClicked(){
    transparentBrainOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: AliceBlue  "  );
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::transparentBrainOptionReleased
//!
void SurgeryPlanWindow::transparentBrainOptionReleased(){
    originalOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: grey  "  );
    transparentBrainOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: grey;  min-width: 0px; color: aliceblue  "  );
    greyMatterOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: grey  "  );
    whiteMatterOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: grey  "  );
    vesselOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: grey  "  );
    interventionalRouteOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: grey  "  );

    originalOption->setFont(QFont("Segoe UI",10, QFont::AnyStyle, true));
    transparentBrainOption->setFont(QFont("Segoe UI",10, QFont::DemiBold, true));
    greyMatterOption->setFont(QFont("Segoe UI", 10, QFont::AnyStyle, true));
    whiteMatterOption->setFont(QFont("Segoe UI", 10, QFont::AnyStyle, true));
    vesselOption->setFont(QFont("Segoe UI", 10, QFont::AnyStyle, true));
    interventionalRouteOption->setFont(QFont("Segoe UI", 10, QFont::AnyStyle, true));

    imageOptionStates.originalOptionState = false;
    imageOptionStates.transparentBrainOptionState = true;
    imageOptionStates.greyMatterOptionState = false;
    imageOptionStates.whiteMatterOptionState = false;
    imageOptionStates.vesselOptionState = false;
    imageOptionStates.interventionalRouteOptionState = false;
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::transparentBrainOptionLeaved
//!
void SurgeryPlanWindow::transparentBrainOptionLeaved(){
    if(imageOptionStates.transparentBrainOptionState){
        transparentBrainOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: grey;  min-width: 0px; color: AliceBlue");
    }
    else{
        transparentBrainOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: grey " );
    }
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::greyMatterOptionHovered
//!
void SurgeryPlanWindow::greyMatterOptionHovered(){
    greyMatterOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: gainsboro;  min-width: 0px; color: AliceBlue  "  );
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::greyMatterOptionClicked
//!
void SurgeryPlanWindow::greyMatterOptionClicked(){
    greyMatterOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: AliceBlue  "  );

}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::greyMatterOptionReleased
//!
void SurgeryPlanWindow::greyMatterOptionReleased(){
    originalOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: grey  "  );
    transparentBrainOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: grey  "  );
    greyMatterOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: grey;  min-width: 0px; color: aliceblue  "  );
    whiteMatterOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: grey  "  );
    vesselOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: grey  "  );
    interventionalRouteOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: grey  "  );

    originalOption->setFont(QFont("Segoe UI",10, QFont::AnyStyle, true));
    transparentBrainOption->setFont(QFont("Segoe UI",10, QFont::AnyStyle, true));
    greyMatterOption->setFont(QFont("Segoe UI", 10, QFont::DemiBold, true));
    whiteMatterOption->setFont(QFont("Segoe UI", 10, QFont::AnyStyle, true));
    vesselOption->setFont(QFont("Segoe UI", 10, QFont::AnyStyle, true));
    interventionalRouteOption->setFont(QFont("Segoe UI", 10, QFont::AnyStyle, true));

    imageOptionStates.originalOptionState = false;
    imageOptionStates.transparentBrainOptionState = false;
    imageOptionStates.greyMatterOptionState = true;
    imageOptionStates.whiteMatterOptionState = false;
    imageOptionStates.vesselOptionState = false;
    imageOptionStates.interventionalRouteOptionState = false;
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::greyMatterOptionLeaved
//!
void SurgeryPlanWindow::greyMatterOptionLeaved(){
    if(imageOptionStates.greyMatterOptionState){
        greyMatterOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: grey;  min-width: 0px; color: AliceBlue");
    }
    else{
        greyMatterOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: grey " );
    }
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::whiteMatterOptionHovered
//!
void SurgeryPlanWindow::whiteMatterOptionHovered(){
    whiteMatterOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: gainsboro;  min-width: 0px; color: AliceBlue  "  );
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::whiteMatterOptionClicked
//!
void SurgeryPlanWindow::whiteMatterOptionClicked(){
    whiteMatterOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: AliceBlue  "  );
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::whiteMatterOptionReleased
//!
void SurgeryPlanWindow::whiteMatterOptionReleased(){
    originalOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: grey  "  );
    transparentBrainOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: grey  "  );
    greyMatterOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: grey  "  );
    whiteMatterOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: grey;  min-width: 0px; color: aliceblue  "  );
    vesselOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: grey  "  );
    interventionalRouteOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: grey  "  );

    originalOption->setFont(QFont("Segoe UI",10, QFont::AnyStyle, true));
    transparentBrainOption->setFont(QFont("Segoe UI",10, QFont::AnyStyle, true));
    greyMatterOption->setFont(QFont("Segoe UI", 10, QFont::AnyStyle, true));
    whiteMatterOption->setFont(QFont("Segoe UI", 10, QFont::DemiBold, true));
    vesselOption->setFont(QFont("Segoe UI", 10, QFont::AnyStyle, true));
    interventionalRouteOption->setFont(QFont("Segoe UI", 10, QFont::AnyStyle, true));

    imageOptionStates.originalOptionState = false;
    imageOptionStates.transparentBrainOptionState = false;
    imageOptionStates.greyMatterOptionState = false;
    imageOptionStates.whiteMatterOptionState = true;
    imageOptionStates.vesselOptionState = false;
    imageOptionStates.interventionalRouteOptionState = false;
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::whiteMatterOptionLeaved
//!
void SurgeryPlanWindow::whiteMatterOptionLeaved(){
    if(imageOptionStates.whiteMatterOptionState){
        whiteMatterOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: grey;  min-width: 0px; color: AliceBlue");
    }
    else{
        whiteMatterOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: grey " );
    }
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::vesselOptionHovered
//!
void SurgeryPlanWindow::vesselOptionHovered(){
    vesselOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: gainsboro;  min-width: 0px; color: AliceBlue  "  );
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::vesselOptionClicked
//!
void SurgeryPlanWindow::vesselOptionClicked(){
    vesselOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: AliceBlue  "  );
}

#include <QThread>
//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::vesselOptionReleased
//!
void SurgeryPlanWindow::vesselOptionReleased(){
    originalOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: grey  "  );
    transparentBrainOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: grey  "  );
    greyMatterOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: grey  "  );
    whiteMatterOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: grey  "  );
    vesselOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: grey;  min-width: 0px; color: aliceblue  "  );
    interventionalRouteOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: grey  "  );

    originalOption->setFont(QFont("Segoe UI",10, QFont::AnyStyle, true));
    transparentBrainOption->setFont(QFont("Segoe UI",10, QFont::AnyStyle, true));
    greyMatterOption->setFont(QFont("Segoe UI", 10, QFont::AnyStyle, true));
    whiteMatterOption->setFont(QFont("Segoe UI", 10, QFont::AnyStyle, true));
    vesselOption->setFont(QFont("Segoe UI", 10, QFont::DemiBold, true));
    interventionalRouteOption->setFont(QFont("Segoe UI", 10, QFont::AnyStyle, true));

    imageOptionStates.originalOptionState = false;
    imageOptionStates.transparentBrainOptionState = false;
    imageOptionStates.greyMatterOptionState = false;
    imageOptionStates.whiteMatterOptionState = false;
    imageOptionStates.vesselOptionState = true;
    imageOptionStates.interventionalRouteOptionState = false;


}


void SurgeryPlanWindow::getVesselEnhancedImage(){
    qDebug()<<enhancedImage->GetDataDimension();
}


//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::vesselOptionLeaved
//!
void SurgeryPlanWindow::vesselOptionLeaved(){
    if(imageOptionStates.vesselOptionState){
        vesselOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: grey;  min-width: 0px; color: AliceBlue");
    }
    else{
        vesselOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: grey " );
    }
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::interventionalRouteOptionHovered
//!
void SurgeryPlanWindow::interventionalRouteOptionHovered(){
     interventionalRouteOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: gainsboro;  min-width: 0px; color: AliceBlue  "  );
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::interventionalRouteOptionClicked
//!
void SurgeryPlanWindow::interventionalRouteOptionClicked(){
     interventionalRouteOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: AliceBlue  "  );
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::interventionalRouteOptionReleased
//!
void SurgeryPlanWindow::interventionalRouteOptionReleased(){
    originalOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: grey  "  );
    transparentBrainOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: grey  "  );
    greyMatterOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: grey  "  );
    whiteMatterOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: grey  "  );
    vesselOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: grey  "  );
    interventionalRouteOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: grey;  min-width: 0px; color: aliceblue  "  );

    originalOption->setFont(QFont("Segoe UI",10, QFont::AnyStyle, true));
    transparentBrainOption->setFont(QFont("Segoe UI",10, QFont::AnyStyle, true));
    greyMatterOption->setFont(QFont("Segoe UI", 10, QFont::AnyStyle, true));
    whiteMatterOption->setFont(QFont("Segoe UI", 10, QFont::AnyStyle, true));
    vesselOption->setFont(QFont("Segoe UI", 10, QFont::AnyStyle, true));
    interventionalRouteOption->setFont(QFont("Segoe UI", 10, QFont::DemiBold, true));

    imageOptionStates.originalOptionState = false;
    imageOptionStates.transparentBrainOptionState = false;
    imageOptionStates.greyMatterOptionState = false;
    imageOptionStates.whiteMatterOptionState = false;
    imageOptionStates.vesselOptionState = false;
    imageOptionStates.interventionalRouteOptionState = true;

}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::interventionalRouteOptionLeaved
//!
void SurgeryPlanWindow::interventionalRouteOptionLeaved(){
    if(imageOptionStates.interventionalRouteOptionState){
        interventionalRouteOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: grey;  min-width: 0px; color: AliceBlue");
    }
    else{
        interventionalRouteOption->setStyleSheet( "border: 1px solid grey;  border-radius: 0px; background-color: transparent;  min-width: 0px; color: grey " );
    }
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief SurgeryPlanWindow::displayConfigurationBoard
//!
void SurgeryPlanWindow::displayConfigurationBoard(){
    this->patientWidgetConfigurationBoard->display(QCursor::pos());
}
