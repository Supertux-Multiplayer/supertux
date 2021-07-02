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

#include "supertux/menu/register_menu.hpp"

#include "editor/editor.hpp"
#include "gui/dialog.hpp"
#include "gui/menu_item.hpp"
#include "gui/menu_manager.hpp"
#include "supertux/menu/menu_storage.hpp"
#include "supertux/world.hpp"
#include "util/gettext.hpp"
#include "cpr/cpr.h"

RegisterMenu::RegisterMenu() :
  username(),
  password(),
  password_conf(),
  email(),
  email_conf()
{
  add_label(_("Registration"));
  add_hl();

  add_textfield(_("Username"), &username);
  add_textfield(_("Password"), &password);
  add_textfield(_("Password (confirm)"), &password_conf);
  add_textfield(_("Email"), &email);
  add_textfield(_("Email (confirm)"), &email_conf);

  add_entry(1,_("Register"));

  add_hl();
  add_back(_("Back"));
}

void
RegisterMenu::menu_action(MenuItem& item)
{
  if (item.get_id() <= 0)
    return;
  if (email!=email_conf)
  {
    Dialog::show_message(_("Email and confirmed Email not equal."));
    return;
  }
  else if (password!=password_conf)
  {
    Dialog::show_message(_("Password and confirmed Password not equal."));
    return;
  }
  cpr::Response r = cpr::Post(cpr::Url{"http://85.215.95.235:22223/register"},cpr::Payload{{"login", username},{"password", password},{"email",email}});
  std::string answ="Registration succeeded";
  std::string answ_wrong="Registration failed: Username already taken.";
  std::string res=r.text;
  if (r.text == answ_wrong)
  {
    Dialog::show_message(_("Username already taken."));
    return;
  }
  else if (r.text != answ)
  {
    Dialog::show_message(_(res));
    return;
  }
  else
  {
    Dialog::show_message("Registration succeeded!");
  }
  MenuManager::instance().pop_menu();
  MenuManager::instance().push_menu(MenuStorage::MAIN_MENU);
}

/* EOF */
