import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640; height: 480
    visible: true

    // A nice red rectangle
    Rectangle {
        width: 200; height: 200
        color: "red"
    }

    Rectangle {
        width: 200; height: 200
        color: "green"
        x: 100; y: 100

        Rectangle {
            width: 50; height: 50
            color: "blue"
            x: 100; y: 100
        }
    }

    title: qsTr("Hello World")
}
