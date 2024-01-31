#ifndef MENUBAR_H
#define MENUBAR_H

#include "appwindow.h"

#include <QWidget>
#include <QMenuBar>
#include <QPushButton>
#include <memory>

class AppWindow;

//Класс используется для создания меню бара приложения
class MenuBar : public QWidget
{
    Q_OBJECT

public:
    explicit MenuBar(AppWindow* parent);

    QMenuBar *getMenuBar() const;

private:
    std::unique_ptr<QMenuBar> _menuBar;
};

#endif // MENUBAR_H
