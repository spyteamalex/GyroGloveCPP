//
// Created by spyteamalex on 22.06.22.
//

#include "app.h"
#include "global.h"

App::App(QObject *parent) : QObject(parent), trayIcon(this) {
    auto * viewWindow = new QAction(trUtf8("Развернуть окно"), this);
    auto * quitAction = new QAction(trUtf8("Выход"), this);
    menu.addAction(viewWindow);
    menu.addAction(quitAction);
    trayIcon.setContextMenu(&menu);
    trayIcon.show();
    //todo
    connect(&trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(showMenu()));
}

void App::showMenu() {
    menu.hideTearOffMenu();
    menu.showTearOffMenu();
}
