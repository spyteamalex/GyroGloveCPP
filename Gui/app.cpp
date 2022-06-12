//
// Created by spyteamalex on 12.06.22.
//

#include "app.h"

App::App(QWidget *parent) : QObject(parent), trayIcon(QSystemTrayIcon(this)) {
    trayIcon.setIcon(QIcon("./../Resources/icon.png"));
//    QMenu * menu = new QMenu(this);
//    QAction * viewWindow = new QAction(trUtf8("Развернуть окно"), this);
//    QAction * quitAction = new QAction(trUtf8("Выход"), this);

    /* подключаем сигналы нажатий на пункты меню к соответсвующим слотам.
     * Первый пункт меню разворачивает приложение из трея,
     * а второй пункт меню завершает приложение
     * */
//    connect(viewWindow, SIGNAL(triggered()), this, SLOT(show()));
//    connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));
//
//    menu->addAction(viewWindow);
//    menu->addAction(quitAction);

    /* Устанавливаем контекстное меню на иконку
     * и показываем иконку приложения в трее
     * */
//    trayIcon->setContextMenu(menu);
    trayIcon.show();
}

App::~App() {
//    delete trayIcon;
}
