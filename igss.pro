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

win32:INCLUDEPATH += "C:\Program Files\VTK\include\vtk-6.2"
unix:INCLUDEPATH += $$PWD/../../../../../usr/local/include/vtk-6.2
unix:DEPENDPATH += $$PWD/../../../../../usr/local/include/vtk-6.2


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/C:/Program Files/VTK/lib/ -lQVTKWidgetPlugin -lvtkalglib-6 -lvtkChartsCore-6 -lvtkCommonColor-6 -lCommonComputationalGeometry-6 -lCommonCore-6 -lCommonDataModel-6 -lCommonExecutionModel-6 -lCommonMath-6 -lCommonMisc-6 -lCommonSystem-6 -lCommonTransforms-6 -lDICOMParser-6 -lDomainsChemistry-6 -lexoIIc-6 -lexpat-6 -lFiltersAMR-6 -lFiltersCore-6 -lFiltersExtraction-6 -lFiltersFlowPaths-6 -lFiltersGeneral-6 -lFiltersGeneric-6 -lFiltersGeometry-6 -lFiltersHybrid-6 -lFiltersHyperTree-6 -lFiltersImaging-6 -lFiltersModeling-6 -lFiltersParallel-6 -lFiltersParallelImaging-6 -lFiltersProgrammable-6 -lFiltersSelection-6 -lFiltersSMP-6 -lFiltersSources-6 -lFiltersStatistics-6 -lFiltersTexture-6 -lFiltersVerdict-6 -lfreetype-6 -lftgl-6 -lGeovisCore-6 -lgl2ps-6 -lGUISupportQt-6 -lGUISupportQtOpenGL-6 -lGUISupportQtSQL-6 -lGUISupportQtWebkit-6 -lhdf5-6 -lhdf5_hl-6 -lImagingColor-6 -lImagingCore-6 -lImagingFourier-6 -lImagingGeneral-6 -lImagingHybrid-6 -lImagingMath-6 -lImagingMorphological-6 -lImagingSources-6 -lImagingStatistics-6 -lImagingStencil-6 -lInfovisCore-6 -lInfovisLayout-6 -lInteractionImage-6 -lInteractionStyle-6 -lInteractionWidgets-6 -lIOAMR-6 -lIOCore-6 -lIOEnSight-6 -lIOExodus-6 -lIOExport-6 -lIOGeometry-6 -lIOImage-6 -lIOImport-6 -lIOInfovis-6 -lIOLegacy-6 -lIOLSDyna-6 -lIOMINC-6 -lIOMovie-6 -lIONetCDF-6 -lIOParallel-6 -lIOParallelXML-6 -lIOPLY-6 -lIOSQL-6 -lIOVideo-6 -lIOXML-6 -lIOXMLParser-6 -ljpeg-6 -ljsoncpp-6 -llibxml2-6 -lmetaio-6 -lNetCDF-6 -lNetCDF_cxx-6 -loggtheora-6 -lParallelCore-6 -lpng-6 -lproj4-6 -lRenderingAnnotation-6 -lRenderingContext2D-6 -lRenderingContextOpenGL-6 -lRenderingCore-6 -lRenderingFreeType-6 -lRenderingFreeTypeOpenGL-6 -lRenderingGL2PS-6 -lRenderingImage-6 -lRenderingLabel-6 -lRenderingLIC-6 -lRenderingLOD-6 -lRenderingOpenGL-6 -lRenderingQt-6 -lRenderingVolume-6 -lRenderingVolumeOpenGL-6 -lsqlite-6 -lsys-6 -ltiff-6 -lverdict-6 -lViewsContext2D-6 -lViewsCore-6 -lViewsInfovis-6 -lViewsQt-6 -lzlib-6
else:unix: LIBS += -L$$PWD/../../../../../usr/local/lib/ -lvtkalglib-6.2 -lvtkChartsCore-6.2 -lvtkCommonColor-6.2 -lvtkCommonComputationalGeometry-6.2 -lvtkCommonCore-6.2 -lvtkCommonDataModel-6.2 -lvtkCommonExecutionModel-6.2 -lvtkCommonMath-6.2 -lvtkCommonMisc-6.2  -lvtkCommonSystem-6.2  -lvtkCommonTransforms-6.2  -lvtkDICOMParser-6.2  -lvtkDomainsChemistry-6.2  -lvtkexoIIc-6.2  -lvtkexpat-6.2  -lvtkFiltersAMR-6.2  -lvtkFiltersCore-6.2  -lvtkFiltersExtraction-6.2  -lvtkFiltersFlowPaths-6.2  -lvtkFiltersGeneral-6.2  -lvtkFiltersGeneric-6.2  -lvtkFiltersGeometry-6.2  -lvtkFiltersHybrid-6.2  -lvtkFiltersHyperTree-6.2  -lvtkFiltersImaging-6.2  -lvtkFiltersModeling-6.2  -lvtkFiltersParallel-6.2  -lvtkFiltersParallelImaging-6.2  -lvtkFiltersProgrammable-6.2  -lvtkFiltersSelection-6.2  -lvtkFiltersSMP-6.2  -lvtkFiltersSources-6.2  -lvtkFiltersStatistics-6.2  -lvtkFiltersTexture-6.2  -lvtkFiltersVerdict-6.2  -lvtkfreetype-6.2  -lvtkftgl-6.2  -lvtkGeovisCore-6.2  -lvtkgl2ps-6.2  -lvtkGUISupportQt-6.2  -lvtkGUISupportQtOpenGL-6.2  -lvtkGUISupportQtSQL-6.2  -lvtkGUISupportQtWebkit-6.2  -lvtkhdf5-6.2  -lvtkhdf5_hl-6.2  -lvtkImagingColor-6.2  -lvtkImagingCore-6.2  -lvtkImagingFourier-6.2  -lvtkImagingGeneral-6.2  -lvtkImagingHybrid-6.2  -lvtkImagingMath-6.2  -lvtkImagingMorphological-6.2  -lvtkImagingSources-6.2  -lvtkImagingStatistics-6.2  -lvtkImagingStencil-6.2  -lvtkInfovisCore-6.2  -lvtkInfovisLayout-6.2  -lvtkInteractionImage-6.2  -lvtkInteractionStyle-6.2  -lvtkInteractionWidgets-6.2  -lvtkIOAMR-6.2  -lvtkIOCore-6.2  -lvtkIOEnSight-6.2  -lvtkIOExodus-6.2  -lvtkIOExport-6.2  -lvtkIOGeometry-6.2  -lvtkIOImage-6.2 -lvtkIOImport-6.2  -lvtkIOInfovis-6.2  -lvtkIOLegacy-6.2  -lvtkIOLSDyna-6.2  -lvtkIOMINC-6.2  -lvtkIOMovie-6.2  -lvtkIONetCDF-6.2  -lvtkIOParallel-6.2  -lvtkIOParallelXML-6.2  -lvtkIOPLY-6.2  -lvtkIOSQL-6.2  -lvtkIOVideo-6.2  -lvtkIOXML-6.2  -lvtkIOXMLParser-6.2  -lvtkjpeg-6.2  -lvtkjsoncpp-6.2  -lvtklibxml2-6.2  -lvtkmetaio-6.2  -lvtkNetCDF-6.2  -lvtkNetCDF_cxx-6.2  -lvtkoggtheora-6.2  -lvtkParallelCore-6.2  -lvtkpng-6.2  -lvtkproj4-6.2  -lvtkRenderingAnnotation-6.2  -lvtkRenderingContext2D-6.2  -lvtkRenderingContextOpenGL-6.2  -lvtkRenderingCore-6.2  -lvtkRenderingFreeType-6.2  -lvtkRenderingFreeTypeOpenGL-6.2  -lvtkRenderingGL2PS-6.2  -lvtkRenderingImage-6.2  -lvtkRenderingLabel-6.2 -lvtkRenderingLIC-6.2 -lvtkRenderingLOD-6.2 -lvtkRenderingOpenGL-6.2 -lvtkRenderingQt-6.2 -lvtkRenderingVolume-6.2 -lvtkRenderingVolumeOpenGL-6.2 -lvtksqlite-6.2 -lvtksys-6.2 -lvtktiff-6.2 -lvtkverdict-6.2 -lvtkViewsContext2D-6.2 -lvtkViewsCore-6.2 -lvtkViewsInfovis-6.2 -lvtkViewsQt-6.2 -lvtkzlib-6.2


