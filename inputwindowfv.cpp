#include "inputwindowfv.h"

InputWindowFV::InputWindowFV(QWidget *parent) : QDialog(parent)
    {
        setWindowTitle("Введите координаты");

        QGridLayout *layout = new QGridLayout(this);


        for (int row = 0; row < 4; ++row)
        {

            QVector<QLineEdit *> rowLineEdits; // Хранит LineEdits для текущей строки
            for (int col = 0; col < 3; ++col)
            {
                if(col == 0){
                    QLabel *label1 = new QLabel(QString("Координата %1").arg(row + 1), this);
                    QLabel *label2 = new QLabel(QString("                           X:"), this);
                    layout->addWidget(label1, row, col * 2);
                    layout->addWidget(label2, row, col * 2);
                }

                else if(col == 1)
                {
                    QLabel *label = new QLabel(QString("Y:"), this);
                    layout->addWidget(label, row, col * 2);
                }

                else
                {
                    QLabel *label = new QLabel(QString("Z:"), this);
                    layout->addWidget(label, row, col * 2);
                }

                QLineEdit *lineEdit = new QLineEdit(this);

                QDoubleValidator *validator = new QDoubleValidator();
                validator->setLocale(QLocale::C);

                lineEdit->setValidator(validator);


                layout->addWidget(lineEdit, row, col * 2 + 1);

                rowLineEdits.append(lineEdit);
            }
            coordinates.append(rowLineEdits);
        }

        QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, this);
        layout->addWidget(buttonBox, 5, 0, 1, 6);

        connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
        connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
    }

    QVector<QVector<QLineEdit *> > InputWindowFV::getCoordinatesLineEdits() const
    {
        qDebug() << "Window returned coordinates";
        return coordinates;
    }



    void InputWindowFV::accept()
    {
        qDebug() << 0;
        emit coordinatesReady(getCoordinatesLineEdits());
        this->close();
    }
