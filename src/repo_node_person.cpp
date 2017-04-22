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

#include "repo_node_person.h"

using namespace repo;

QString RepoNodePerson::firstName() const
{
    return value("firstName", "<undefined>").toString();
}

QString RepoNodePerson::lastName() const
{
    return value("lastName", "<undefined>").toString();
}

QString RepoNodePerson::jobTitle() const
{
    return value("jobTitle").toString();
}

QUrl RepoNodePerson::linkedIn() const
{
    return value("linkedIn").toUrl();
}

QString RepoNodePerson::email() const
{
    return value("email").toString();
}
