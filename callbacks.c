#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "callbacks.h"
#include "support.h"
#include "service.h"
#include "reservation.h"
#include "interface.h"

void on_A4_button1_clicked(GtkWidget *objet_graphique,
                           gpointer user_data)
{
   // REDIRECT TO PARKINGS
}

void on_A4_button2_clicked(GtkWidget *objet_graphique,
                           gpointer user_data)
{
   // AGENTS
}

void on_A4_button3_clicked(GtkWidget *objet_graphique,
                           gpointer user_data)
{
   // RESERVATIONS
}

void on_A4_button4_clicked(GtkWidget *objet_graphique,
                           gpointer user_data)
{
   // SIGN IN - SIGN UP PAGE
}

void on_A4_button5_clicked(GtkWidget *objet_graphique,
                           gpointer user_data)
{
   /*GtkWidget* sort;
   sort=lookup_widget(GTK_WIDGET(objet_graphique), "A4_combobox1");
   char sortby[30];
   strcpy(sortby,gtk_combo_box_get_active_text(GTK_COMBO_BOX(sort)));
   if */
}

void on_A4_button6_clicked(GtkWidget *objet_graphique,
                           gpointer user_data)
{
   GtkWidget *AddServiceWindow;
   GtkWidget *MainWindow;
   AddServiceWindow = create_A4_1();
   MainWindow = lookup_widget(GTK_WIDGET(objet_graphique), "A4");
   gtk_widget_show(AddServiceWindow);
   gtk_widget_destroy(MainWindow);
}

void on_A4_button7_clicked(GtkWidget *objet_graphique,
                           gpointer user_data)
{
   GtkWidget *EditServiceWindow;
   GtkWidget *MainWindow;
   EditServiceWindow = create_A4_2();
   MainWindow = lookup_widget(GTK_WIDGET(objet_graphique), "A4");
   gtk_widget_show(EditServiceWindow);
   gtk_widget_destroy(MainWindow);
}

void on_A4_button8_clicked(GtkWidget *objet_graphique,
                           gpointer user_data)
{
   GtkWidget *ConfirmDeletionWindow;
   GtkWidget *MainWindow;
   ConfirmDeletionWindow = create_A4_3();
   MainWindow = lookup_widget(GTK_WIDGET(objet_graphique), "A4");
   gtk_widget_show(ConfirmDeletionWindow);
   gtk_widget_destroy(MainWindow);
}

void on_A4_button9_clicked(GtkWidget *objet_graphique,
                           gpointer user_data)
{
   GtkWidget *AffectServiceWindow;
   GtkWidget *MainWindow;
   GtkWidget *A44_treeview1, *A44_treeview2;
   AffectServiceWindow = create_A4_4();
   MainWindow = lookup_widget(GTK_WIDGET(objet_graphique), "A4");
   gtk_widget_show(AffectServiceWindow);
   gtk_widget_destroy(MainWindow);
   A44_treeview1 = lookup_widget(AffectServiceWindow, "A44_treeview1");
   A44_treeview2 = lookup_widget(AffectServiceWindow, "A44_treeview2");
   show_reservation(A44_treeview1);
   show_reservation(A44_treeview2);
}

void on_A4_button10_clicked(GtkWidget *objet_graphique,
                            gpointer user_data)
{
   GtkWidget *MainWindow, *w1;
   GtkWidget *treeview1;
   MainWindow = lookup_widget(GTK_WIDGET(objet_graphique), "A4");
   w1 = create_A4();
   gtk_widget_show(w1);
   gtk_widget_destroy(MainWindow);
   treeview1 = lookup_widget(w1, "A4_treeview1");
   empty_service(treeview1);
   show_service(treeview1);
}

void on_A4_button11_clicked(GtkWidget *objet_graphique,
                            gpointer user_data)
{
   GtkWidget *MainWindow, *w1;
   GtkWidget *treeview1, *treeview2;
   MainWindow = lookup_widget(GTK_WIDGET(objet_graphique), "A4");
   w1 = create_A4();
   gtk_widget_destroy(MainWindow);
   gtk_widget_show(w1);
   treeview1 = lookup_widget(w1, "A4_treeview1");
   
   show_service(treeview1);

}

