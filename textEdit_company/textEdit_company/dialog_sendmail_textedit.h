#ifndef DIALOG_SENDMAIL_TEXTEDIT_H
#define DIALOG_SENDMAIL_TEXTEDIT_H
#include <QDialog>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QLabel>
class Dialog_sendMail_textEdit:public QDialog
{
    Q_OBJECT

private:
    QLabel* windowLabel;
    QLabel* recipientMailLabel;
    QLabel* sendMailLabel;
    QLabel* themeMailLabel;
    QLabel* userEmail;
    QLabel* pasEmail;


    QPushButton* m_buttonn_OK;
    QPushButton* m_buttonn_Cancel;
    QLineEdit* m_lineEdit;
    QLineEdit* m_lineEditSendMail;
    QLineEdit* m_lineEditThemeMail;
    QLineEdit* m_lineUser;
    QLineEdit* m_linePassword;
    QGridLayout* layout;
public:
    Dialog_sendMail_textEdit(QWidget* parent=0);
    virtual~ Dialog_sendMail_textEdit(){}
signals:
    void signalSaveEmail(QString&,
                         QString&,
                         QString&,
                         QString&,
                         QString&);
public slots:
    void slotCloseOK();
};

#endif // DIALOG_SENDMAIL_TEXTEDIT_H
