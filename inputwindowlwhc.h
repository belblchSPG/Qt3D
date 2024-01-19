#ifndef INPUTWINDOWLWHC_H
#define INPUTWINDOWLWHC_H

#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QDoubleValidator>
#include <QLocale>
#include <QDebug>

class InputWindowLWHC : public QDialog
{
    Q_OBJECT

public:
    InputWindowLWHC(QWidget *parent = nullptr);

signals:

    void resultReady(QVector<QVector<QLineEdit *>>);

protected:

    void accept() override;

private:

    QVector<QVector<QLineEdit *>> _result;
    void createWindow();
};


#endif // INPUTWINDOWLWHC_H
