import QtQuick.Controls 1.3
import Counter 1.0

ApplicationWindow {
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

        back.onClicked: {
            counter.stop();
            selectFile.visible = true;
            visible = false;
        }

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
        onWordAdded: process.dictionary.append({name: word})
        onFinished: {
            console.debug("FINISHED");
            result.lines = lines
            result.words = words
            result.visible = true;
            process.visible = false;
        }
    }
}
