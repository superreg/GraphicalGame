#include <gtk/gtk.h>
#include <gio/gio.h>
#include <glib.h>
#include "network.h"

int main(int argc, char** argv){
    GtkWidget *window;
    GtkWidget *mainBox, *topBox, *bottomBox, *topRightBox, *topLeftBox, *checkersRows[8];
    GtkWidget *bottomLeftBox, *bottomRightBox;
    GtkWidget *checkersGrid[8][8];
    const char *cssPath = "main.css";
    GFile *css;
    GtkCssProvider *cssProvider;
    GError **error;
    GtkStyleContext *opponentBoard, *playerBoard;
    int i, j;
    //initializing and packing
    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Checkers");
    gtk_window_set_default_size(GTK_WINDOW(window), 640, 640);
    mainBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 2);
    gtk_container_add(GTK_CONTAINER(window), mainBox);
    topBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 2);
    bottomBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 2);
    gtk_box_pack_start(GTK_BOX(mainBox), topBox, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(mainBox), bottomBox, TRUE, TRUE, 0);
    bottomLeftBox = gtk_event_box_new();
    bottomRightBox = gtk_event_box_new();
    gtk_box_pack_start(GTK_BOX(bottomBox), bottomLeftBox, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(bottomBox), bottomRightBox, TRUE, TRUE, 0);
    topLeftBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 1);
    topRightBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 2);
    gtk_box_pack_start(GTK_BOX(topBox), topLeftBox, TRUE, TRUE, 2);
    gtk_box_pack_start(GTK_BOX(topBox), topRightBox, TRUE, TRUE, 2);
    //initialize checkers board
    for(i = 0; i < 8; i++)
        for(j = 0; j < 8; j++)
            checkersGrid[i][j] = gtk_event_box_new();
    //initialize checkers rows
    for(i = 0; i < 8; i++)
        checkersRows[i] = gtk_box_new(GTK_ORIENTATION_VERTICAL, 1);
    //pack checkersGrid into checkersRows
    for(i = 0; i < 8; i++)
        for(j = 0; j < 8; j++)
            gtk_box_pack_start(GTK_BOX(checkersRows[i]), checkersGrid[i][j], TRUE, TRUE, 0);
    //pack checkersRows into topLeftBox
    for(i = 0; i < 8; i++)
        gtk_box_pack_start(GTK_BOX(topRightBox), checkersRows[i], TRUE, TRUE, 0);
    //make it close when closed
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    //checkerboard
    css = g_file_new_for_path(cssPath);
    cssProvider = gtk_css_provider_new();
    if(!gtk_css_provider_load_from_file(cssProvider, css, error))
        return 1;
    for(i = 0; i<8; i++){
        for(j = 0; j<8; j++){
            gtk_widget_set_size_request(checkersGrid[i][j], 50, 50);
            if(i % 2)
                if(j % 2)
                    gtk_style_context_add_class(gtk_widget_get_style_context(checkersGrid[i][j]), "opponentBoard");
                else
                    gtk_style_context_add_class(gtk_widget_get_style_context(checkersGrid[i][j]), "playerBoard");
            else
                if(j % 2)
                    gtk_style_context_add_class(gtk_widget_get_style_context(checkersGrid[i][j]), "playerBoard");
                else
                    gtk_style_context_add_class(gtk_widget_get_style_context(checkersGrid[i][j]), "opponentBoard");
        }
    }
    //start
    gtk_widget_show(window);
    gtk_main();
    return 0;
}
