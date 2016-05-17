import QtQuick 2.6
import Qt.labs.controls 1.0

SpinBox {
    id: spinBox

    leftPadding: -background.implicitWidth / 2
    opacity: enabled ? 1 : 0.3

    background: Rectangle {
        implicitWidth: 32
        implicitHeight: 32
        color: palette.backgroundColor
    }

    contentItem: TextInput {
        text: textFromValue(spinBox.value, spinBox.locale)

        font: spinBox.font
        color: palette.textColor
        selectionColor: palette.highlightColor
        selectedTextColor: color
        horizontalAlignment: Qt.AlignHCenter
        verticalAlignment: Qt.AlignVCenter

        validator: spinBox.validator
        inputMethodHints: Qt.ImhFormattedNumbersOnly
    }

    down.indicator: Rectangle {
        x: spinBox.mirrored ? up.indicator.width :
                              spinBox.width - width - up.indicator.width
        height: spinBox.height
        implicitWidth: 32
        implicitHeight: 32
        color: down.pressed ? palette.highlightColor : "transparent"

        Image {
            anchors.centerIn: parent
            opacity: enabled ? 1 : 0.5
            source: "qrc:/resources/icons/minus.svg"
        }
    }

    up.indicator: Rectangle {
        x: spinBox.mirrored ? 0 : spinBox.width - width
        height: spinBox.height
        implicitWidth: 32
        implicitHeight: 32
        color: up.pressed ? palette.highlightColor : palette.transparent

        Image {
            anchors.centerIn: parent
            opacity: enabled ? 1 : 0.5
            source: "qrc:/resources/icons/plus.svg"
        }
    }
}

