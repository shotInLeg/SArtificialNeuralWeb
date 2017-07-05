#ifndef SARTIFICIALNEURALWEBKERNEL_H
#define SARTIFICIALNEURALWEBKERNEL_H

#include <QString>
#include <QVector>
#include <QMap>
#include <QImage>
#include <QRgb>
#include <QColor>
#include <QDebug>

#include <cmath>

using NeuronMap = QVector< QVector< int > >;

struct NeuronAnswer
{
    QString id;
    QString name;
    int rate;

    NeuronAnswer(){}

    NeuronAnswer( const QString& id, const QString& name, int rate );
};

class SArtificialNeuralWebKernel
{
public:
    class Neuron
    {
    public:
        Neuron()
        {}

        Neuron( const QString& id, const QString& name, const NeuronMap& map );

        QString id() const;

        QString name() const;

        int overlap( const NeuronMap& map ) const;

        void extendNeuronMap( const NeuronMap& map );

    private:
        QString _id;
        QString _name;
        NeuronMap _map;
    };

public:

    SArtificialNeuralWebKernel(){}

    QVector< NeuronAnswer > overlaps( const NeuronMap& map );
    void extendNeuron( const QString& id, const NeuronMap& map );
    void addNeuron( const QString& name, const NeuronMap& map );

    static NeuronMap neuronMapFromImage( const QImage& image );

protected:
    QMap<QString, Neuron> _neuralWeb;
};

using SANWK = SArtificialNeuralWebKernel;

#endif // SARTIFICIALNEURALWEBKERNEL_H
