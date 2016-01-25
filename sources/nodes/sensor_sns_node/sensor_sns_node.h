#ifndef SENSOR_SNS_NODE_H
#define SENSOR_SNS_NODE_H

#include "abstract_node_frequency.h"

namespace domain
{
    class SensorSnsNode: public AbstractNodeFrequency
    {
    public:
        SensorSnsNode(QObject* parent = nullptr);
        ~SensorSnsNode() override;

        void init() override;
        void exec() override;

    private:
        class Impl;
        Impl* const d;
    };
}

#endif // SENSOR_SNS_NODE_H