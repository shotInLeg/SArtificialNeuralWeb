#include "sartificialneuralwebkernel.h"

NeuronAnswer::NeuronAnswer(const QString &id, const QString &name, int rate)
{
    this->id = id;
    this->name = name;
    this->rate = rate;
}
