#-------------------------------------------------
#
# Project created by QtCreator 2015-09-07T10:03:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

unix:QMAKE_CXXFLAGS += -Wno-deprecated

TARGET = igss
TEMPLATE = app

INCLUDEPATH += SystemDataWare

INCLUDEPATH += GUIs

INCLUDEPATH += Dispatchers

INCLUDEPATH += DiskImageReaderFactory

INCLUDEPATH += ImageProcessingMethods

SOURCES +=  main.cpp\
            DiskImageReaderFactory/MHDFileReader.cpp \
            Dispatchers/SystemDispatcher.cpp \
            SystemDataWare/SystemDataBase.cpp \
            SystemDataWare/DataSetOfPatient.cpp \
            SystemDataWare/IgssImage.cpp \
            ImageProcessingMethods/IgssVtkImageConverter.cpp \
            ImageProcessingMethods/IgssItkImageConverter.cpp \
            SystemDataWare/CenterLinePoint.cpp \
            GUIs/IgssMainWindow.cpp \
            SystemDataWare/Patients.cpp \
            SystemDataWare/SystemMetaData.cpp

HEADERS  += \
            DiskImageReaderFactory/MHDFileReader.h \
            Dispatchers/SystemDispatcher.h \
            SystemDataWare/SystemDataBase.h \
            SystemDataWare/DataSetOfPatient.h \
            SystemDataWare/IgssImage.h \
            ImageProcessingMethods/IgssVtkImageConverter.h \
            ImageProcessingMethods/IgssItkImageConverter.h \
            SystemDataWare/CenterLinePoint.h \
            GUIs/IgssMainWindow.h \
            SystemDataWare/Patients.h \
            SystemDataWare/SystemMetaData.h

win32:INCLUDEPATH += "C:\Program Files\VTK\include\vtk-6.2"
unix:INCLUDEPATH += $$PWD/../../../../../usr/local/include/vtk-6.2
unix:DEPENDPATH += $$PWD/../../../../../usr/local/include/vtk-6.2

unix: LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkalglib-6.2 -lvtkChartsCore-6.2 -lvtkCommonColor-6.2 -lvtkCommonComputationalGeometry-6.2 -lvtkCommonCore-6.2 -lvtkCommonDataModel-6.2 -lvtkCommonExecutionModel-6.2 -lvtkCommonMath-6.2 -lvtkCommonMisc-6.2  -lvtkCommonSystem-6.2  -lvtkCommonTransforms-6.2  -lvtkDICOMParser-6.2  -lvtkDomainsChemistry-6.2  -lvtkexoIIc-6.2  -lvtkexpat-6.2  -lvtkFiltersAMR-6.2  -lvtkFiltersCore-6.2  -lvtkFiltersExtraction-6.2  -lvtkFiltersFlowPaths-6.2  -lvtkFiltersGeneral-6.2  -lvtkFiltersGeneric-6.2  -lvtkFiltersGeometry-6.2  -lvtkFiltersHybrid-6.2  -lvtkFiltersHyperTree-6.2  -lvtkFiltersImaging-6.2  -lvtkFiltersModeling-6.2  -lvtkFiltersParallel-6.2  -lvtkFiltersParallelImaging-6.2  -lvtkFiltersProgrammable-6.2  -lvtkFiltersSelection-6.2  -lvtkFiltersSMP-6.2  -lvtkFiltersSources-6.2  -lvtkFiltersStatistics-6.2  -lvtkFiltersTexture-6.2  -lvtkFiltersVerdict-6.2  -lvtkfreetype-6.2  -lvtkftgl-6.2  -lvtkGeovisCore-6.2  -lvtkgl2ps-6.2  -lvtkGUISupportQt-6.2  -lvtkGUISupportQtOpenGL-6.2  -lvtkGUISupportQtSQL-6.2  -lvtkGUISupportQtWebkit-6.2  -lvtkhdf5-6.2  -lvtkhdf5_hl-6.2  -lvtkImagingColor-6.2  -lvtkImagingCore-6.2  -lvtkImagingFourier-6.2  -lvtkImagingGeneral-6.2  -lvtkImagingHybrid-6.2  -lvtkImagingMath-6.2  -lvtkImagingMorphological-6.2  -lvtkImagingSources-6.2  -lvtkImagingStatistics-6.2  -lvtkImagingStencil-6.2  -lvtkInfovisCore-6.2  -lvtkInfovisLayout-6.2  -lvtkInteractionImage-6.2  -lvtkInteractionStyle-6.2  -lvtkInteractionWidgets-6.2  -lvtkIOAMR-6.2  -lvtkIOCore-6.2  -lvtkIOEnSight-6.2  -lvtkIOExodus-6.2  -lvtkIOExport-6.2  -lvtkIOGeometry-6.2  -lvtkIOImage-6.2 -lvtkIOImport-6.2  -lvtkIOInfovis-6.2  -lvtkIOLegacy-6.2  -lvtkIOLSDyna-6.2  -lvtkIOMINC-6.2  -lvtkIOMovie-6.2  -lvtkIONetCDF-6.2  -lvtkIOParallel-6.2  -lvtkIOParallelXML-6.2  -lvtkIOPLY-6.2  -lvtkIOSQL-6.2  -lvtkIOVideo-6.2  -lvtkIOXML-6.2  -lvtkIOXMLParser-6.2  -lvtkjpeg-6.2  -lvtkjsoncpp-6.2  -lvtklibxml2-6.2  -lvtkmetaio-6.2  -lvtkNetCDF-6.2  -lvtkNetCDF_cxx-6.2  -lvtkoggtheora-6.2  -lvtkParallelCore-6.2  -lvtkpng-6.2  -lvtkproj4-6.2  -lvtkRenderingAnnotation-6.2  -lvtkRenderingContext2D-6.2  -lvtkRenderingContextOpenGL-6.2  -lvtkRenderingCore-6.2  -lvtkRenderingFreeType-6.2  -lvtkRenderingFreeTypeOpenGL-6.2  -lvtkRenderingGL2PS-6.2  -lvtkRenderingImage-6.2  -lvtkRenderingLabel-6.2 -lvtkRenderingLIC-6.2 -lvtkRenderingLOD-6.2 -lvtkRenderingOpenGL-6.2 -lvtkRenderingQt-6.2 -lvtkRenderingVolume-6.2 -lvtkRenderingVolumeOpenGL-6.2 -lvtksqlite-6.2 -lvtksys-6.2 -lvtktiff-6.2 -lvtkverdict-6.2 -lvtkViewsContext2D-6.2 -lvtkViewsCore-6.2 -lvtkViewsInfovis-6.2 -lvtkViewsQt-6.2 -lvtkzlib-6.2

