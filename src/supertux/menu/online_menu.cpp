//  SuperTux
//  Copyright (C) 2015 Matthew <thebatmankiller3@gmail.com>
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

#include "supertux/menu/online_menu.hpp"

#include "gui/menu_item.hpp"
#include "gui/menu_manager.hpp"
#include "supertux/game_manager.hpp"
#include "supertux/menu/menu_storage.hpp"
#include "supertux/world.hpp"
#include "util/gettext.hpp"

OnlineMenu::OnlineMenu()
{
   add_label(_("Online Mode"));
   add_hl();
   add_entry(LOGIN, _("Login"));
   add_entry(REGISTER, _("Register"));
   add_entry(SERVER_LIST, _("Server List"));
   add_hl();
   add_back(_("Back"));
}

void OnlineMenu::menu_action(MenuItem& item)
{
  switch (item.get_id())
  {
    case LOGIN:
	 MenuManager::instance().push_menu(MenuStorage::LOGIN_MENU);
	 break; 
    case REGISTER:
	 MenuManager::instance().push_menu(MenuStorage::REGISTER_MENU);
	 break;
    case SERVER_LIST:
	 MenuManager::instance().push_menu(MenuStorage::SERVER_LIST);
	 break;
  }
}

/* EOF */
