#ifndef WINDOWSMANAGER_H
#define WINDOWSMANAGER_H

#include "inputwindowlwhc.h"

//Класс, к которому обращаются для генерации окон
class WindowsManager
{
public:
    WindowsManager();

    InputWindowLWHC* GenerateCuboidByLWHCWindow(QWidget*);
};

#endif // WINDOWSMANAGER_H
