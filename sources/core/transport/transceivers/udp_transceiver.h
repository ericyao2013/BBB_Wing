#ifndef UDP_TRANSCEIVER_H
#define UDP_TRANSCEIVER_H

#include "abstract_transceiver.h"

// Qt
#include <QtNetwork/QHostAddress>

class QUdpSocket;

namespace domain
{
    class UdpTransceiver: public AbstractTransceiver
    {
        Q_OBJECT

    public:
        UdpTransceiver(const QHostAddress& address, int port,
                       const QHostAddress& transmitAdress, int transmitPort,
                       QObject* parent = nullptr);

        QHostAddress transmitAdress() const;
        int transmitPort() const;

    public slots:
        void transmit(const QByteArray& packet) override;

        void setTransmitAdress(const QHostAddress& transmitAdress);
        void setTransmitPort(int transmitPort);

    private slots:
        void readPendingDatagrams();

    private:
        QUdpSocket* m_socket;
        QHostAddress m_transmitAdress;
        int m_transmitPort;
    };
}

#endif // UDP_TRANSCEIVER_H