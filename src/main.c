#include <gtk/gtk.h>

int main(int argc, char** argv){
    GtkWindow *window;
    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(window, "Checkers");
    gtk_window_set_default_size(window, 1024, 768);
    gtk_main();
    return 0;
}