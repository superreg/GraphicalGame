#include <gtk/gtk.h>
#include "network.h"

int main(int argc, char** argv){
    GtkWindow *window;
    GtkWidget *mainBox, *topBox, *bottomBox, *bottomLeftBox, *bottomRightBox, *topRightBox, *topLeftBox;
    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(window, "Checkers");
    gtk_window_set_default_size(window, 1024, 768);
    mainBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 2);
    gtk_container_add(window, mainBox);
    topBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 2);
    bottomBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 2);
    gtk_box_pack_start(mainBox, topBox, TRUE, TRUE, 0);
    gtk_box_pack_start(mainBox, bottomBox, TRUE, TRUE, 0);
    bottomLeftBox = gtk_event_box_new();
    bottomRightBox = gtk_event_box_new();
    gtk_box_pack_start(bottomBox, bottomLeftBox, TRUE, TRUE, 0);
    gtk_box_pack_start(bottomBox, bottomRightBox, TRUE, TRUE, 0);
    topLeftBox = gtk_event_box_new();
    topRightBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 2);
    gtk_box_pack_start(topBox, topLeftBox, TRUE, TRUE, 2);
    gtk_box_pack_start(topBox, topRightBox, TRUE, TRUE, 2);
    g_signal_connect (G_OBJECT(window), "destroy", G_CALLBACK (gtk_main_quit), NULL);
    gtk_widget_show(window);
    gtk_widget_show(mainBox);
    gtk_widget_show(topBox);
    gtk_widget_show(bottomBox);
    gtk_widget_show(bottomLeftBox);
    gtk_widget_show(bottomRightBox);
    gtk_widget_show(topRightBox);
    gtk_widget_show(topLeftBox);
    gtk_main();
    return 0;
}
