//
// Created by Dragonfly on 01/01/23.
//
/*
Copyright (c) 2023, Dragonfly
        All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
        this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
        IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
        FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
        CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 */



#include <gtk/gtk.h>
#include "qr_ui.h"

static GtkBuilder *builder;
static GError *error = NULL;

void open_qr(GtkWidget *widget, gpointer root,char* image_path) {

    builder = gtk_builder_new();
    //Load ui description from built resource - need to generate compiled source with glib-compile-resource
    gtk_builder_add_from_resource(builder,"/org/gtk/wihotspot/qr.glade",&error);

    root = gtk_builder_get_object(builder, "dialog_qr");

    GtkImage* qr_image = (GtkImage *) gtk_builder_get_object(builder, "image_qr");

    gtk_image_set_from_file(qr_image,image_path);

    GtkDialog* dialog= GTK_DIALOG(root);
    
    gtk_dialog_run(GTK_DIALOG(dialog));

    gtk_widget_destroy(GTK_WIDGET( dialog));
    
    g_signal_connect (dialog, "destroy", G_CALLBACK(gtk_main_quit), NULL);

}