# importer des librairies de vtk...
win32:LIBS += $$quote(C:\Program Files\VTK\lib\QVTKWidgetPlugin.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkalglib-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkChartsCore-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkCommonColor-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkCommonComputationalGeometry-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkCommonCore-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkCommonDataModel-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkCommonExecutionModel-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkCommonMath-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkCommonMisc-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkCommonSystem-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkCommonTransforms-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkDICOMParser-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkDomainsChemistry-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkexoIIc-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkexpat-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersAMR-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersCore-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersExtraction-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersFlowPaths-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersGeneral-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersGeneric-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersGeometry-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersHybrid-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersHyperTree-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersImaging-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersModeling-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersParallel-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersParallelImaging-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersProgrammable-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersSelection-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersSMP-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersSources-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersStatistics-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersTexture-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkFiltersVerdict-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkfreetype-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkftgl-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkGeovisCore-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkgl2ps-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkGUISupportQt-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkGUISupportQtOpenGL-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkGUISupportQtSQL-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkGUISupportQtWebkit-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkhdf5-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkhdf5_hl-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkImagingColor-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkImagingCore-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkImagingFourier-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkImagingGeneral-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkImagingHybrid-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkImagingMath-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkImagingMorphological-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkImagingSources-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkImagingStatistics-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkImagingStencil-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkInfovisCore-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkInfovisLayout-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkInteractionImage-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkInteractionStyle-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkInteractionWidgets-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOAMR-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOCore-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOEnSight-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOExodus-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOExport-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOGeometry-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOImage-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOImport-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOInfovis-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOLegacy-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOLSDyna-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOMINC-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOMovie-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIONetCDF-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOParallel-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOParallelXML-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOPLY-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOSQL-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOVideo-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOXML-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkIOXMLParser-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkjpeg-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkjsoncpp-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtklibxml2-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkmetaio-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkNetCDF-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkNetCDF_cxx-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkoggtheora-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkParallelCore-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkpng-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkproj4-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingAnnotation-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingContext2D-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingContextOpenGL-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingCore-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingFreeType-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingFreeTypeOpenGL-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingGL2PS-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingImage-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingLabel-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingLIC-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingLOD-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingOpenGL-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingQt-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingVolume-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkRenderingVolumeOpenGL-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtksqlite-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtksys-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtktiff-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkverdict-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkViewsContext2D-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkViewsCore-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkViewsInfovis-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkViewsQt-6.2.lib)
win32:LIBS += $$quote(C:\Program Files\VTK\lib\vtkzlib-6.2.lib)


