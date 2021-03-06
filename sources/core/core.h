#ifndef CORE_H
#define CORE_H

#include <QStringList>

namespace topics // TODO: core to dynamic library
{
    const QString data = "data";
    const QString status = "st";
    const QString all = "";

    const QString altPacket = "data_alt";
    const QString insPacket = "data_ins";
    const QString snsPacket = "data_sns";

    const QString driveImpactsPacket = "data_drv";
    const QString controlPacket = "data_ctrl";
    const QString navigatorPacket = "data_navi";

    const QString automaticPacket = "data_auto";

    const QString directPacket = "data_direct";

    const QString reversePacket = "data_reverse";
    const QString reverseStatusPacket = "st_reverse";

    const QString connectionStatusPacket = "st_cn";

    const QStringList boardTopics = {
        altPacket, insPacket, snsPacket,
        navigatorPacket, controlPacket, driveImpactsPacket
    };
}

namespace endpoints
{
    const QString altimeter = "ipc://alt";
    const QString ins = "ipc://ins";
    const QString sns = "ipc://sns";

    const QString navigator = "ipc://navi";
    const QString flightPilot = "ipc://pilot";
    const QString flightDynamics = "ipc://flight";

    const QString player = "ipc://player";

    const QString boardTransceiver = "ipc://board_tr";
    const QString groundTransceiver = "ipc://ground_tr";

    const QString gui = "ipc://gui";
}

#endif // CORE_H
