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

#include "supertux/menu/login_menu.hpp"

#include "gui/dialog.hpp"
#include "gui/menu_item.hpp"
#include "gui/menu_manager.hpp"
#include "supertux/menu/menu_storage.hpp"
#include "supertux/world.hpp"
#include "util/gettext.hpp"
#include <cpr/cpr.h>

LoginMenu::LoginMenu() :
  username(),
  password()
{
  add_label(_("Login Menu"));
  add_hl();

  add_textfield(_("Username"), &username);
  add_textfield(_("Password"), &password);

  add_entry(1,_("Login"));

  add_hl();
  add_back(_("Back"));
}

void
LoginMenu::LoginAction(MenuItem& item)
{
  if (item.get_id() <= 0)
    return;

  if (username.empty() or password.empty())
  {
    Dialog::show_message(_("Please your username and password."));
    return;
  }

  cpr::Response r = cpr::Post(cpr::Url{"http://85.215.95.235:22223/login"},
                   cpr::Payload{{"login", username},{"password", password}});

  Dialog::show_message(_(r.text));
  MenuManager::instance().pop_menu();
  MenuManager::instance().push_menu(MenuStorage::MAIN_MENU);
}

/* EOF */
