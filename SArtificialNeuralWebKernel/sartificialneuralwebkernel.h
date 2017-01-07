#ifndef SARTIFICIALNEURALWEBKERNEL_H
#define SARTIFICIALNEURALWEBKERNEL_H

#include <QString>
#include <QVector>
#include <QMap>
#include <QDebug>

using NeuronMap = QVector< QVector< int > >;

struct NeuronAnswer
{
    QString id;
    QString name;
    int rate;
};

class SArtificialNeuralWebKernel
{
public:
    class Neuron
    {
    public:
        Neuron()
        {}

        Neuron( const QString& id, const QString& name, const NeuronMap& map )
        {}

        int overlap( const NeuronMap& map ) const
        {}

        void rateUp( const NeuronMap& map )
        {}

    private:
        int _rate;
        QString _id;
        QString _name;
        NeuronMap _map;
    };

    SArtificialNeuralWebKernel(){}

    QVector< NeuronAnswer > overlaps( const NeuronMap& map )
    {

    }

    void rateUpNeuron( const QString& id, const NeuronMap& map )
    {

    }

    void addNeuron( const QString& name, const NeuronMap& map )
    {

    }

    static NeuronMap neuronMapFromBitmap( const QBitmap& bitmap )
    {}

protected:
    QMap<QString, Neuron> _neuralWeb;
};

using SANWK = SArtificialNeuralWebKernel;

#endif // SARTIFICIALNEURALWEBKERNEL_H
