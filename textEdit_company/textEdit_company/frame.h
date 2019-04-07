#ifndef FRAME_H
#define FRAME_H

#include <QFrame>
#include <QTextEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QFileDialog>
#include <QDebug>
#include "menubar.h"
#include "SmtpMime"



class Frame : public QFrame
{
    Q_OBJECT
private:
    QTextEdit *textEdit;
    QVBoxLayout *layout;
public:
    Frame(QWidget *parent=0);
    virtual~Frame(){}
signals:
    void signalNewFileFrame();
    void signalOpenFileTextEdit(QString&);
    void signalSaveFile(QString&);
    void signalSaveFileDir(QString&);
public slots:
    void slotTextEdit();
    void slotOpenFileTextEdit(QString&);
    void slotSaveFile(QString&);
    void slotSaveFileDir(QString&);
    void slotSendEmail(QString&,QString&,QString&,QString&,QString&);
};

#endif // FRAME_H
