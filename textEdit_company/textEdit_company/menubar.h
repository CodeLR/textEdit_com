#ifndef MENUBAR_H
#define MENUBAR_H

#include <QMenuBar>
#include <QAction>
#include <QMenu>
#include <QToolBar>

class MenuBar:public QMenuBar
{
private:
    QToolBar *toolBar;
public:
    MenuBar(QWidget *parent=0);
    virtual ~MenuBar(){}
};

#endif // MENUBAR_H
