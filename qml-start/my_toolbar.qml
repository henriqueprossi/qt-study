﻿import QtQuick 2.12
import QtQuick.Window 2.12

Rectangle {
    height: 50
    color: "gray"

        Rectangle {
            id: purpleRectangle
            width: 50; height: parent.height
            color: "purple"
            radius: 10
        }

        Text {
            anchors.left: purpleRectangle.right
            anchors.right: parent.right
            text: "Dominate the Mobile UI"
            font.pointSize: 30
        }
    }
}
