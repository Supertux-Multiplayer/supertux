//  SuperTux
//  Copyright (C) 2016 Hume2 <teratux.mail@gmail.com>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef HEADER_SUPERTUX_SUPERTUX_MENU_SERVER_LIST_HPP
#define HEADER_SUPERTUX_SUPERTUX_MENU_SERVER_LIST_HPP

#include "gui/menu.hpp"

class ServerList final : public Menu
{
public:
  ServerList();

  void menu_action(MenuItem& item) override;
  std::vector<std::string> split(std::string text,char splitter);

private:
  std::string username;
  std::string password;

private:
  ServerList(const ServerList&) = delete;
  ServerList& operator=(const ServerList&) = delete;
};

#endif

/* EOF */
