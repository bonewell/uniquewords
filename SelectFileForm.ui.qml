import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1
import QtQuick.Dialogs 1.0
import Qt.labs.folderlistmodel 2.1

Item {
    id: item1
    width: 640
    height: 480

    property alias exit: exit
    property alias next: next
    property alias select: select
    property alias url: file_text.text
    property alias files: fileDialog

    Button {
        id: next
        x: 210
        y: 435
        text: qsTr("Next")
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
        id: select_file
        x: 379
        color: "#0c7818"
        text: "File"
        font.pointSize: 20
        anchors.top: parent.top
        anchors.topMargin: 10
        style: Text.Sunken
        font.bold: true
        anchors.horizontalCenter: parent.horizontalCenter
    }

    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        folder: shortcuts.home
    }

    Label {
        id: file_label
        text: qsTr("File: ")
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: select_file.bottom
        anchors.topMargin: 10
        font.pointSize: 40
    }

    TextField {
        id: file_text
        y: 228
        width: 409
        height: 40
        anchors.right: select.left
        anchors.rightMargin: 309
        anchors.verticalCenter: file_label.verticalCenter
        anchors.left: file_label.right
        anchors.leftMargin: 10
        placeholderText: qsTr("")
    }

    Button {
        id: select
        x: 437
        y: 71
        text: qsTr("Select...")
        anchors.verticalCenter: file_label.verticalCenter
        anchors.right: parent.right
        anchors.rightMargin: 10
    }
}