int add_type = 0;

void on_A41_radiobutton1_toggled(GtkToggleButton *togglebutton,
                                 gpointer user_data)
{
   if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
      add_type = 1;
}

void on_A41_radiobutton2_toggled(GtkToggleButton *togglebutton,
                                 gpointer user_data)
{
   if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
      add_type = 2;
}

void on_A41_radiobutton3_toggled(GtkToggleButton *togglebutton,
                                 gpointer user_data)
{
   if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
      add_type = 3;
}

int add_eligibility[2] = {0, 0};

void on_A41_checkbutton1_toggled(GtkToggleButton *togglebutton, gpointer user_data)
{
   if (gtk_toggle_button_get_active(togglebutton))
      add_eligibility[0] = 1;
   else
      add_eligibility[0] = 0;
}

void on_A41_checkbutton2_toggled(GtkToggleButton *togglebutton, gpointer user_data)
{
   if (gtk_toggle_button_get_active(togglebutton))
      add_eligibility[1] = 1;
   else
      add_eligibility[1] = 0;
}

void on_A41_button1_clicked(GtkWidget *objet_graphique,
                            gpointer user_data)
{
   int x;
   gchar *id;
   gchar *name;
   gint *price;
   gchar *manager;
   gchar *capacity;
   GtkWidget *output;
   id = gtk_entry_get_text(GTK_ENTRY(lookup_widget(objet_graphique, "A41_entry1")));
   name = gtk_entry_get_text(GTK_ENTRY(lookup_widget(objet_graphique, "A41_entry2")));
   price = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(lookup_widget(objet_graphique, "A41_spinbutton1")));
   manager = gtk_combo_box_get_active_text(GTK_COMBO_BOX(lookup_widget(objet_graphique, "A41_combobox1")));
   capacity = gtk_entry_get_text(GTK_ENTRY(lookup_widget(objet_graphique, "A41_entry3")));
   output = lookup_widget(objet_graphique, "A41_label5");
   ser s;
   if (verify_int(id) == 0)
      gtk_label_set_text(GTK_LABEL(output), "Error: Service ID should be a number");
   else
   {
      if (strlen(name) > 30)
         gtk_label_set_text(GTK_LABEL(output), "Error: Service name shouldn't surpass 30 characters");
      else
      {
         if (verify_int(capacity) == 0)
            gtk_label_set_text(GTK_LABEL(output), "Error: Capacity should be a number");
         else
         {
            s.id = atoi(id);
            strcpy(s.name, name);
            s.type = add_type;
            s.price = price;
            strcpy(s.manager, manager);
            s.capacity = atoi(capacity);
            s.eligibility[0] = add_eligibility[0];
            s.eligibility[1] = add_eligibility[1];
            x = add_service("services.txt", s);

            switch (x)
            {
            case 0:
               gtk_label_set_text(GTK_LABEL(output), "Error: Coudldn't retrieve user input");
               break;
            case 1:
               gtk_label_set_text(GTK_LABEL(output), "Service has been successfully added");
               break;
            case 2:
               gtk_label_set_text(GTK_LABEL(output), "Error: Service is already registered");
               break;
            case 3:
               gtk_label_set_text(GTK_LABEL(output), "Error: Service ID should be between 1 - 99");
               break;
            case 4:
               gtk_label_set_text(GTK_LABEL(output), "Error: Service capacity should be between 1 - 99");
            }
         }
      }
   }
}

void on_A41_button2_clicked(GtkWidget *objet_graphique,
                            gpointer user_data)
{
   GtkWidget *AddServiceWindow;
   GtkWidget *MainWindow;
   MainWindow = create_A4();
   AddServiceWindow = lookup_widget(GTK_WIDGET(objet_graphique), "A4_1");
   gtk_widget_show(MainWindow);
   gtk_widget_destroy(AddServiceWindow);
}

int edit_type;

void on_A42_radiobutton1_toggled(GtkToggleButton *togglebutton,
                                 gpointer user_data)
{
   if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
      edit_type = 1;
}

void on_A42_radiobutton2_toggled(GtkToggleButton *togglebutton,
                                 gpointer user_data)
{
   if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
      edit_type = 2;
}

