#include "dialog_sendmail_textedit.h"

Dialog_sendMail_textEdit::Dialog_sendMail_textEdit(QWidget* parent)
    :QDialog(parent)
{
    windowLabel=new QLabel(this);
    windowLabel->setText(tr("Введите параметра для отправки сообщения"));
    recipientMailLabel=new QLabel(tr("Получатель"));
    sendMailLabel=new QLabel(tr("Отправитель"));
    themeMailLabel=new QLabel(tr("Тема письма"));
    m_lineUser=new QLineEdit(this);
    m_linePassword=new QLineEdit(this);
    pasEmail=new QLabel(tr("Пароль"));
    userEmail=new QLabel(tr("Имя получателя"));
    layout=new QGridLayout(this);
    m_buttonn_Cancel=new QPushButton(tr("Cancel"),this);
    layout->setMargin(5);
    m_buttonn_OK=new QPushButton(tr("OK"),this);
    m_lineEdit=new QLineEdit(this);
    m_lineEditSendMail=new QLineEdit(this);
    m_lineEditThemeMail=new QLineEdit(this);
    layout->addWidget(windowLabel,0,0,1,2,Qt::AlignCenter);
    layout->addWidget(recipientMailLabel,1,0,Qt::AlignLeft);
    layout->addWidget(sendMailLabel,2,0,Qt::AlignLeft);
    layout->addWidget(themeMailLabel,3,0,Qt::AlignLeft);
    layout->addWidget(m_lineEdit,1,1);
    layout->addWidget(m_lineEditSendMail,2,1);
    layout->addWidget(m_lineEditThemeMail,3,1);
    layout->addWidget(userEmail,4,0,Qt::AlignLeft);
    layout->addWidget(m_lineUser,4,1);
    layout->addWidget(pasEmail,5,0,Qt::AlignLeft);
    layout->addWidget(m_linePassword,5,1);
    layout->addWidget(m_buttonn_OK,6,0);
    layout->addWidget(m_buttonn_Cancel,6,1);
    connect(m_buttonn_Cancel,SIGNAL(clicked()),this,SLOT(close()));
    connect(m_buttonn_OK,SIGNAL(clicked()),this,SLOT(slotCloseOK()));
}

void Dialog_sendMail_textEdit::slotCloseOK()
{
    QString tempMail=m_lineEdit->text();
    QString sendMail=m_lineEditSendMail->text();
    QString themeMail=m_lineEditThemeMail->text();
    QString pas=m_linePassword->text();
    QString user=m_lineUser->text();

    if(tempMail.contains("@")) {
        emit signalSaveEmail(tempMail,
                             sendMail,
                             themeMail,
                             pas,
                             user);
        close();
     } else {
        QMessageBox::critical(this,"Email","Введите верный адрес для отправки почты!");
     }
    if(tempMail.isEmpty()){
        QMessageBox::critical(this,"Email","Введите верный адрес для отправки почты!");
    }
}
