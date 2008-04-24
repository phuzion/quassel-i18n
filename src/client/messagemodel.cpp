/***************************************************************************
 *   Copyright (C) 2005-08 by the Quassel IRC Team                         *
 *   devel@quassel-irc.org                                                 *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) version 3.                                           *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "messagemodel.h"

MessageModel::MessageModel(QObject *parent) : QAbstractItemModel(parent) {
  
  
  
}

MessageModel::~MessageModel() {
  
  
}

QVariant MessageModel::data(const QModelIndex &index, int role) const {
  int row = index.row();
  if(row < 0 || row >= _messageList.count()) return QVariant();
  return _messageList[row]->data(index.column(), role);
}

bool MessageModel::setData(const QModelIndex &index, const QVariant &value, int role) {
  int row = index.row();
  if(row < 0 || row >= _messageList.count()) return false;
  if(_messageList[row]->setData(index.column(), role)) {
    emit dataChanged(index, index); // FIXME make msg emit this (too)
    return true;
  }
  return false;
}

void MessageModel::insertMessage(const Message &msg) {
  MsgId id = msg.msgId();
  MessageItem *item = createMessageItem(msg);
  if(id > )
    
}

// returns index of msg with given Id or of the next message after that (i.e., the index where we'd insert this msg)
int MessageModel::indexForId(MsgId id) {
  if(!_messageList.count() || id <= _messageList[0]->data(0, MsgIdRole).value<MsgId>()) return 0;
  if(id > _messageList.last()->data(0, MsgIdRole).value<MsgId>()) return _messageList.count();
  // binary search
  int start = 0; int end = _messageList.count()-1;
  int idx;
  while(1) {
    if(start == end) return start;
    idx = (end + start) / 2;
    
}

/**********************************************************************************/

