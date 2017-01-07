#ifndef SARTIFICIALNEURALWEBKERNEL_H
#define SARTIFICIALNEURALWEBKERNEL_H

#include <QString>
#include <QVector>
#include <QMap>
#include <QDebug>

using NeuronMap = QVector< QVector< int > >;

class SArtificialNeuralWebKernel
{
public:
    class Neuron
    {
    public:
        Neuron(){}
    private:
        int _rate;
        QString _id;
        QString _name;
        NeuronMap _map;
    };

    SArtificialNeuralWebKernel();
protected:
    QMap<QString, Neuron> _neuralWeb;
};

#endif // SARTIFICIALNEURALWEBKERNEL_H
