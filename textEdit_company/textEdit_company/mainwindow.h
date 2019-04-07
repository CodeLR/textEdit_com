#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <frame.h>
#include <QAction>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QLineEdit>
#include <QPushButton>
#include <string.h>
#include "dialog_sendmail_textedit.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QAction *m_actionNewFile;
    QAction *m_actionOpenFile;
    QAction *m_actionSaveFile;
    QAction *m_actionHowToSave;
    QAction *m_actionSendEmail;
    QAction *m_actionPrint;

    QAction *m_actionUp;
    QAction *m_actionDown;
    QAction *m_actionCut;
    QAction *m_actionCopy;
    QAction *m_actionPaste;
    QAction *m_actionTrash;

    QAction *m_actionSettings;

    QAction *m_actionQuit;
    QAction *m_actionAboutQt;

    QMenu *file_menu;
    QMenu *menu_edit;
    QMenu *menu_settings;
    QMenu *quit_menu;
    Frame *m_frame;
    QVBoxLayout *layout;
    QToolBar *m_menu;

    QFileDialog* file;
    QString save_File_Dir;
    Dialog_sendMail_textEdit* dialogMail;
public:
    MainWindow(QWidget *parent = 0);
    QToolBar* createToolBar();
    ~MainWindow();
signals:
    void signalNewFile();
    void signalOpenFileForTextEdit(QString&);
    void signalSaveFile(QString&);
    void signalSaveFileDir(QString&);
    void sendFrameEmailAddress(QString&);
public slots:
    void slot_NewFile();
    void slot_OpenFile();
    void slot_SaveFile();
    void slot_HowToSaveFile();
    void slot_SendEmail();
    void slot_Print();
    void slot_Quit();
    void slot_AboutQt();
};


#endif // MAINWINDOW_H
