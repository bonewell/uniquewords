import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

Item {
    width: 640
    height: 480

    property alias exit: exit
    property alias back: back

    Button {
        id: back
        x: 210
        y: 435
        text: qsTr("Back")
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.right: parent.right
        anchors.rightMargin: 10
    }

    Button {
        id: exit
        y: 453
        text: qsTr("Exit")
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 10
    }
}