win32:INCLUDEPATH += "C:\Program Files\ITK\include\ITK-4.7"
unix:INCLUDEPATH += $$PWD/../../../../../Program Files/ITK/include/ITK-4.7
unix:DEPENDPATH += $$PWD/../../../../../Program Files/ITK/include/ITK-4.7

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../Program Files/ITK/lib/ -lITKBiasCorrection-4 -lITKBioCell-4 -lITKCommon -lITKDICOMParser-4 -litkdouble-conversion-4 -lITKEXPAT-4 -lITKFEM-4 -litkgdcmCommon-4 -litkgdcmDICT-4 -litkgdcmDSED-4 -litkgdcmIOD-4 -litkgdcmjpeg8-4 -litkgdcmjpeg12-4 -litkgdcmjpeg16-4 -litkgdcmMSFF-4 -lITKgiftiio-4 -litkhdf5_cpp-4 -litkhdf5-4 -lITKIOBioRad-4 -lITKIOBMP-4 -lITKIOCSV-4 -lITKIOGDCM-4 -lITKIOGE-4 -lITKIOGIPL-4 -lITKIOHDF5-4 -lITKIOImageBase-4 -lITKIOIPL-4 -lITKIOJPEG-4 -lITKIOLSM-4 -lITKIOMesh-4 -lITKIOMeta-4 -lITKIOMRC-4 -lITKIONIFTI-4 -lITKIONRRD-4 -lITKIOPNG-4 -lITKIOSiemens-4 -lITKIOSpatialObjects-4 -lITKIOStimulate-4 -lITKIOTIFF-4 -lITKIOTransformBase-4 -lITKIOTransformHDF5-4 -lITKIOTransformInsightLegacy-4 -lITKIOTransformMatlab-4 -lITKIOVTK-4 -lITKIOXML-4 -litkjpeg-4 -lITKKLMRegionGrowing-4 -lITKLabelMap-4 -lITKMesh-4 -lITKMetaIO-4 -litkNetlibSlatec-4 -lITKniftiio-4 -lITKNrrdIO-4 -litkopenjpeg-4 -lITKOptimizers-4 -lITKOptimizersv4-4 -lITKPath-4 -litkpng-4 -lITKPolynomials-4 -lITKQuadEdgeMesh-4 -lITKSpatialObjects-4 -lITKStatistics-4 -litksys-4 -litktiff-4 -litkv3p_lsqr-4 -litkv3p_netlib-4 -litkvcl-4 -lITKVideoCore-4 -lITKVideoIO-4 -litkvnl_algo-4 -litkvnl-4 -lITKVNLInstantiation-4 -lITKVTK-4 -lITKWatersheds-4 -litkzlib-4 -lITKznz-4
else:unix: LIBS += -L$$PWD/../../../../../Program Files/ITK/lib/ -lITKBiasCorrection-4 -lITKBioCell-4 -lITKCommon -lITKDICOMParser-4 -litkdouble-conversion-4 -lITKEXPAT-4 -lITKFEM-4 -litkgdcmCommon-4 -litkgdcmDICT-4 -litkgdcmDSED-4 -litkgdcmIOD-4 -litkgdcmjpeg8-4 -litkgdcmjpeg12-4 -litkgdcmjpeg16-4 -litkgdcmMSFF-4 -lITKgiftiio-4 -litkhdf5_cpp-4 -litkhdf5-4 -lITKIOBioRad-4 -lITKIOBMP-4 -lITKIOCSV-4 -lITKIOGDCM-4 -lITKIOGE-4 -lITKIOGIPL-4 -lITKIOHDF5-4 -lITKIOImageBase-4 -lITKIOIPL-4 -lITKIOJPEG-4 -lITKIOLSM-4 -lITKIOMesh-4 -lITKIOMeta-4 -lITKIOMRC-4 -lITKIONIFTI-4 -lITKIONRRD-4 -lITKIOPNG-4 -lITKIOSiemens-4 -lITKIOSpatialObjects-4 -lITKIOStimulate-4 -lITKIOTIFF-4 -lITKIOTransformBase-4 -lITKIOTransformHDF5-4 -lITKIOTransformInsightLegacy-4 -lITKIOTransformMatlab-4 -lITKIOVTK-4 -lITKIOXML-4 -litkjpeg-4 -lITKKLMRegionGrowing-4 -lITKLabelMap-4 -lITKMesh-4 -lITKMetaIO-4 -litkNetlibSlatec-4 -lITKniftiio-4 -lITKNrrdIO-4 -litkopenjpeg-4 -lITKOptimizers-4 -lITKOptimizersv4-4 -lITKPath-4 -litkpng-4 -lITKPolynomials-4 -lITKQuadEdgeMesh-4 -lITKSpatialObjects-4 -lITKStatistics-4 -litksys-4 -litktiff-4 -litkv3p_lsqr-4 -litkv3p_netlib-4 -litkvcl-4 -lITKVideoCore-4 -lITKVideoIO-4 -litkvnl_algo-4 -litkvnl-4 -lITKVNLInstantiation-4 -lITKVTK-4 -lITKWatersheds-4 -litkzlib-4 -lITKznz-4
