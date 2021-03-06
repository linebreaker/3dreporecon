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

#pragma once

#include <QList>
#include <QJsonDocument>
#include <QJsonArray>
#include "repo_node.h"

namespace repo {

class RepoJsonParser: public QObject
{
    Q_OBJECT

public:

    static QList<QVariant> read(const QString &filepath);

    static void write(const QList<QVariant> &list,
                      const QString &filepath,
                      QJsonDocument::JsonFormat format = QJsonDocument::Indented);

};

}
