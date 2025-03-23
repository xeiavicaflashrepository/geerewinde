/*
Copyright (C) 2025 - Matthew Polk.

This file is part of geerewinde.

Geerewinde is free software: you can redistribute it and/or modify it under the
terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later version.

Geerewinde is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with geerewinde.
If not, see <https://www.gnu.org/licenses/>. 
*/

#include <gtk/gtk.h>

// Menubar and Menus
static void menuinterface(GtkApplication *App) {
    GMenu *menubar = g_menu_new();
    GMenu *menuitem = g_menu_new();

    static GActionEntry actions[] = {
        { "quit", NULL, NULL, NULL, NULL }
    };

    g_menu_append(menuitem, "Menu", "actions.quit");
    g_menu_append_section(menubar, "File", G_MENU_MODEL(menuitem));
    g_object_unref(menuitem);

    gtk_application_set_menubar(GTK_APPLICATION(App), G_MENU_MODEL(menubar));
}

// Text box area
static void txtbox(GtkWidget *Win) {
    GtkWidget *Viewer = gtk_text_view_new();
    GtkTextBuffer *Buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(Viewer));

    gtk_text_buffer_set_text(Buffer, "", -1);
    gtk_window_set_child(GTK_WINDOW(Win), Viewer);
}



// Ran every single time a new application is started.
static void activation(GtkApplication *App, gpointer userdata) {
    GtkWidget *Window = gtk_application_window_new(App);
    txtbox(Window);

    gtk_window_set_title(GTK_WINDOW(Window), "Geerewinde");
    gtk_window_set_default_size(GTK_WINDOW(Window), 800, 600);
    gtk_window_present(GTK_WINDOW(Window));
}

int main(int argc, char *argv[]) {
    // Turn off the client side decorations
    g_setenv("GTK_CSD", "0", 0);
    
    // Now for the rest of the application.
    GtkApplication *App = gtk_application_new("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(App, "activate", G_CALLBACK(activation), NULL);

    int status = g_application_run(G_APPLICATION(App), argc, argv);

    // Setup the menu
    g_signal_connect(App, "startup", G_CALLBACK(menuinterface), NULL);

    g_object_unref(App);

    return status;
}
