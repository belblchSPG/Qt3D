#ifndef WINDOWSMANAGER_H
#define WINDOWSMANAGER_H

#include "inputwindowlwhc.h"

#include <QFileDialog>

//Класс, к которому обращаются для генерации окон
//Пока не используется
class WindowsManager
{
public:
    WindowsManager();

    InputWindowLWHC* GenerateCuboidByLWHCWindow(QWidget*);
};

#endif // WINDOWSMANAGER_H
