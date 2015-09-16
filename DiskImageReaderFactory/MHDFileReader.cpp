#include "MHDFileReader.h"
#include <QDebug>

MHDFileReader::MHDFileReader(){

}

//!------------------------------------------------------------------------------------------------------
//!
//! \brief MHDFileReader::doParseMHDFile
//! \param mhdFilePath
//! \param image
//!
void MHDFileReader::doParseMHDFile(QString mhdFilePath, IgssImage* image){

    //qDebug()<<"lecture of the mhd metadata file";
    QFile *file = new QFile(mhdFilePath);
    if(!file->open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug()<<"Can't open the file!"<<endl;
    }

    //qDebug()<<"mhd start";
    while(!file->atEnd()) {
        //!fetch a line of character
        QByteArray line = file->readLine();
        QString str(line);
        str.replace(QString("\n"), QString(""));

        if(str.contains("NDim")){
            QStringList temp = str.split(" = ");
            image->setNumberOfDimension(temp[1].toInt(0,10));
        }
        else if(str.contains("DimSize")){
            QStringList temp = str.split(" = ");
            QStringList temp1 = temp[1].split(" ");
            image->setDimensionSize(temp1[0].toInt(0,10), temp1[1].toInt(0,10), temp1[2].toInt(0,10));
        }
        else if(str.contains("ElementSpacing")){
            QStringList temp = str.split(" = ");
            QStringList temp1 = temp[1].split(" ");
            image->setElementSpacing(temp1[0].toFloat(0), temp1[1].toFloat(0), temp1[2].toFloat(0));
        }
        else if(str.contains("ElementType")){
            QStringList temp = str.split(" = ");
            image->setElementType(temp[1]);
        }
        else if(str.contains("ElementByteOrderMSB")){
            QStringList temp = str.split(" = ");
            image->setElementByteOrderMSB(temp[1].toInt(0,10));
        }
        else if(str.contains("ElementDataFile")){
            QStringList temp = str.split(" = ");

            QStringList temp1 = mhdFilePath.split("/");
            mhdFilePath.replace(temp1.at(temp1.size() - 1),temp[1]);
            image->setRawFileName(mhdFilePath);
            //qDebug()<<mhdFilePath;
        }
    }
    //qDebug()<<"mhd finished";
    file->close();

    //qDebug()<<"allocate space for data storage";
    image->setLengthOfDataSet();

    //!------------------------------------------------------------------------------------------------------
    //! Read the dataset file to fectch the tridimensional image's true values
    //!------------------------------------------------------------------------------------------------------
    QFile* rawfileReader =  new QFile(image->getRawFileName());
    if(!rawfileReader->open(QIODevice::ReadOnly)){
        qDebug()<<"Can't open the file!"<<endl;
        return;
    }

    QByteArray dataset = rawfileReader->readAll();

    for(long i = 0; i < dataset.size() - 1; i += 2){
        image->setValueByIndex(i/2, int(dataset.at(i)) + int(dataset.at(i + 1))*255);
    }

    rawfileReader->close();

}
