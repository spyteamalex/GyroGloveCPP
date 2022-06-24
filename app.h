//
// Created by spyteamalex on 22.06.22.
//

#ifndef GYROGLOVECPP_APP_H
#define GYROGLOVECPP_APP_H


#include <QObject>
#include <QSystemTrayIcon>
#include <QMenu>

class App : public QObject{
    Q_OBJECT

private:
    QMenu menu;
    QSystemTrayIcon trayIcon;

private slots:
    void showMenu();

public:
    explicit App(QObject *parent);
};


#endif //GYROGLOVECPP_APP_H
