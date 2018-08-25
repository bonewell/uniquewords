import QtQuick 2.4
import QtQuick.Controls 1.3
import Counter 1.0

ApplicationWindow {
    id: appWindow
    title: qsTr("Unique words")
    width: 640
    height: 480
    visible: true

    SelectFileForm {
        id: selectFile
        anchors.fill: parent
        next.onClicked: {
            process.visible = true;
            visible = false;
            counter.run(url);
        }
        exit.onClicked: Qt.quit();
        select.onClicked: files.visible = true
        url: files.fileUrl
    }

    ProcessForm {
        id: process
        anchors.fill: parent
        visible: false
        lines: counter.lines
        words: counter.words
        uniqueWord: counter.uniqueWord
        stop.onClicked: counter.stop();
        exit.onClicked: {
            counter.stop();
            Qt.quit();
        }
    }

    ResultForm {
        id: result
        anchors.fill: parent
        visible: false
        exit.onClicked: Qt.quit();
    }

    Counter {
        id: counter
        timeout: 50
        onFinished: {
            console.debug("FINISHED");
            show();
        }
        onCancelled: {
            console.debug("CANCELLED");
            show();
        }
        function show() {
            result.lines = lines
            result.words = words
            result.dictionary = dict
            result.visible = true;
            process.visible = false;
        }
    }
}
