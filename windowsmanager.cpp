#include "windowsmanager.h"

WindowsManager::WindowsManager() {}

InputWindowLWHC* WindowsManager::GenerateCuboidByLWHCWindow(QWidget* scene)
{
    return new InputWindowLWHC(scene);
}
