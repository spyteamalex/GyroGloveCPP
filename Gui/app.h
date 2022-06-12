//
// Created by spyteamalex on 12.06.22.
//

#ifndef GYROGLOVECPP_APP_H
#define GYROGLOVECPP_APP_H


#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QMenu>
#include "../global.h"

class App : public QObject{

    Q_OBJECT

public:
    virtual ~App();

    App(QWidget *parent);
private:
    QSystemTrayIcon trayIcon;
};


#endif //GYROGLOVECPP_APP_H