void on_A42_radiobutton3_toggled(GtkToggleButton *togglebutton,
                                 gpointer user_data)
{
   if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
      edit_type = 3;
}

int edit_eligibility[2] = {0, 0};

void on_A42_checkbutton1_toggled(GtkToggleButton *togglebutton, gpointer user_data)
{
   if (gtk_toggle_button_get_active(togglebutton))
      edit_eligibility[0] = 1;
}

void on_A42_checkbutton2_toggled(GtkToggleButton *togglebutton, gpointer user_data)
{
   if (gtk_toggle_button_get_active(togglebutton))
      edit_eligibility[1] = 1;
}

void on_A42_button1_clicked(GtkWidget *objet_graphique,
                            gpointer user_data)
{
   gchar *id;
   gchar *name;
   gint price;
   gchar *manager;
   gchar *capacity;
   GtkWidget *output;
   id = gtk_entry_get_text(GTK_ENTRY(lookup_widget(objet_graphique, "A42_entry1")));
   name = gtk_entry_get_text(GTK_ENTRY(lookup_widget(objet_graphique, "A42_entry2")));
   price = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(lookup_widget(objet_graphique, "A42_spinbutton1")));
   manager = gtk_combo_box_get_active_text(GTK_COMBO_BOX(lookup_widget(objet_graphique, "A42_combobox1")));
   capacity = gtk_entry_get_text(GTK_ENTRY(lookup_widget(objet_graphique, "A42_entry3")));
   output = lookup_widget(objet_graphique, "A42_label5");
   ser s;
   s.id = atoi(id);
   if (verify_service("services.txt", s.id) == 0)
      gtk_label_set_text(GTK_LABEL(output), "Error: No service with this ID can be found");
   else
   {
      if (strlen(name) > 30)
         gtk_label_set_text(GTK_LABEL(output), "Error: Service name shouldn't surpass 30 characters");
      else
      {
         if (verify_int(capacity) == 0)
            gtk_label_set_text(GTK_LABEL(output), "Error: Capacity should be a number");
         else
         {
            strcpy(s.name, name);
            s.type = edit_type;
            s.price = price;
            strcpy(s.manager, manager);
            s.capacity = atoi(capacity);
            s.eligibility[0] = edit_eligibility[0];
            s.eligibility[1] = edit_eligibility[1];
            int x = edit_service("services.txt", fetch_service("services.txt", s.id), s);
            switch (x)
            {
            case 0:
               gtk_label_set_text(GTK_LABEL(output), "Error: Coudldn't retrieve user input");
               break;
            case 1:
               gtk_label_set_text(GTK_LABEL(output), "Service has been successfully edited");
               break;
            case 2:
               gtk_label_set_text(GTK_LABEL(output), "Error: Service capacity should be between 1 - 99");
            case 3:
               gtk_label_set_text(GTK_LABEL(output), "Error: Service capacity should remain higher than the number of customers");
            }
         }
      }
   }
}

void on_A42_button2_clicked(GtkWidget *objet_graphique,
                            gpointer user_data)
{
   GtkWidget *EditServiceWindow;
   GtkWidget *MainWindow;
   MainWindow = create_A4();
   EditServiceWindow = lookup_widget(GTK_WIDGET(objet_graphique), "A4_2");
   gtk_widget_show(MainWindow);
   gtk_widget_destroy(EditServiceWindow);
}

void on_A43_button1_clicked(GtkWidget *objet_graphique,
                            gpointer user_data)
{
   GtkWidget *id = lookup_widget(objet_graphique, "A43_entry1");
   GtkWidget *output;
   output = lookup_widget(objet_graphique, "A43_label2");
   if (verify_int(gtk_entry_get_text(GTK_ENTRY(id))) == 0)
      gtk_label_set_text(GTK_LABEL(output), "Service ID is a number");
   else
   {
      ser s;
      s.id = atoi(gtk_entry_get_text(GTK_ENTRY(id)));
      if (verify_service("services.txt", s.id) == 0)
         gtk_label_set_text(GTK_LABEL(output), "NO service with this ID can be found");
      else
      {
         s = fetch_service("services.txt", s.id);
         int x = delete_service("services.txt", s);
         if (x == 1)
            gtk_label_set_text(GTK_LABEL(output), "Service has been successfully deleted");
         else
            gtk_label_set_text(GTK_LABEL(output), "Error: Service hasn't been deleted");
      }
   }
}

