import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

Item {
    id: item1
    width: 640
    height: 480

    property alias exit: exit
    property alias lines: lines.text
    property alias words: words.text
    property alias dictionary: unique_list.model

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
        id: lines_label
        text: qsTr("Number of lines:")
        anchors.top: summary.bottom
        anchors.topMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 10
        font.pointSize: 40
        textFormat: Text.AutoText
    }

    Label {
        id: words_label
        text: qsTr("Number of unique words:")
        anchors.top: lines_label.bottom
        anchors.topMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 10
        font.pointSize: 40
    }

    Label {
        id: words
        x: 333
        text: "0"
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.top: lines.bottom
        anchors.topMargin: 10
        font.pointSize: 40
    }

    Label {
        id: lines
        x: 333
        text: "0"
        anchors.top: summary.bottom
        anchors.topMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 10
        font.pointSize: 40
    }

    Label {
        id: summary
        x: 199
        color: "#0c7818"
        text: qsTr("Summary")
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        style: Text.Sunken
        font.bold: true
        font.pointSize: 20
    }

    GridView {
        id: unique_list
        cellWidth: 80
        cellHeight: 20
        anchors.rightMargin: 10
        anchors.leftMargin: 10
        anchors.bottomMargin: 10
        anchors.top: words_label.bottom
        anchors.right: parent.right
        anchors.bottom: exit.top
        anchors.left: parent.left
        anchors.topMargin: 10
        delegate: Text {
            text: modelData
            font.bold: true
            font.pixelSize: 15
            elide: Text.ElideRight
            width: unique_list.cellWidth
            height: unique_list.cellHeight
        }
    }
}

