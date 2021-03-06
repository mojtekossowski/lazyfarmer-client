import QtQuick 2.11
import QtQuick.Layouts 1.3

import QtQuick.Controls 2.4
import QtQuick.Controls.Material 2.3

import QtGraphicalEffects 1.0

import "Views"
import "Items"
import "Dialogs"

import Common 1.0

ApplicationWindow {
    id: root;

    visible: true

    minimumHeight: 575;
    minimumWidth: 420;

    Material.theme: Material.Light;
    Material.primary: Material.color(Material.Green);
    Material.accent: Material.color(Material.LightGreen);

    title: Qt.application.name + ' v. ' + Qt.application.version;

    header: MainToolbar {
        id: topMenu

        enabled: !dialogContainer.visible;

        stack: stack;

        onMenuClicked: {
            sideMenu.visible = true;
        }

    }

    SideMenu {
        id: sideMenu;

        width: 0.65 * root.width;
        height: root.height;
    }


    Rectangle {
        id: dialogContainer

        visible: loginDialog.visible;

        anchors.fill: parent;
        z: 1;

        color: Qt.rgba(0.2, 0.2, 0.2, 0.9);

        LoginDialog {
            id: loginDialog

            x: (dialogContainer.width  - loginDialog.width) / 2
            y: (dialogContainer.height - loginDialog.height) / 2
        }

        FastBlur {
            anchors.fill: parent
            source: stack
            radius: Stylesheet.defaultBlurRadius;
        }

    }

    StackView {
        id: stack

        enabled: !dialogContainer.visible;

        anchors.fill: parent;

        initialItem: AccountsView {
            loginDialog: loginDialog;
        }

        Component.onCompleted: function () {
            LazyFarmer.pushToStack.connect(function(qml, data) {
                var widget = Qt.createComponent(qml);
                if (widget.status === Component.Ready) {
                    var object = widget.createObject(stack, data)

                    stack.push(object, {
                        destroyOnPop: true
                    });

                } else {
                    console.error(widget.errorString())
                }
            });
        }

    }

    footer: Item {
        visible: LazyFarmer.isDebugMode()

        Text {
            anchors.bottom: parent.bottom;
            anchors.left: parent.left;
            anchors.margins: Stylesheet.defaultMargin;

            text: root.width + ' x ' + root.height;
        }

    }

}
