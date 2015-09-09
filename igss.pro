#-------------------------------------------------
#
# Project created by QtCreator 2015-09-07T10:03:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -Wno-deprecated

TARGET = igss
TEMPLATE = app

INCLUDEPATH += SystemDataWare

INCLUDEPATH += GUIs

INCLUDEPATH += Dispatchers

INCLUDEPATH += DiskImageReaderFactory

SOURCES +=  main.cpp\
            GUIs/widget.cpp \
            DiskImageReaderFactory/MHDFileReader.cpp \
            Dispatchers/SystemDispatcher.cpp \
            SystemDataWare/SystemDataBase.cpp \
            SystemDataWare/DataSetOfPatient.cpp \
            SystemDataWare/IgssImage.cpp \
            ImageProcessingMethods/IgssVtkImageConverter.cpp \
            ImageProcessingMethods/IgssItkImageConverter.cpp \
    SystemDataWare/CenterLinePoint.cpp

HEADERS  += GUIs/widget.h \
            DiskImageReaderFactory/MHDFileReader.h \
            Dispatchers/SystemDispatcher.h \
            SystemDataWare/SystemDataBase.h \
            SystemDataWare/DataSetOfPatient.h \
            SystemDataWare/IgssImage.h \
            ImageProcessingMethods/IgssVtkImageConverter.h \
            ImageProcessingMethods/IgssItkImageConverter.h \
    SystemDataWare/CenterLinePoint.h


INCLUDEPATH += $$PWD/../../../../../usr/local/include/vtk-6.2

DEPENDPATH += $$PWD/../../../../../usr/local/include/vtk-6.2

LIBS += -L$$PWD/../../../../../usr/local/lib/ -lQVTKWidgetPlugin
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkalglib-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkChartsCore-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkCommonColor-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkCommonComputationalGeometry-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkCommonCore-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkCommonDataModel-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkCommonExecutionModel-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkCommonMath-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkCommonMisc-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkCommonSystem-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkCommonTransforms-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkDICOMParser-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkDomainsChemistry-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkexoIIc-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkexpat-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkFiltersAMR-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkFiltersCore-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkFiltersExtraction-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkFiltersFlowPaths-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkFiltersGeneral-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkFiltersGeneric-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkFiltersGeometry-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkFiltersHybrid-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkFiltersHyperTree-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkFiltersImaging-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkFiltersModeling-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkFiltersParallel-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkFiltersParallelImaging-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkFiltersProgrammable-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkFiltersSelection-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkFiltersSMP-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkFiltersSources-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkFiltersStatistics-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkFiltersTexture-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkFiltersVerdict-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkfreetype-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkftgl-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkGeovisCore-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkgl2ps-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkGUISupportQt-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkGUISupportQtOpenGL-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkGUISupportQtSQL-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkGUISupportQtWebkit-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkhdf5-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkhdf5_hl-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkImagingColor-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkImagingCore-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkImagingFourier-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkImagingGeneral-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkImagingHybrid-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkImagingMath-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkImagingMorphological-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkImagingSources-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkImagingStatistics-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkImagingStencil-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkInfovisCore-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkInfovisLayout-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkInteractionImage-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkInteractionStyle-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkInteractionWidgets-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkIOAMR-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkIOCore-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkIOEnSight-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkIOExodus-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkIOExport-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkIOGeometry-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkIOImage-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkIOImport-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkIOInfovis-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkIOLegacy-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkIOLSDyna-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkIOMINC-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkIOMovie-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkIONetCDF-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkIOParallel-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkIOParallelXML-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkIOPLY-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkIOSQL-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkIOVideo-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkIOXML-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkIOXMLParser-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkjpeg-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkjsoncpp-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtklibxml2-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkmetaio-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkNetCDF-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkNetCDF_cxx-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkoggtheora-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkParallelCore-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkpng-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkproj4-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkRenderingAnnotation-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkRenderingContext2D-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkRenderingContextOpenGL-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkRenderingCore-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkRenderingFreeType-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkRenderingFreeTypeOpenGL-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkRenderingGL2PS-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkRenderingImage-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkRenderingLabel-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkRenderingLIC-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkRenderingLOD-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkRenderingOpenGL-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkRenderingQt-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkRenderingVolume-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkRenderingVolumeOpenGL-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtksqlite-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtksys-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtktiff-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkverdict-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkViewsContext2D-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkViewsCore-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkViewsInfovis-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkViewsQt-6.2
LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkzlib-6.2

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib/release/ -lQVTKWidgetPlugin
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib/debug/ -lQVTKWidgetPlugin
#else:unix: LIBS += -L$$PWD/../../../../../usr/local/lib/ -lQVTKWidgetPlugin
