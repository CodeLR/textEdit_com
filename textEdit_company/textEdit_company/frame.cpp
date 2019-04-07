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

    connect(this,SIGNAL(signalSaveFileDir(QString&)),
            this,SLOT(slotSaveFileDir(QString&)));
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

void Frame::slotSaveFileDir(QString &strSave)
{
    QFile saveFile(strSave);
    if(saveFile.open(QFile::WriteOnly|QFile::Text)){
        QTextStream textStream(&saveFile);
        QString text=textEdit->toPlainText();
        textStream<<text;
        saveFile.flush();
        saveFile.close();
    }


}

void Frame::slotSendEmail(QString& emailRecipient,
                          QString& emailSend,
                          QString& emailTheme,
                          QString& pas,
                          QString& user)
{
    qDebug()<<emailRecipient;
    qDebug()<<emailSend;
    qDebug()<<emailTheme;
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);
    smtp.setUser(emailSend);
    smtp.setPassword(pas);
    MimeMessage message;
    message.setSender(new EmailAddress(emailSend, emailSend));
    message.addRecipient(new EmailAddress(emailRecipient,user));
    message.setSubject(emailTheme);

            // Now add some text to the email.
            // First we create a MimeText object.

            MimeText text;

            text.setText(textEdit->toPlainText());

            // Now add it to the mail

            message.addPart(&text);

            // Now we can send the mail

            smtp.connectToHost();
            smtp.login();
            if (smtp.sendMail(message))
            {
                QMessageBox::information(this,"Window message","Сообщение отправлено");
                qDebug()<<"Correct message";
            }
            else
            {
                QMessageBox::critical(this,"Window message","Ошибка! Введите данные верно");
                qDebug()<<"Fail";
            }
            smtp.quit();
}
