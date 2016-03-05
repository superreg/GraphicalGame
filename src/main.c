#include <gtk/gtk.h>
#include "network.h"

int main(int argc, char** argv){
    GtkWindow *window;
    GtkBox *mainBox, *topBox, *bottomBox, *topRightBox, *topLeftBox, *checkersRows[8];
    GtkEventBox *bottomLeftBox, *bottomRightBox;
    GtkEventBox *checkersGrid[8][8];
    int i, j;
    //initializing and packing
    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(window, "Checkers");
    gtk_window_set_default_size(window, 640, 640);
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
    topLeftBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 1);
    topRightBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 2);
    gtk_box_pack_start(topBox, topLeftBox, TRUE, TRUE, 2);
    gtk_box_pack_start(topBox, topRightBox, TRUE, TRUE, 2);
    //initialize checkers board
    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            checkersGrid[i][j] = gtk_event_box_new();
        }
    }
    //initialize checkers rows
    for(i = 0; i < 8; i++){
        checkersRows[i] = gtk_box_new(GTK_ORIENTATION_VERTICAL, 1);
    }
    //pack checkersGrid into checkersRows
    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            gtk_box_pack_start(&(checkersRows[i]), &(checkersGrid[i][j]), TRUE, TRUE, 0);
        }
    }
    //pack checkersRows into topLeftBox
    for(i = 0; i < 8; i++){
        gtk_box_pack_start(topRightBox, &(checkersRows[i]), TRUE, TRUE, 0);
    }
    gtk_widget_show(window);
    gtk_main();
    return 0;
}
