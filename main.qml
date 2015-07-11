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
            counter.run("build_and_run_steps.txt");
        }
        exit.onClicked: Qt.quit();
    }

    ProcessForm {
        id: process
        anchors.fill: parent
        visible: false
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
        onLinesChanged: console.info("Lines: ", number)
        onWordsChanged: console.info("Words: ", number)
        onWordAdded: console.info("Unique word: ", word)
        onFinished: {
            result.visible = true;
            process.visible = false;
        }
    }
}
