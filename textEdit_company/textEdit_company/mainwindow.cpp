#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setMinimumSize(330,330);
    setMaximumSize(330,330);
    //File
    m_actionNewFile=new QAction(this);
    m_actionNewFile->setText(tr("New File"));
    m_actionNewFile->setMenuRole(QAction::NoRole);
    m_actionNewFile->setShortcut(QKeySequence("CTRL+N"));
    m_actionNewFile->setToolTip("New Document");
    m_actionNewFile->setStatusTip("New File");
    m_actionNewFile->setWhatsThis("New File");
    m_actionNewFile->setIcon(QPixmap(":/rec/new file"));



    m_actionOpenFile=new QAction(this);
    m_actionOpenFile->setText(tr("Open File"));
    m_actionOpenFile->setMenuRole(QAction::NoRole);
    m_actionOpenFile->setShortcut(QKeySequence("CTRL+O"));
    m_actionOpenFile->setToolTip("Open Document");
    m_actionOpenFile->setStatusTip("Open File");
    m_actionOpenFile->setWhatsThis("Open File");
    m_actionOpenFile->setIcon(QPixmap(":/rec/open"));

    m_actionSaveFile=new QAction(this);
    m_actionSaveFile->setText(tr("Save File"));
    m_actionSaveFile->setMenuRole(QAction::NoRole);
    m_actionSaveFile->setShortcut(QKeySequence("CTRL+S"));
    m_actionSaveFile->setToolTip("Save Document");
    m_actionSaveFile->setStatusTip("Save File");
    m_actionSaveFile->setWhatsThis("Save File");
    m_actionSaveFile->setIcon(QPixmap(":/rec/save"));

    m_actionHowToSave=new QAction(this);
    m_actionHowToSave->setText(tr("Save File (how to save...)"));
    m_actionHowToSave->setMenuRole(QAction::NoRole);
    m_actionHowToSave->setToolTip("How to save Document");
    m_actionHowToSave->setShortcut(QKeySequence("Ctrl+Shift+S"));
    m_actionHowToSave->setStatusTip("How to Save...");
    m_actionHowToSave->setWhatsThis("How to Save...");
    m_actionHowToSave->setIcon(QPixmap(":/rec/save as"));

    m_actionSendEmail=new QAction(this);
    m_actionSendEmail->setText(tr("Send Email"));
    m_actionSendEmail->setMenuRole(QAction::NoRole);
    m_actionSendEmail->setToolTip("Send Email Document");
    m_actionSendEmail->setShortcut(QKeySequence("Ctrl+Shift+E"));
    m_actionSendEmail->setStatusTip("Send Email");
    m_actionSendEmail->setWhatsThis("Send Email");
    m_actionSendEmail->setIcon(QPixmap(":/rec/send email"));

    m_actionPrint=new QAction(this);
    m_actionPrint->setText(tr("Print"));
    m_actionPrint->setMenuRole(QAction::NoRole);
    m_actionPrint->setToolTip("Print Document");
    m_actionPrint->setShortcut(QKeySequence("CTRL+P"));
    m_actionPrint->setStatusTip("Print");
    m_actionPrint->setWhatsThis("Print");
    m_actionPrint->setIcon(QPixmap(":/rec/print"));
