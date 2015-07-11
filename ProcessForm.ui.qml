import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

Item {
    id: item1
    width: 640
    height: 480

    property alias exit: exit
    property alias back: back
    property alias lines: lines.text
    property alias words: words.text
    property alias dictionary : dictionary

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

    Label {
        id: scan
        x: 379
        color: "#0c7818"
        text: qsTr("Scanning")
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        style: Text.Sunken
        font.bold: true
        font.pointSize: 20
    }

    ListView {
        id: unique_list
        x: 453
        width: 200
        anchors.bottom: back.top
        anchors.bottomMargin: 10
        anchors.top: scan.bottom
        anchors.topMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 10
        delegate: Item {
            height: 15
            Text {
                text: name
                anchors.verticalCenter: parent.verticalCenter
                font.bold: true
                font.pixelSize: 10
            }
        }
        model: dictionary
    }

    ListModel {
        id: dictionary
    }

    Label {
        id: lines_label
        text: qsTr("Lines:")
        anchors.left: parent.left
        font.pointSize: 30
        textFormat: Text.AutoText
        anchors.top: scan.bottom
        anchors.leftMargin: 10
        anchors.topMargin: 10
    }

    Label {
        id: words_label
        x: 4
        y: 4
        text: qsTr("Unique words:")
        anchors.left: parent.left
        font.pointSize: 30
        anchors.top: lines_label.bottom
        anchors.leftMargin: 10
        anchors.topMargin: 10
    }

    Label {
        id: words
        x: 333
        text: "0"
        anchors.right: unique_list.left
        font.pointSize: 30
        anchors.top: lines.bottom
        anchors.topMargin: 10
        anchors.rightMargin: 10
    }

    Label {
        id: lines
        x: 337
        text: "0"
        anchors.right: unique_list.left
        font.pointSize: 30
        anchors.top: scan.bottom
        anchors.topMargin: 10
        anchors.rightMargin: 10
    }
}