win32:INCLUDEPATH += "C:\Program Files\ITK\include\ITK-4.7"
unix:INCLUDEPATH += $$PWD/../../../../../Program Files/ITK/include/ITK-4.7
unix:DEPENDPATH += $$PWD/../../../../../Program Files/ITK/include/ITK-4.7

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../Program Files/ITK/lib/ -lITKBiasCorrection-4 -lITKBioCell-4 -lITKCommon -lITKDICOMParser-4 -litkdouble-conversion-4 -lITKEXPAT-4 -lITKFEM-4 -litkgdcmCommon-4 -litkgdcmDICT-4 -litkgdcmDSED-4 -litkgdcmIOD-4 -litkgdcmjpeg8-4 -litkgdcmjpeg12-4 -litkgdcmjpeg16-4 -litkgdcmMSFF-4 -lITKgiftiio-4 -litkhdf5_cpp-4 -litkhdf5-4 -lITKIOBioRad-4 -lITKIOBMP-4 -lITKIOCSV-4 -lITKIOGDCM-4 -lITKIOGE-4 -lITKIOGIPL-4 -lITKIOHDF5-4 -lITKIOImageBase-4 -lITKIOIPL-4 -lITKIOJPEG-4 -lITKIOLSM-4 -lITKIOMesh-4 -lITKIOMeta-4 -lITKIOMRC-4 -lITKIONIFTI-4 -lITKIONRRD-4 -lITKIOPNG-4 -lITKIOSiemens-4 -lITKIOSpatialObjects-4 -lITKIOStimulate-4 -lITKIOTIFF-4 -lITKIOTransformBase-4 -lITKIOTransformHDF5-4 -lITKIOTransformInsightLegacy-4 -lITKIOTransformMatlab-4 -lITKIOVTK-4 -lITKIOXML-4 -litkjpeg-4 -lITKKLMRegionGrowing-4 -lITKLabelMap-4 -lITKMesh-4 -lITKMetaIO-4 -litkNetlibSlatec-4 -lITKniftiio-4 -lITKNrrdIO-4 -litkopenjpeg-4 -lITKOptimizers-4 -lITKOptimizersv4-4 -lITKPath-4 -litkpng-4 -lITKPolynomials-4 -lITKQuadEdgeMesh-4 -lITKSpatialObjects-4 -lITKStatistics-4 -litksys-4 -litktiff-4 -litkv3p_lsqr-4 -litkv3p_netlib-4 -litkvcl-4 -lITKVideoCore-4 -lITKVideoIO-4 -litkvnl_algo-4 -litkvnl-4 -lITKVNLInstantiation-4 -lITKVTK-4 -lITKWatersheds-4 -litkzlib-4 -lITKznz-4
else:unix: LIBS += -L$$PWD/../../../../../Program Files/ITK/lib/ -lITKBiasCorrection-4 -lITKBioCell-4 -lITKCommon -lITKDICOMParser-4 -litkdouble-conversion-4 -lITKEXPAT-4 -lITKFEM-4 -litkgdcmCommon-4 -litkgdcmDICT-4 -litkgdcmDSED-4 -litkgdcmIOD-4 -litkgdcmjpeg8-4 -litkgdcmjpeg12-4 -litkgdcmjpeg16-4 -litkgdcmMSFF-4 -lITKgiftiio-4 -litkhdf5_cpp-4 -litkhdf5-4 -lITKIOBioRad-4 -lITKIOBMP-4 -lITKIOCSV-4 -lITKIOGDCM-4 -lITKIOGE-4 -lITKIOGIPL-4 -lITKIOHDF5-4 -lITKIOImageBase-4 -lITKIOIPL-4 -lITKIOJPEG-4 -lITKIOLSM-4 -lITKIOMesh-4 -lITKIOMeta-4 -lITKIOMRC-4 -lITKIONIFTI-4 -lITKIONRRD-4 -lITKIOPNG-4 -lITKIOSiemens-4 -lITKIOSpatialObjects-4 -lITKIOStimulate-4 -lITKIOTIFF-4 -lITKIOTransformBase-4 -lITKIOTransformHDF5-4 -lITKIOTransformInsightLegacy-4 -lITKIOTransformMatlab-4 -lITKIOVTK-4 -lITKIOXML-4 -litkjpeg-4 -lITKKLMRegionGrowing-4 -lITKLabelMap-4 -lITKMesh-4 -lITKMetaIO-4 -litkNetlibSlatec-4 -lITKniftiio-4 -lITKNrrdIO-4 -litkopenjpeg-4 -lITKOptimizers-4 -lITKOptimizersv4-4 -lITKPath-4 -litkpng-4 -lITKPolynomials-4 -lITKQuadEdgeMesh-4 -lITKSpatialObjects-4 -lITKStatistics-4 -litksys-4 -litktiff-4 -litkv3p_lsqr-4 -litkv3p_netlib-4 -litkvcl-4 -lITKVideoCore-4 -lITKVideoIO-4 -litkvnl_algo-4 -litkvnl-4 -lITKVNLInstantiation-4 -lITKVTK-4 -lITKWatersheds-4 -litkzlib-4 -lITKznz-4