//////////////////////
    //Edit

    m_actionUp=new QAction(this);
    m_actionUp->setText(tr("Undo"));
    m_actionUp->setMenuRole(QAction::NoRole);
    m_actionUp->setToolTip("Undo");
    m_actionUp->setShortcut(QKeySequence("CTRL+Z"));
    m_actionUp->setStatusTip("Undo");
    m_actionUp->setWhatsThis("Undo");
    m_actionUp->setIcon(QPixmap(":/rec/undo"));

    m_actionDown=new QAction(this);
    m_actionDown->setText(tr("Redo"));
    m_actionDown->setMenuRole(QAction::NoRole);
    m_actionDown->setToolTip("Redo");
    m_actionDown->setShortcut(QKeySequence("Ctrl+Shift+Z"));
    m_actionDown->setStatusTip("Redo");
    m_actionDown->setWhatsThis("Redo");
    m_actionDown->setIcon(QPixmap(":/rec/redo"));

    m_actionCut=new QAction(this);
    m_actionCut->setText(tr("Cut"));
    m_actionCut->setMenuRole(QAction::NoRole);
    m_actionCut->setToolTip("Cut");
    m_actionCut->setShortcut(QKeySequence("Ctrl+X"));
    m_actionCut->setStatusTip("Cut");
    m_actionCut->setWhatsThis("Cut");
    m_actionCut->setIcon(QPixmap(":/rec/cut"));

    m_actionCopy=new QAction(this);
    m_actionCopy->setText(tr("Copy"));
    m_actionCopy->setMenuRole(QAction::NoRole);
    m_actionCopy->setToolTip("Copy");
    m_actionCopy->setShortcut(QKeySequence("CTRL+C"));
    m_actionCopy->setStatusTip("Copy");
    m_actionCopy->setWhatsThis("Copy");
    m_actionCopy->setIcon(QPixmap(":/rec/copy"));

    m_actionPaste=new QAction(this);
    m_actionPaste->setText(tr("Paste"));
    m_actionPaste->setMenuRole(QAction::NoRole);
    m_actionPaste->setToolTip("Paste");
    m_actionPaste->setShortcut(QKeySequence("Ctrl+V"));
    m_actionPaste->setStatusTip("Paste");
    m_actionPaste->setWhatsThis("Paste");
    m_actionPaste->setIcon(QPixmap(":/rec/paste"));


    m_actionTrash=new QAction(this);
    m_actionTrash->setText(tr("Delete"));
    m_actionTrash->setMenuRole(QAction::NoRole);
    m_actionTrash->setToolTip("Delete");
    m_actionTrash->setShortcut(QKeySequence("Del"));
    m_actionTrash->setStatusTip("Delete");
    m_actionTrash->setWhatsThis("Delete");
    m_actionTrash->setIcon(QPixmap(":/rec/trash"));

//Settings
    m_actionSettings=new QAction(this);
    m_actionSettings->setText(tr("Settings"));
    m_actionSettings->setMenuRole(QAction::NoRole);
    m_actionSettings->setToolTip("Settings Document");
    m_actionSettings->setShortcut(QKeySequence("Ctrl+,"));
    m_actionSettings->setStatusTip("Settings");
    m_actionSettings->setWhatsThis("Settings");
    m_actionSettings->setIcon(QPixmap(":/rec/settings"));
//Quit
    m_actionAboutQt=new QAction(this);
    m_actionAboutQt->setText(tr("About Qt..."));
    m_actionAboutQt->setMenuRole(QAction::NoRole);
    m_actionAboutQt->setToolTip("About Qt");
    m_actionAboutQt->setShortcut(QKeySequence("Ctrl+Shift+A"));
    m_actionAboutQt->setStatusTip("About Qt");
    m_actionAboutQt->setWhatsThis("About Qt");
    m_actionAboutQt->setIcon(QPixmap(":/rec/faq"));

    m_actionQuit=new QAction(this);
    m_actionQuit->setText(tr("Quit"));
    m_actionQuit->setMenuRole(QAction::NoRole);
    m_actionQuit->setToolTip("Quit");
    m_actionQuit->setShortcut(QKeySequence("Ctrl+Q"));
    m_actionQuit->setStatusTip("Quit");
    m_actionQuit->setWhatsThis("Quit");
    m_actionQuit->setIcon(QPixmap(":/rec/exit"));

    file_menu=new QMenu(tr("File"),this);
    file_menu->addAction(m_actionNewFile);
    file_menu->addSeparator();
    file_menu->addAction(m_actionOpenFile);
    file_menu->addAction(m_actionHowToSave);
    file_menu->addAction(m_actionSendEmail);
    file_menu->addAction(m_actionPrint);

    menu_edit=new QMenu(tr("Edit"),this);
    menu_edit->addAction(m_actionUp);
    menu_edit->addAction(m_actionDown);
    menu_edit->addSeparator();
    menu_edit->addAction(m_actionCut);
    menu_edit->addAction(m_actionCopy);
    menu_edit->addAction(m_actionPaste);
    menu_edit->addAction(m_actionTrash);

    menu_settings=new QMenu(tr("Settings"),this);
    menu_settings->addAction(m_actionSettings);

    quit_menu=new QMenu(tr("Quit"),this);
    quit_menu->addAction(m_actionAboutQt);
    quit_menu->addSeparator();
    quit_menu->addAction(m_actionQuit);

    addToolBar(Qt::TopToolBarArea,createToolBar());
    menuBar()->addMenu(file_menu);
    menuBar()->addMenu(menu_edit);
    menuBar()->addMenu(menu_settings);
    menuBar()->addMenu(quit_menu);

    m_frame=new Frame(this);
    setCentralWidget(m_frame);

    connect(m_actionNewFile,SIGNAL(triggered()),this,SLOT(slot_NewFile()));
    connect(m_actionOpenFile,SIGNAL(triggered()),this,SLOT(slot_OpenFile()));
    connect(m_actionSaveFile,SIGNAL(triggered()),this,SLOT(slot_SaveFile()));
    connect(m_actionHowToSave,SIGNAL(triggered()),this,SLOT(slot_HowToSaveFile()));
    connect(m_actionSendEmail,SIGNAL(triggered()),this,SLOT(slot_SendEmail()));
    connect(m_actionPrint,SIGNAL(triggered()),this,SLOT(slot_Print()));
    connect(m_actionQuit,SIGNAL(triggered()),this,SLOT(slot_Quit()));
    connect(m_actionAboutQt,SIGNAL(triggered()),this,SLOT(slot_AboutQt()));



    connect(this,SIGNAL(signalNewFile()),m_frame,SIGNAL(signalNewFileFrame()));
    connect(this,SIGNAL(signalOpenFileForTextEdit(QString&)),
            m_frame,SIGNAL(signalOpenFileTextEdit(QString&)));
    connect(this,SIGNAL(signalSaveFile(QString&)),
            m_frame,SIGNAL(signalSaveFile(QString&)));
    connect(this,SIGNAL(signalSaveFileDir(QString&)),
            m_frame,SIGNAL(signalSaveFileDir(QString&)));
}

