#ifndef SERIAL_PORT_TRANSCEIVER_H
#define SERIAL_PORT_TRANSCEIVER_H

#include "abstract_transceiver.h"

class QSerialPort;

namespace domain
{
    class SerialPortTransceiver: public AbstractTransceiver
    {
        Q_OBJECT

    public:
        SerialPortTransceiver(const QString& device, QObject* parent = nullptr);

    public slots:
        void transmit(const QByteArray& packet) override;

    private slots:
        void readSerialData();

    private:
        QSerialPort* m_port;
    };
}

#endif // SERIAL_PORT_TRANSCEIVER_H
