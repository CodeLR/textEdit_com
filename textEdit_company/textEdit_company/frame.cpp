#include "frame.h"

Frame::Frame(QWidget *parent)
    :QFrame(parent)
{
    layout=new QVBoxLayout(this);
    textEdit=new QTextEdit(this);
    layout->addWidget(textEdit);
    connect(this,SIGNAL(signalNewFileFrame()),this,SLOT(slotTextEdit()));
    connect(this,SIGNAL(signalOpenFileTextEdit(QString&)),
            this,SLOT(slotOpenFileTextEdit(QString&)));

    connect(this,SIGNAL(signalSaveFile(QString&)),
            this,SLOT(slotSaveFile(QString&)));
}

void Frame::slotTextEdit()
{
    textEdit->clear();
}

void Frame::slotOpenFileTextEdit(QString &tempString)
{
    QFile file(tempString);
    if(file.open(QFile::ReadOnly|QFile::Text))
    {
        QTextStream textStream(&file);
        QString stringTextS=textStream.readAll();
        textEdit->setText(stringTextS);
    }
}

void Frame::slotSaveFile(QString &strSaveDir)
{
    QFile saveFile(strSaveDir);
    if(saveFile.open(QFile::WriteOnly|QFile::Text)){
        QTextStream textStream(&saveFile);
        QString text=textEdit->toPlainText();
        textStream<<text;
        saveFile.flush();
        saveFile.close();
    }

}
