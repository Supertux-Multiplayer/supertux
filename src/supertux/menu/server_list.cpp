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

#include "supertux/menu/server_list.hpp"

#include "editor/editor.hpp"
#include "gui/dialog.hpp"
#include "gui/menu_item.hpp"
#include "gui/menu_manager.hpp"
#include "supertux/menu/menu_storage.hpp"
#include "supertux/world.hpp"
#include "util/gettext.hpp"
#include "cpr/cpr.h"

ServerList::ServerList()
{
  add_label(_("Server List"));
  add_hl();

  cpr::Response r = cpr::Get(cpr::Url{"http://85.215.95.235:22224/data"});
  //char spl1="\t";
  //char spl2="\n";
  std::vector<std::string> v1 = ServerList::split(r.text,'\n');
  std::vector<std::string> ip;
  std::vector<std::string> port;
  for (int i=0;i<v1.size();i++)
  {
      std::vector<std::string> v2 = ServerList::split(v1[i],'\t');
      std::string text=v2[0]+" ("+v2[2]+"/"+v2[1]+")";
      ip.push_back(v2[3]);
      port.push_back(v2[4]);
      add_entry(i,_(text));
  }
  add_hl();
  add_back(_("Back"));
}

void
ServerList::menu_action(MenuItem& item)
{
  MenuManager::instance().push_menu(MenuStorage::MAIN_MENU);
}

std::vector<std::string> ServerList::split(std::string text, char splitter)
{
    std::vector<std::string> v1;
    std::string test="";
    for(int i=0;i<text.size();i++)
    {
        if (text[i]!=splitter) test+=text[i];
	else
	{
	    v1.push_back(test);
	    test="";
	}
    }
    if (test!="") v1.push_back(test);
    return v1;
}

/* EOF */
