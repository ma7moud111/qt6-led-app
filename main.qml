import QtQuick
import QtQuick.Controls

ApplicationWindow {
    visible: true
    width: 360; height: 200
    title: "LED Control"

    Column {
        anchors.centerIn: parent
        spacing: 16

        Switch {
            id: ledSwitch
            checked: ledController.on
            text: checked ? "LED: ON" : "LED: OFF"
            onToggled: ledController.setOn(checked)
        }

        Text { text: ledController.switchPressed ? "SW: PRESSED" : "SW: RELEASED" }
    }

    Timer {
        interval: 200; running: true; repeat: true
        onTriggered: ledController.refreshSwitch()
    }
}