QToolBar* MainWindow::createToolBar()
{
    m_menu=new QToolBar(this);
    m_menu->setMovable(false);
    m_menu->setSizePolicy(QSizePolicy::Preferred,
                          QSizePolicy::Minimum);
    m_menu->addAction(m_actionNewFile);
    m_menu->addSeparator();
    m_menu->addAction(m_actionOpenFile);
    m_menu->addAction(m_actionSaveFile);
    m_menu->addAction(m_actionHowToSave);
    m_menu->addAction(m_actionPrint);
    m_menu->addAction(m_actionSendEmail);
    m_menu->addAction(m_actionQuit);
    return m_menu;
}


MainWindow::~MainWindow()
{

}

void MainWindow::slot_NewFile()// Слот очистки блокнота
{
    emit signalNewFile();
}

void MainWindow::slot_OpenFile()// Слот открытия файла
{
    QString fileOpen=QFileDialog::getOpenFileName(0,"Open File","","*.txt");
    emit signalOpenFileForTextEdit(fileOpen);
}

void MainWindow::slot_SaveFile() // Слот быстрого сохранения
{
    if(!save_File_Dir.isEmpty()){
        emit signalSaveFile(save_File_Dir);
    }
    else{
        QMessageBox::warning(this,"Warning Dir","Дерриктория не выбрана !");
    }
}

void MainWindow::slot_HowToSaveFile()//слот сохранение как
{
    save_File_Dir=QFileDialog::getSaveFileName(this,tr("Save File"),"","Text files (*.txt);;XML files (*.xml)");
    emit signalSaveFileDir(save_File_Dir);
}

void MainWindow::slot_SendEmail()// Слот отправки сообщения
{
    dialogMail=new Dialog_sendMail_textEdit(this);
    dialogMail->setModal(true);
    connect(dialogMail,SIGNAL(signalSaveEmail(QString&,QString&,QString&,QString&,QString&)),m_frame
            ,SLOT(slotSendEmail(QString&,QString&,QString&,QString&,QString&)));
    dialogMail->exec();


}

void MainWindow::slot_Print()// Слот вывода печати на принтер
{

}

void MainWindow::slot_Quit()// слот закрытия приложения
{
    close();
}

void MainWindow::slot_AboutQt()// слот инфо про qt
{
    QMessageBox::aboutQt(this,"TextEdit");
}


