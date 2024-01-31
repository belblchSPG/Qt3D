#include "menubar.h"

MenuBar::MenuBar(AppWindow *parent)
    : QWidget{parent}
{
    _menuBar = std::make_unique<QMenuBar>(this);

    QMenu *project = new QMenu("Project",this);

    QAction *openSceneAction = new QAction("Open Scene", this);

    project->addAction(openSceneAction);

    _menuBar->addMenu(project);

    connect(openSceneAction, &QAction::triggered, this, [=](){
        QString fileName = QFileDialog::getOpenFileName(this, "Open File", "/home/", "Text Files (*.txt);;All Files (*.*)");
        parent->recieveFileName(fileName);
    });
}

QMenuBar *MenuBar::getMenuBar() const
{
    return _menuBar.get();
}
