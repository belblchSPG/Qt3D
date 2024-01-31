#include "windowsmanager.h"

WindowsManager::WindowsManager() {}

InputWindowLWHC* WindowsManager::GenerateCuboidByLWHCWindow(QWidget* widget)
{
    return new InputWindowLWHC(widget);
}