void on_A43_button2_clicked(GtkWidget *objet_graphique,
                            gpointer user_data)
{
   GtkWidget *ConfirmDeletionWindow;
   GtkWidget *MainWindow;
   MainWindow = create_A4();
   ConfirmDeletionWindow = lookup_widget(GTK_WIDGET(objet_graphique), "A4_3");
   gtk_widget_show(MainWindow);
   gtk_widget_destroy(ConfirmDeletionWindow);
}

void on_A44_button1_clicked(GtkWidget *objet_graphique,
                            gpointer user_data)
{
   GtkWidget *AffectServiceWindow, *w1;
   GtkWidget *treeview1, *treeview2;
   AffectServiceWindow = lookup_widget(GTK_WIDGET(objet_graphique), "A4_4");
   w1 = create_A4();
   gtk_widget_destroy(AffectServiceWindow);
   gtk_widget_show(w1);
   treeview1 = lookup_widget(w1, "A44_treeview1");
   treeview2 = lookup_widget(w1, "A44_treeview2");
   empty_reservation(treeview1);
   show_reservation(treeview1);
   empty_reservation(treeview2);
   show_reservation(treeview2);
}

// elected row

void on_A44_button4_clicked(GtkWidget *objet_graphique,
                            gpointer user_data)
{
   GtkWidget *AffectServiceWindow;
   GtkWidget *MainWindow;
   MainWindow = create_A4();
   AffectServiceWindow = lookup_widget(GTK_WIDGET(objet_graphique), "A4_4");
   gtk_widget_show(MainWindow);
   gtk_widget_destroy(AffectServiceWindow);
}
void on_A44_treeview1_row_activated(GtkWidget *objet_graphique,
                                    GtkTreeView *treeview,
                                    GtkTreePath *path,
                                    GtkTreeViewColumn *column,
                                    gpointer user_data)
{
   GtkWidget *output;
   GtkTreeIter iter;
   gchar *id;
   gchar *status;
   gchar *day;
   gchar *month;
   res r;
   output = lookup_widget(GTK_WIDGET(objet_graphique), "A44_label3");
   GtkTreeModel *model = gtk_tree_view_get_model(treeview);
   if (gtk_tree_model_get_iter(model, &iter, path))
   {
      gtk_tree_model_get(GTK_LIST_STORE(model), &iter, id, &id, status, &status, day, &day, month, &month, -1);
      r.id = atoi(id);
      strcpy(r.status, status);
      r.res_date.day = atoi(day);
      r.res_date.month = atoi(month);
   }
   int x = add_reservation("accepted_reservations.txt", r);
   if (x == 1)
   {
      gtk_label_set_text(GTK_LABEL(output), "Reservation accepted");
      ser s = fetch_service("services.txt", r.id);
      s.customers++;
   }
}

void on_A44_treeview2_row_activated(GtkWidget *objet_graphique,
                                    GtkTreeView *treeview,
                                    GtkTreePath *path,
                                    GtkTreeViewColumn *column,
                                    gpointer user_data)
{
   GtkWidget *output;
   GtkTreeIter iter;
   gchar *id;
   gchar *status;
   gchar *day;
   gchar *month;
   res r;
   output = lookup_widget(GTK_WIDGET(objet_graphique), "A44_label3");
   GtkTreeModel *model = gtk_tree_view_get_model(treeview);
   if (gtk_tree_model_get_iter(model, &iter, path))
   {
      gtk_tree_model_get(GTK_LIST_STORE(model), &iter, id, &id, status, &status, day, &day, month, &month, -1);
      r.id = atoi(id);
      strcpy(r.status, status);
      r.res_date.day = atoi(day);
      r.res_date.month = atoi(month);
   }
   int x = delete_reservation("reservations.txt", r);
   if (x == 1)
      gtk_label_set_text(GTK_LABEL(output), "Reservation refused");
}
