#include "inputwindowlwhc.h"

InputWindowLWHC::InputWindowLWHC(QWidget *parent) : QDialog(parent)
{
    createWindow();
}

void InputWindowLWHC::createWindow()
    {
        setWindowTitle("Введите координаты");

        QGridLayout *layout = new QGridLayout(this);
        for (int row = 0; row < 2; ++row)
        {
           QVector<QLineEdit *> rowLineEdits; // Хранит LineEdits для текущей строки

            if(row == 0){

               for (int col = 0; col < 3; ++col){

               if(col == 0){
                   QLabel *label = new QLabel(QString("Ширина"), this);
                   layout->addWidget(label, row, col * 2);
                }

               else if(col == 1)
                {
                   QLabel *label = new QLabel(QString("Высота"), this);
                   layout->addWidget(label, row, col * 2);
                }

                else
                {
                    QLabel *label = new QLabel(QString("Длина"), this);
                    layout->addWidget(label, row, col * 2);
                }

                QLineEdit *lineEdit = new QLineEdit(this);

                QDoubleValidator *validator = new QDoubleValidator();
                validator->setBottom(0);
                validator->setLocale(QLocale::C);

                lineEdit->setValidator(validator);


                layout->addWidget(lineEdit, row, col * 2 + 1);

                rowLineEdits.append(lineEdit);
                }
            }
            else{
               for (int col = 0; col < 3; ++col){

               if(col == 0){
                   QLabel *label = new QLabel(QString("X"), this);
                   layout->addWidget(label, row, col * 2);
                }

               else if(col == 1)
                {
                   QLabel *label = new QLabel(QString("Y"), this);
                   layout->addWidget(label, row, col * 2);
                }

                else
                {
                    QLabel *label = new QLabel(QString("Z"), this);
                    layout->addWidget(label, row, col * 2);
                }

                QLineEdit *lineEdit = new QLineEdit(this);

                QDoubleValidator *validator = new QDoubleValidator();
                validator->setLocale(QLocale::C);

                lineEdit->setValidator(validator);


                layout->addWidget(lineEdit, row, col * 2 + 1);

                rowLineEdits.append(lineEdit);
               }
            }
            _result.append(rowLineEdits);
        }

        QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, this);
        layout->addWidget(buttonBox, 5, 0, 1, 6);

        connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
        connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
    }

void InputWindowLWHC::accept()
{
    for(int i = 0; i < _result.size(); ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            qDebug() << _result[i][j]->text();
        }
    }
    emit resultReady(_result);
    this->close();
}

