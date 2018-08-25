import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

Item {
    id: item1
    width: 640
    height: 480

    property alias exit: exit
    property alias stop: stop
    property alias lines: lines.text
    property alias words: words.text
    property alias uniqueWord: unique_word.text

    Button {
        id: stop
        x: 210
        y: 435
        text: qsTr("Stop")
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

    Label {
        id: number_lines_label
        text: qsTr("Number of lines:")
        anchors.left: parent.left
        font.pointSize: 40
        textFormat: Text.AutoText
        anchors.top: scan.bottom
        anchors.leftMargin: 10
        anchors.topMargin: 10
    }

    Label {
        id: number_unique_words_label
        x: 4
        y: 4
        text: qsTr("Number of unique words:")
        anchors.left: parent.left
        font.pointSize: 40
        anchors.top: number_lines_label.bottom
        anchors.leftMargin: 10
        anchors.topMargin: 10
    }

    Label {
        id: words
        x: 333
        text: "0"
        anchors.right: parent.right
        font.pointSize: 40
        anchors.top: lines.bottom
        anchors.topMargin: 10
        anchors.rightMargin: 10
    }

    Label {
        id: lines
        x: 337
        text: "0"
        anchors.right: parent.right
        font.pointSize: 40
        anchors.top: scan.bottom
        anchors.topMargin: 10
        anchors.rightMargin: 10
    }

    Label {
        id: unique_word
        color: "#d30d0d"
        text: qsTr("")
        font.pointSize: 50
        textFormat: Text.PlainText
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.rightMargin: 10
        anchors.leftMargin: 10
        anchors.bottomMargin: 10
        anchors.top: number_unique_words_label.bottom
        anchors.right: parent.right
        anchors.bottom: exit.top
        anchors.left: parent.left
        anchors.topMargin: 10
    }
}

