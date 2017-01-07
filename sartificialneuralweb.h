#ifndef SARTIFICIALNEURALWEB_H
#define SARTIFICIALNEURALWEB_H

#include <QMainWindow>

namespace Ui {
class SArtificialNeuralWeb;
}

class SArtificialNeuralWeb : public QMainWindow
{
    Q_OBJECT

public:
    explicit SArtificialNeuralWeb(QWidget *parent = 0);
    ~SArtificialNeuralWeb();

private:
    Ui::SArtificialNeuralWeb *ui;
};

#endif // SARTIFICIALNEURALWEB_H
