#ifndef INPUTWINDOWFV_H
#define INPUTWINDOWFV_H

#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QDoubleValidator>
#include <QLocale>
#include <QDebug>

class InputWindowFV : public QDialog
{
    Q_OBJECT

public:
    InputWindowFV(QWidget *parent = nullptr);

    QVector<QVector<QLineEdit *>> getCoordinatesLineEdits() const;

signals:

    void aboutToClose();
    void coordinatesReady(QVector<QVector<QLineEdit *>>);
    void resultReady(QVector<QVector<QLineEdit *>>);

protected:

    void accept() override;

private:
    QVector<QVector<QLineEdit *>> coordinates;
    QVector<float> _result = {1.0f,1.0f,1.0f,0.0f,0.0f,0.0f};
};

#endif // INPUTWINDOWFV_H
