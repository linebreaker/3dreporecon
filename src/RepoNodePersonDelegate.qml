/**
*  Copyright (C) 2017 3D Repo Ltd
*
*  This program is free software: you can redistribute it and/or modify
*  it under the terms of the GNU Affero General Public License as
*  published by the Free Software Foundation, either version 3 of the
*  License, or (at your option) any later version.
*
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU Affero General Public License for more details.
*
*  You should have received a copy of the GNU Affero General Public License
*  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.0
import repo 1.0
import QtGraphicalEffects 1.0
import QtQuick.Controls.Styles 1.4

import QtQuick.Dialogs 1.0

Item {
    width: nodePersonListView.width
    height: nodePersonListView.height



        Flickable {
            width: parent.width
            height: parent.height
            contentHeight: img.height + grid.height + 60



            RepoModelItemPainter {
                id: img
                Binding on image {
                    when: model.image !== "undefined"
                    value: model.image
                }
                width: 200
                height: 200
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.topMargin: 20
                anchors.top: parent.top
            }

            Grid {
                id: grid
                columns: 1
                anchors.top: img.bottom
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.topMargin: 10
                spacing: 10
                width: parent.width - 60

                TextField {
                    id: nameField
                    width: parent.width
                    placeholderText: qsTr("Name")
                    text: firstName
                    font.pointSize: 12
                    onTextChanged: {
                        repoModel.setData(index, text, "firstName")
                    }
                }

                TextField {
                    text: jobTitle
                    placeholderText: qsTr("Job Title")
                    width: parent.width
                    anchors.topMargin: 2
                    font.pointSize: 10
                    //            color: "grey"
                    onTextChanged: {
                        repoModel.setData(index, text, "jobTitle")
                    }
                }

                TextField {
                    text: organisation
                    placeholderText: qsTr("Organisation")
                    width: parent.width
                    anchors.topMargin: 2
                    font.pointSize: 10
                    //            color: "grey"
                    onTextChanged: {
                        repoModel.setData(index, text, "organisation")
                    }
                }

                TextField {
                    text: email
                    placeholderText: qsTr("Email")
                    width: parent.width
                    anchors.topMargin: 2
                    font.pointSize: 10
                    onTextChanged: {
                        repoModel.setData(index, text, "email")
                    }
                }

                TextField {
                    text: mobile
                    placeholderText: qsTr("Mobile")
                    width: parent.width
                    anchors.topMargin: 2
                    font.pointSize: 10
                    onTextChanged: {
                        repoModel.setData(index, text, "mobile")
                    }
                }

                TextField {
                    text: work
                    placeholderText: qsTr("Work")
                    width: parent.width
                    anchors.topMargin: 2
                    font.pointSize: 10
                    onTextChanged: {
                        repoModel.setData(index, text, "work")
                    }
                }

                TextArea {
                    text: notes
                    placeholderText: qsTr("Notes")
                    width: parent.width
                    anchors.topMargin: 2
                    wrapMode: TextEdit.Wrap

                    font.pointSize: 10
                    onTextChanged: {
                        repoModel.setData(index, text, "notes")
                    }
                }
            }
            ScrollIndicator.vertical: ScrollIndicator { }
        }

//        MouseArea {

//            anchors.fill: parent
//            onClicked: nodePersonListView.currentIndex = index
//    }

    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        visible: false
        nameFilters: [ "Image files (*.jpg *.png)", "All files (*)" ]
        onAccepted: {
            console.log("You chose: " + fileDialog.fileUrls)
        }
        onRejected: {
            console.log("Canceled")
        }
    }

}