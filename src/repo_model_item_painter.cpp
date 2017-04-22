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

#include "repo_model_item_painter.h"

#include "repo_material_icons.h"

using namespace repo;

RepoModelItemPainter::RepoModelItemPainter(QQuickItem *parent)
    : QQuickPaintedItem(parent)
{

}

void RepoModelItemPainter::paint(QPainter *painter)
{
    int border = boundingRect().width() * 0.03;
    int gap = boundingRect().width() * 0.06;
    int innerCircle = border + gap;
    int icon = innerCircle + 10;

    int w = boundingRect().width();
    int h = boundingRect().height();

    painter->setRenderHint(QPainter::Antialiasing);


    // Border
    QPen p;
    p.setWidth(border);
    p.setColor(Qt::blue);
    painter->setPen(p);
    painter->setBrush(Qt::blue);
    painter->drawArc(border, border,
                     w - 2 * border,
                     h - 2 * border,
                     0, 5760);

    // Inner circle
    //    painter->drawEllipse(innerCircle, innerCircle, w - 2 * innerCircle, h - 2 * innerCircle);


    // Icon
    //    painter->setFont(RepoMaterialIcons::getInstance().getFont(w - 2 * icon));
    //    painter->setPen(QColor("#081028"));
    //    painter->drawText(QRectF(icon, icon, w - 2 * icon, h - 2 * icon), QChar(0xE7FD),
    //                      QTextOption(Qt::AlignCenter | Qt::AlignVCenter));

        QPainterPath path;
        path.addEllipse(innerCircle, innerCircle, w - 2 * innerCircle, h - 2 * innerCircle);
        painter->setClipPath(path);




    QRectF target(0, 0, w, h);
    QImage image(":/resources/alvise.jpg");

    painter->drawImage(target, image);




}