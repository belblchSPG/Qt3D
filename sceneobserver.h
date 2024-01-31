#ifndef SCENEOBSERVER_H
#define SCENEOBSERVER_H

#include <QToolBar>
#include <QLabel>
#include <QPushButton>

class SceneObserver : public QToolBar
{
    Q_OBJECT
public:
    explicit SceneObserver(QWidget* parent = nullptr);
};

#endif // SCENEOBSERVER_H
