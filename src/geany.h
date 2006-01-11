/*
 *      geany.h - this file is part of Geany, a fast and lightweight IDE
 *
 *      Copyright 2006 Enrico Troeger <enrico.troeger@uvena.de>
 *
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * $Id$
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#ifndef PLAT_GTK
#   define PLAT_GTK 1
#endif

#ifndef GEANY_H
#define GEANY_H

#include "Scintilla.h"
#include "SciLexer.h"
#include "ScintillaWidget.h"

#include "tm_tagmanager.h"

#include "filetypes.h"

#define SSM(s, m, w, l) scintilla_send_message(s, m, w, l)

#define INLINE inline
//#define INLINE

#ifdef G_OS_WIN32
# include <windows.h>
# include <commdlg.h>
# define GEANY_WIN32
# define GEANY_DATA_DIR PACKAGE_DATA_DIR
#else
# define GEANY_DATA_DIR PACKAGE_DATA_DIR "/" PACKAGE
#endif


#define GEANY_HOME_DIR					g_get_home_dir()
#define GEANY_CODENAME					"Rebus"
#define GEANY_HOMEPAGE					"http://geany.uvena.de/"
#define GEANY_MAX_OPEN_FILES			25
#define GEANY_SESSION_FILES				15
#define GEANY_MAX_TAGS_COUNT			1000
#define GEANY_WORDCHARS					"_#&abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
#define GEANY_MAX_AUTOCOMPLETE_WORDS	30
#define GEANY_MSGWIN_HEIGHT				240
#define GEANY_STRING_UNTITLED			_("untitled")


#ifndef DOCDIR
# define DOCDIR PACKAGE_DATA_DIR"/doc/"PACKAGE"/html/"
#endif


/* structure for representing an open tab with all its related stuff. */
typedef struct document
{
	gboolean		 is_valid;
	gchar 			*file_name;
	gchar 			*encoding;
	filetype		*file_type;
	TMWorkObject	*tm_file;
	ScintillaObject	*sci;
	GtkWidget		*tab_label;
	GtkWidget		*tabmenu_label;
	GtkWidget		*tag_tree;
	GtkTreeStore	*tag_store;
	GtkTreeIter		 iter;
	gint 			 scid;
	gboolean		 readonly;
	gboolean		 changed;
	gboolean		 do_overwrite;
	gboolean		 line_breaking;
	time_t			 last_check;	// to remember the last disk check
	time_t			 mtime;
} document;



/* array of document elements to hold all information of the notebook tabs */
document doc_list[GEANY_MAX_OPEN_FILES];


/* store some pointers and variables for frequently used widgets  */
typedef struct MyApp
{
	gint			 	 toolbar_icon_style;
	// 0:x, 1:y, 2:width, 3:height
	gint				 geometry[4];
	gboolean			 debug_mode;
	// represents the state at startup while opening session files
	gboolean			 opening_session_files;
	// represents the state when Geany is quitting completely
	gboolean			 quitting;
	gboolean			 have_vte;
	gboolean			 ignore_global_tags;
	gboolean			 toolbar_visible;
	gboolean			 treeview_symbol_visible;
	gboolean			 treeview_openfiles_visible;
	gboolean			 msgwindow_visible;
	gboolean			 show_white_space;
	gboolean			 use_auto_indention;
	gboolean			 show_indent_guide;
	//gboolean			 line_breaking;
	gboolean			 show_line_endings;
	gboolean			 show_markers_margin;
	gboolean			 fullscreen;
	gboolean			 beep_on_errors;
	gboolean			 switch_msgwin_pages;
	gboolean			 auto_close_xml_tags;
	gboolean			 auto_complete_constructs;
	gboolean			 main_window_realized;
	gint				 pref_editor_tab_width;
	gboolean			 pref_editor_new_line;
	gboolean			 pref_editor_trail_space;
	gboolean			 pref_main_load_session;
	gboolean			 pref_main_save_winpos;
	gboolean			 pref_main_confirm_exit;
	gboolean			 pref_main_show_search;
	gint				 mru_length;
	gint				 long_line_column;
#ifdef HAVE_VTE
	gchar				*lib_vte;
#endif
	gchar				*long_line_color;
	gchar				*pref_template_developer;
	gchar				*pref_template_company;
	gchar				*pref_template_mail;
	gchar				*pref_template_initial;
	gchar				*pref_template_version;
	gchar				*editor_font;
	gchar				*tagbar_font;
	gchar				*msgwin_font;
	gchar				*configdir;
	gchar				*search_text;
	gchar				*terminal_settings;
	gchar				*build_args_inc;
	gchar				*build_args_libs;
	gchar				*build_args_prog;
	gchar				 build_make_custopt[256];
	gchar				*build_browser_cmd;
	gchar				*build_c_cmd;
	gchar				*build_cpp_cmd;
	/* I called it fpc (www.freepascal.org) to demonstrate I mean a pascal compiler,
	 * but feel free to use the GNU one as well */
	gchar				*build_fpc_cmd;
	gchar				*build_tex_dvi_cmd;
	gchar				*build_tex_pdf_cmd;
	gchar				*build_tex_view_dvi_cmd;
	gchar				*build_tex_view_pdf_cmd;
	gchar				*build_java_cmd;
	gchar				*build_javac_cmd;
	gchar				*build_make_cmd;
	gchar				*build_term_cmd;
	gchar			   **recent_files;
	GtkIconSize			 toolbar_icon_size;
	GtkWidget			*toolbar;
	GtkWidget			*compile_button;
	GtkWidget			*compile_button_image;
	GtkWidget			*tagbar;
	GtkWidget			*treeview_notebook;
	GtkWidget			*notebook;
	GtkWidget			*statusbar;
	GtkWidget			*window;
	GtkWidget			*popup_menu;
	GtkWidget			*toolbar_menu;
	GtkWidget			*new_file_menu;
	GtkWidget			*menu_insert_include_item[2];
	GtkWidget			*popup_goto_items[3];
	GtkWidget			*popup_items[4];
	GtkWidget			*menu_copy_items[4];
	GtkWidget			*redo_items[2];
	GtkWidget			*undo_items[2];
	GtkWidget			*save_buttons[2];
	GtkWidget			*sensitive_buttons[16];
	GtkWidget			*open_colorsel;
	GtkWidget			*open_fontsel;
	GtkWidget			*open_filesel;
	GtkWidget			*save_filesel;
	GtkWidget			*prefs_dialog;
	GtkWidget			*find_dialog;
	GtkWidget			*replace_dialog;
	GtkWidget			*build_menu_item_link;
	GtkWidget			*default_tag_tree;
	//GtkTreeStore		*default_tag_store;
	const TMWorkspace	*tm_workspace;
	GQueue				*recent_queue;
} MyApp;

MyApp *app;

gint this_year;
gint this_month;
gint this_day;


// small struct to track tag name and type together
typedef struct GeanySymbol
{
	gchar	*str;
	gint	 type;
} GeanySymbol;


enum
{
	GEANY_IMAGE_SMALL_CROSS,
	GEANY_IMAGE_LOGO,
	GEANY_IMAGE_COMPILE,
	GEANY_IMAGE_SAVE_ALL,
	GEANY_IMAGE_NEW_ARROW
};

enum {
	GEANY_RESPONSE_REPLACE = 1,
	GEANY_RESPONSE_REPLACE_ALL = 2,
	GEANY_RESPONSE_REPLACE_SEL = 3
};


enum
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

// prototype from tagmanager/parse.h, used in document.c, ugly but it works
extern langType getNamedLanguage(const char *const name);

// implementation in main.c
void geany_debug(gchar const *format, ...);

#endif
