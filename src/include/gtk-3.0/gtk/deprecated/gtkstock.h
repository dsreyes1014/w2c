/* GTK - The GIMP Toolkit
 * Copyright (C) 2000 Red Hat, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * Modified by the GTK+ Team and others 1997-2000.  See the AUTHORS
 * file for a list of people on the GTK+ Team.  See the ChangeLog
 * files for a list of changes.  These files are distributed with
 * GTK+ at ftp://ftp.gtk.org/pub/gtk/.
 */

#ifndef __GTK_STOCK_H__
#define __GTK_STOCK_H__


#if !defined (__GTK_H_INSIDE__) && !defined (GTK_COMPILATION)
#error "Only <gtk/gtk.h> can be included directly."
#endif

#include <gdk/gdk.h>

G_BEGIN_DECLS

/*
 * GtkTranslateFunc:
 * @path: The id of the message. In #GtkActionGroup this will be a label
 *   or tooltip from a #GtkActionEntry.
 * @func_data: user data passed in when registering the function
 *
 * The function used to translate messages in e.g. #GtkIconFactory
 * and #GtkActionGroup.
 *
 * Returns: the translated message
 *
 * Deprecated: 3.10
 */
typedef gchar * (*GtkTranslateFunc) (const gchar  *path,
                                     gpointer      func_data);

typedef struct _GtkStockItem GtkStockItem;

struct _GtkStockItem
{
  gchar *stock_id;
  gchar *label;
  GdkModifierType modifier;
  guint keyval;
  gchar *translation_domain;
};

GDK_DEPRECATED_IN_3_10
void     gtk_stock_add        (const GtkStockItem  *items,
                               guint                n_items);
GDK_DEPRECATED_IN_3_10
void     gtk_stock_add_static (const GtkStockItem  *items,
                               guint                n_items);
GDK_DEPRECATED_IN_3_10
gboolean gtk_stock_lookup     (const gchar         *stock_id,
                               GtkStockItem        *item);

/* Should free the list (and free each string in it also).
 * This function is only useful for GUI builders and such.
 */
GDK_DEPRECATED_IN_3_10
GSList*  gtk_stock_list_ids  (void);

GDK_DEPRECATED_IN_3_10
GtkStockItem *gtk_stock_item_copy (const GtkStockItem *item);
GDK_DEPRECATED_IN_3_10
void          gtk_stock_item_free (GtkStockItem       *item);

GDK_DEPRECATED_IN_3_10
void          gtk_stock_set_translate_func (const gchar      *domain,
					    GtkTranslateFunc  func,
					    gpointer          data,
					    GDestroyNotify    notify);

/* the following type exists just so we can get deprecation warnings */
#ifndef GDK_DISABLE_DEPRECATION_WARNINGS
#if GDK_VERSION_MIN_REQUIRED >= GDK_VERSION_3_10
G_DEPRECATED
#endif
#endif
typedef char * GtkStock;

/* Stock IDs (not all are stock items; some are images only) */
/**
 * GTK_STOCK_ABOUT:
 *
 * The "About" item.
 * <inlinegraphic fileref="help-about.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.6
 *
 * Deprecated: 3.10: Use named icon &quot;help-about&quot; or the label &quot;_About&quot;.
 */
#define GTK_STOCK_ABOUT            ((GtkStock)"gtk-about")

/**
 * GTK_STOCK_ADD:
 *
 * The "Add" item.
 * <inlinegraphic fileref="list-add.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;list-add&quot; or the label &quot;_Add&quot;.
 */
#define GTK_STOCK_ADD              ((GtkStock)"gtk-add")

/**
 * GTK_STOCK_APPLY:
 *
 * The "Apply" item.
 * <inlinegraphic fileref="gtk-apply.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Do not use an icon. Use label &quot;_Apply&quot;.
 */
#define GTK_STOCK_APPLY            ((GtkStock)"gtk-apply")

/**
 * GTK_STOCK_BOLD:
 *
 * The "Bold" item.
 * <inlinegraphic fileref="format-text-bold.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;format-text-bold&quot;.
 */
#define GTK_STOCK_BOLD             ((GtkStock)"gtk-bold")

/**
 * GTK_STOCK_CANCEL:
 *
 * The "Cancel" item.
 * <inlinegraphic fileref="gtk-cancel.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Do not use an icon. Use label &quot;_Cancel&quot;.
 */
#define GTK_STOCK_CANCEL           ((GtkStock)"gtk-cancel")

/**
 * GTK_STOCK_CAPS_LOCK_WARNING:
 *
 * The "Caps Lock Warning" icon.
 * <inlinegraphic fileref="gtk-caps-lock-warning.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.16
 *
 * Deprecated: 3.10: Use named icon &quot;dialog-warning-symbolic&quot;.
 */
#define GTK_STOCK_CAPS_LOCK_WARNING ((GtkStock)"gtk-caps-lock-warning")

/**
 * GTK_STOCK_CDROM:
 *
 * The "CD-Rom" item.
 * <inlinegraphic fileref="media-optical.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;media-optical&quot;.
 */
#define GTK_STOCK_CDROM            ((GtkStock)"gtk-cdrom")

/**
 * GTK_STOCK_CLEAR:
 *
 * The "Clear" item.
 * <inlinegraphic fileref="edit-clear.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;edit-clear&quot;.
 */
#define GTK_STOCK_CLEAR            ((GtkStock)"gtk-clear")

/**
 * GTK_STOCK_CLOSE:
 *
 * The "Close" item.
 * <inlinegraphic fileref="window-close.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;window-close&quot; or the label &quot;_Close&quot;.
 */
#define GTK_STOCK_CLOSE            ((GtkStock)"gtk-close")

/**
 * GTK_STOCK_COLOR_PICKER:
 *
 * The "Color Picker" item.
 * <inlinegraphic fileref="gtk-color-picker.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.2
 *
 * Deprecated: 3.10
 */
#define GTK_STOCK_COLOR_PICKER     ((GtkStock)"gtk-color-picker")

/**
 * GTK_STOCK_CONNECT:
 *
 * The "Connect" icon.
 * <inlinegraphic fileref="gtk-connect.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.6
 *
 * Deprecated: 3.10
 */
#define GTK_STOCK_CONNECT          ((GtkStock)"gtk-connect")

/**
 * GTK_STOCK_CONVERT:
 *
 * The "Convert" item.
 * <inlinegraphic fileref="gtk-convert.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10
 */
#define GTK_STOCK_CONVERT          ((GtkStock)"gtk-convert")

/**
 * GTK_STOCK_COPY:
 *
 * The "Copy" item.
 * <inlinegraphic fileref="edit-copy.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Do not use an icon. Use label &quot;_Copy&quot;.
 */
#define GTK_STOCK_COPY             ((GtkStock)"gtk-copy")

/**
 * GTK_STOCK_CUT:
 *
 * The "Cut" item.
 * <inlinegraphic fileref="edit-cut.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Do not use an icon. Use label &quot;Cu_t&quot;.
 */
#define GTK_STOCK_CUT              ((GtkStock)"gtk-cut")

/**
 * GTK_STOCK_DELETE:
 *
 * The "Delete" item.
 * <inlinegraphic fileref="edit-delete.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Do not use an icon. Use label &quot;_Delete&quot;.
 */
#define GTK_STOCK_DELETE           ((GtkStock)"gtk-delete")

/**
 * GTK_STOCK_DIALOG_AUTHENTICATION:
 *
 * The "Authentication" item.
 * <inlinegraphic fileref="dialog-password.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.4
 *
 * Deprecated: 3.10: Use named icon &quot;dialog-password&quot;.
 */
#define GTK_STOCK_DIALOG_AUTHENTICATION ((GtkStock)"gtk-dialog-authentication")

/**
 * GTK_STOCK_DIALOG_INFO:
 *
 * The "Information" item.
 * <inlinegraphic fileref="dialog-information.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;dialog-information&quot;.
 */
#define GTK_STOCK_DIALOG_INFO      ((GtkStock)"gtk-dialog-info")

/**
 * GTK_STOCK_DIALOG_WARNING:
 *
 * The "Warning" item.
 * <inlinegraphic fileref="dialog-warning.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;dialog-warning&quot;.
 */
#define GTK_STOCK_DIALOG_WARNING   ((GtkStock)"gtk-dialog-warning")

/**
 * GTK_STOCK_DIALOG_ERROR:
 *
 * The "Error" item.
 * <inlinegraphic fileref="dialog-error.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;dialog-error&quot;.
 */
#define GTK_STOCK_DIALOG_ERROR     ((GtkStock)"gtk-dialog-error")

/**
 * GTK_STOCK_DIALOG_QUESTION:
 *
 * The "Question" item.
 * <inlinegraphic fileref="dialog-question.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;dialog-question&quot;.
 */
#define GTK_STOCK_DIALOG_QUESTION  ((GtkStock)"gtk-dialog-question")

/**
 * GTK_STOCK_DIRECTORY:
 *
 * The "Directory" icon.
 * <inlinegraphic fileref="folder.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.6
 *
 * Deprecated: 3.10: Use named icon &quot;folder&quot;.
 */
#define GTK_STOCK_DIRECTORY        ((GtkStock)"gtk-directory")

/**
 * GTK_STOCK_DISCARD:
 *
 * The "Discard" item.
 *
 * Since: 2.12
 *
 * Deprecated: 3.10
 */
#define GTK_STOCK_DISCARD          ((GtkStock)"gtk-discard")

/**
 * GTK_STOCK_DISCONNECT:
 *
 * The "Disconnect" icon.
 * <inlinegraphic fileref="gtk-disconnect.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.6
 *
 * Deprecated: 3.10
 */
#define GTK_STOCK_DISCONNECT       ((GtkStock)"gtk-disconnect")

/**
 * GTK_STOCK_DND:
 *
 * The "Drag-And-Drop" icon.
 * <inlinegraphic fileref="gtk-dnd.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10
 */
#define GTK_STOCK_DND              ((GtkStock)"gtk-dnd")

/**
 * GTK_STOCK_DND_MULTIPLE:
 *
 * The "Drag-And-Drop multiple" icon.
 * <inlinegraphic fileref="gtk-dnd-multiple.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10
 */
#define GTK_STOCK_DND_MULTIPLE     ((GtkStock)"gtk-dnd-multiple")

/**
 * GTK_STOCK_EDIT:
 *
 * The "Edit" item.
 * <inlinegraphic fileref="gtk-edit.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.6
 *
 * Deprecated: 3.10
 */
#define GTK_STOCK_EDIT             ((GtkStock)"gtk-edit")

/**
 * GTK_STOCK_EXECUTE:
 *
 * The "Execute" item.
 * <inlinegraphic fileref="system-run.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;system-run&quot;.
 */
#define GTK_STOCK_EXECUTE          ((GtkStock)"gtk-execute")

/**
 * GTK_STOCK_FILE:
 *
 * The "File" item.
 * <inlinegraphic fileref="text-x-generic.png" format="PNG"></inlinegraphic>
 *
 * Since 3.0, this item has a label, before it only had an icon.
 *
 * Since: 2.6
 *
 * Deprecated: 3.10: Use named icon &quot;text-x-generic&quot;.
 */
#define GTK_STOCK_FILE             ((GtkStock)"gtk-file")

/**
 * GTK_STOCK_FIND:
 *
 * The "Find" item.
 * <inlinegraphic fileref="edit-find.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;edit-find&quot;.
 */
#define GTK_STOCK_FIND             ((GtkStock)"gtk-find")

/**
 * GTK_STOCK_FIND_AND_REPLACE:
 *
 * The "Find and Replace" item.
 * <inlinegraphic fileref="edit-find-replace.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;edit-find-replace&quot;.
 */
#define GTK_STOCK_FIND_AND_REPLACE ((GtkStock)"gtk-find-and-replace")

/**
 * GTK_STOCK_FLOPPY:
 *
 * The "Floppy" item.
 * <inlinegraphic fileref="media-floppy.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10
 */
#define GTK_STOCK_FLOPPY           ((GtkStock)"gtk-floppy")

/**
 * GTK_STOCK_FULLSCREEN:
 *
 * The "Fullscreen" item.
 * <inlinegraphic fileref="view-fullscreen.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.8
 *
 * Deprecated: 3.10: Use named icon &quot;view-fullscreen&quot;.
 */
#define GTK_STOCK_FULLSCREEN       ((GtkStock)"gtk-fullscreen")

/**
 * GTK_STOCK_GOTO_BOTTOM:
 *
 * The "Bottom" item.
 * <inlinegraphic fileref="go-bottom.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;go-bottom&quot;.
 */
#define GTK_STOCK_GOTO_BOTTOM      ((GtkStock)"gtk-goto-bottom")

/**
 * GTK_STOCK_GOTO_FIRST:
 *
 * The "First" item.
 * <inlinegraphic fileref="go-first-ltr.png" format="PNG"></inlinegraphic>
 * RTL variant
 * <inlinegraphic fileref="go-first-rtl.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;go-first&quot;.
 */
#define GTK_STOCK_GOTO_FIRST       ((GtkStock)"gtk-goto-first")

/**
 * GTK_STOCK_GOTO_LAST:
 *
 * The "Last" item.
 * <inlinegraphic fileref="go-last-ltr.png" format="PNG"></inlinegraphic>
 * RTL variant
 * <inlinegraphic fileref="go-last-rtl.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;go-last&quot;.
 */
#define GTK_STOCK_GOTO_LAST        ((GtkStock)"gtk-goto-last")

/**
 * GTK_STOCK_GOTO_TOP:
 *
 * The "Top" item.
 * <inlinegraphic fileref="go-top.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;go-top&quot;.
 */
#define GTK_STOCK_GOTO_TOP         ((GtkStock)"gtk-goto-top")

/**
 * GTK_STOCK_GO_BACK:
 *
 * The "Back" item.
 * <inlinegraphic fileref="go-previous-ltr.png" format="PNG"></inlinegraphic>
 * RTL variant
 * <inlinegraphic fileref="go-previous-rtl.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;go-previous&quot;.
*/
#define GTK_STOCK_GO_BACK          ((GtkStock)"gtk-go-back")

/**
 * GTK_STOCK_GO_DOWN:
 *
 * The "Down" item.
 * <inlinegraphic fileref="go-down.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;go-down&quot;.
 */
#define GTK_STOCK_GO_DOWN          ((GtkStock)"gtk-go-down")

/**
 * GTK_STOCK_GO_FORWARD:
 *
 * The "Forward" item.
 * <inlinegraphic fileref="go-next-ltr.png" format="PNG"></inlinegraphic>
 * RTL variant
 * <inlinegraphic fileref="go-next-rtl.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;go-next&quot;.
 */
#define GTK_STOCK_GO_FORWARD       ((GtkStock)"gtk-go-forward")

/**
 * GTK_STOCK_GO_UP:
 *
 * The "Up" item.
 * <inlinegraphic fileref="go-up.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;go-up&quot;.
 */
#define GTK_STOCK_GO_UP            ((GtkStock)"gtk-go-up")

/**
 * GTK_STOCK_HARDDISK:
 *
 * The "Harddisk" item.
 * <inlinegraphic fileref="drive-harddisk.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.4
 *
 * Deprecated: 3.10: Use named icon &quot;drive-harddisk&quot;.
 */
#define GTK_STOCK_HARDDISK         ((GtkStock)"gtk-harddisk")

/**
 * GTK_STOCK_HELP:
 *
 * The "Help" item.
 * <inlinegraphic fileref="help-contents.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;help-browser&quot;.
 */
#define GTK_STOCK_HELP             ((GtkStock)"gtk-help")

/**
 * GTK_STOCK_HOME:
 *
 * The "Home" item.
 * <inlinegraphic fileref="go-home.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;go-home&quot;.
 */
#define GTK_STOCK_HOME             ((GtkStock)"gtk-home")

/**
 * GTK_STOCK_INDEX:
 *
 * The "Index" item.
 * <inlinegraphic fileref="gtk-index.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10
 */
#define GTK_STOCK_INDEX            ((GtkStock)"gtk-index")

/**
 * GTK_STOCK_INDENT:
 *
 * The "Indent" item.
 * <inlinegraphic fileref="format-indent-more-ltr.png" format="PNG"></inlinegraphic>
 * RTL variant
 * <inlinegraphic fileref="format-indent-more-rtl.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.4
 *
 * Deprecated: 3.10: Use named icon &quot;format-indent-more&quot;.
 */
#define GTK_STOCK_INDENT           ((GtkStock)"gtk-indent")

/**
 * GTK_STOCK_INFO:
 *
 * The "Info" item.
 * <inlinegraphic fileref="dialog-information.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.8
 *
 * Deprecated: 3.10: Use named icon &quot;dialog-information&quot;.
 */
#define GTK_STOCK_INFO             ((GtkStock)"gtk-info")

/**
 * GTK_STOCK_ITALIC:
 *
 * The "Italic" item.
 * <inlinegraphic fileref="format-text-italic.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;format-text-italic&quot;.
 */
#define GTK_STOCK_ITALIC           ((GtkStock)"gtk-italic")

/**
 * GTK_STOCK_JUMP_TO:
 *
 * The "Jump to" item.
 * <inlinegraphic fileref="go-jump-ltr.png" format="PNG"></inlinegraphic>
 * RTL-variant
 * <inlinegraphic fileref="go-jump-rtl.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;go-jump&quot;.
 */
#define GTK_STOCK_JUMP_TO          ((GtkStock)"gtk-jump-to")

/**
 * GTK_STOCK_JUSTIFY_CENTER:
 *
 * The "Center" item.
 * <inlinegraphic fileref="format-justify-center.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;format-justify-center&quot;.
 */
#define GTK_STOCK_JUSTIFY_CENTER   ((GtkStock)"gtk-justify-center")

/**
 * GTK_STOCK_JUSTIFY_FILL:
 *
 * The "Fill" item.
 * <inlinegraphic fileref="format-justify-fill.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;format-justify-fill&quot;.
 */
#define GTK_STOCK_JUSTIFY_FILL     ((GtkStock)"gtk-justify-fill")

/**
 * GTK_STOCK_JUSTIFY_LEFT:
 *
 * The "Left" item.
 * <inlinegraphic fileref="format-justify-left.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;format-justify-left&quot;.
 */
#define GTK_STOCK_JUSTIFY_LEFT     ((GtkStock)"gtk-justify-left")

/**
 * GTK_STOCK_JUSTIFY_RIGHT:
 *
 * The "Right" item.
 * <inlinegraphic fileref="format-justify-right.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;format-justify-right&quot;.
 */
#define GTK_STOCK_JUSTIFY_RIGHT    ((GtkStock)"gtk-justify-right")

/**
 * GTK_STOCK_LEAVE_FULLSCREEN:
 *
 * The "Leave Fullscreen" item.
 * <inlinegraphic fileref="view-restore.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.8
 *
 * Deprecated: 3.10: Use named icon &quot;view-restore&quot;.
 */
#define GTK_STOCK_LEAVE_FULLSCREEN ((GtkStock)"gtk-leave-fullscreen")

/**
 * GTK_STOCK_MISSING_IMAGE:
 *
 * The "Missing image" icon.
 * <inlinegraphic fileref="image-missing.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;image-missing&quot;.
 */
#define GTK_STOCK_MISSING_IMAGE    ((GtkStock)"gtk-missing-image")

/**
 * GTK_STOCK_MEDIA_FORWARD:
 *
 * The "Media Forward" item.
 * <inlinegraphic fileref="media-seek-forward-ltr.png" format="PNG"></inlinegraphic>
 * RTL variant
 * <inlinegraphic fileref="media-seek-forward-rtl.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.6
 *
 * Deprecated: 3.10: Use named icon &quot;media-seek-forward&quot; or the label &quot;_Forward&quot;.
 */
#define GTK_STOCK_MEDIA_FORWARD    ((GtkStock)"gtk-media-forward")

/**
 * GTK_STOCK_MEDIA_NEXT:
 *
 * The "Media Next" item.
 * <inlinegraphic fileref="media-skip-forward-ltr.png" format="PNG"></inlinegraphic>
 * RTL variant
 * <inlinegraphic fileref="media-skip-forward-rtl.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.6
 *
 * Deprecated: 3.10: Use named icon &quot;media-skip-forward&quot; or the label &quot;_Next&quot;.
 */
#define GTK_STOCK_MEDIA_NEXT       ((GtkStock)"gtk-media-next")

/**
 * GTK_STOCK_MEDIA_PAUSE:
 *
 * The "Media Pause" item.
 * <inlinegraphic fileref="media-playback-pause.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.6
 *
 * Deprecated: 3.10: Use named icon &quot;media-playback-pause&quot; or the label &quot;P_ause&quot;.
 */
#define GTK_STOCK_MEDIA_PAUSE      ((GtkStock)"gtk-media-pause")

/**
 * GTK_STOCK_MEDIA_PLAY:
 *
 * The "Media Play" item.
 * <inlinegraphic fileref="media-playback-start-ltr.png" format="PNG"></inlinegraphic>
 * RTL variant
 * <inlinegraphic fileref="media-playback-start-rtl.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.6
 *
 * Deprecated: 3.10: Use named icon &quot;media-playback-start&quot; or the label &quot;_Play&quot;.
 */
#define GTK_STOCK_MEDIA_PLAY       ((GtkStock)"gtk-media-play")

/**
 * GTK_STOCK_MEDIA_PREVIOUS:
 *
 * The "Media Previous" item.
 * <inlinegraphic fileref="media-skip-backward-ltr.png" format="PNG"></inlinegraphic>
 * RTL variant
 * <inlinegraphic fileref="media-skip-backward-rtl.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.6
 *
 * Deprecated: 3.10: Use named icon &quot;media-skip-backward&quot; or the label &quot;Pre_vious&quot;.
 */
#define GTK_STOCK_MEDIA_PREVIOUS   ((GtkStock)"gtk-media-previous")

/**
 * GTK_STOCK_MEDIA_RECORD:
 *
 * The "Media Record" item.
 * <inlinegraphic fileref="media-record.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.6
 *
 * Deprecated: 3.10: Use named icon &quot;media-record&quot; or the label &quot;_Record&quot;.
 */
#define GTK_STOCK_MEDIA_RECORD     ((GtkStock)"gtk-media-record")

/**
 * GTK_STOCK_MEDIA_REWIND:
 *
 * The "Media Rewind" item.
 * <inlinegraphic fileref="media-seek-backward-ltr.png" format="PNG"></inlinegraphic>
 * RTL variant
 * <inlinegraphic fileref="media-seek-backward-rtl.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.6
 *
 * Deprecated: 3.10: Use named icon &quot;media-seek-backward&quot; or the label &quot;R_ewind&quot;.
 */
#define GTK_STOCK_MEDIA_REWIND     ((GtkStock)"gtk-media-rewind")

/**
 * GTK_STOCK_MEDIA_STOP:
 *
 * The "Media Stop" item.
 * <inlinegraphic fileref="media-playback-stop.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.6
 *
 * Deprecated: 3.10: Use named icon &quot;media-playback-stop&quot; or the label &quot;_Stop&quot;.
 */
#define GTK_STOCK_MEDIA_STOP       ((GtkStock)"gtk-media-stop")

/**
 * GTK_STOCK_NETWORK:
 *
 * The "Network" item.
 * <inlinegraphic fileref="network-idle.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.4
 *
 * Deprecated: 3.10: Use named icon &quot;network-workgroup&quot;.
 */
#define GTK_STOCK_NETWORK          ((GtkStock)"gtk-network")

/**
 * GTK_STOCK_NEW:
 *
 * The "New" item.
 * <inlinegraphic fileref="document-new.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;document-new&quot; or the label &quot;_New&quot;.
 */
#define GTK_STOCK_NEW              ((GtkStock)"gtk-new")

/**
 * GTK_STOCK_NO:
 *
 * The "No" item.
 * <inlinegraphic fileref="gtk-no.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10
 */
#define GTK_STOCK_NO               ((GtkStock)"gtk-no")

/**
 * GTK_STOCK_OK:
 *
 * The "OK" item.
 * <inlinegraphic fileref="gtk-ok.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Do not use an icon. Use label &quot;_OK&quot;.
 */
#define GTK_STOCK_OK               ((GtkStock)"gtk-ok")

/**
 * GTK_STOCK_OPEN:
 *
 * The "Open" item.
 * <inlinegraphic fileref="document-open.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;document-open&quot; or the label &quot;_Open&quot;.
 */
#define GTK_STOCK_OPEN             ((GtkStock)"gtk-open")

/**
 * GTK_STOCK_ORIENTATION_PORTRAIT:
 *
 * The "Portrait Orientation" item.
 * <inlinegraphic fileref="gtk-orientation-portrait.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.10
 *
 * Deprecated: 3.10
 */
#define GTK_STOCK_ORIENTATION_PORTRAIT ((GtkStock)"gtk-orientation-portrait")

/**
 * GTK_STOCK_ORIENTATION_LANDSCAPE:
 *
 * The "Landscape Orientation" item.
 * <inlinegraphic fileref="gtk-orientation-landscape.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.10
 *
 * Deprecated: 3.10
 */
#define GTK_STOCK_ORIENTATION_LANDSCAPE ((GtkStock)"gtk-orientation-landscape")

/**
 * GTK_STOCK_ORIENTATION_REVERSE_LANDSCAPE:
 *
 * The "Reverse Landscape Orientation" item.
 * <inlinegraphic fileref="gtk-orientation-reverse-landscape.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.10
 *
 * Deprecated: 3.10
 */
#define GTK_STOCK_ORIENTATION_REVERSE_LANDSCAPE ((GtkStock)"gtk-orientation-reverse-landscape")

/**
 * GTK_STOCK_ORIENTATION_REVERSE_PORTRAIT:
 *
 * The "Reverse Portrait Orientation" item.
 * <inlinegraphic fileref="gtk-orientation-reverse-portrait.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.10
 *
 * Deprecated: 3.10
 */
#define GTK_STOCK_ORIENTATION_REVERSE_PORTRAIT ((GtkStock)"gtk-orientation-reverse-portrait")

/**
 * GTK_STOCK_PAGE_SETUP:
 *
 * The "Page Setup" item.
 * <inlinegraphic fileref="gtk-page-setup.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.14
 *
 * Deprecated: 3.10: Use named icon &quot;document-page-setup&quot; or the label &quot;Page Set_up&quot;.
 */
#define GTK_STOCK_PAGE_SETUP       ((GtkStock)"gtk-page-setup")

/**
 * GTK_STOCK_PASTE:
 *
 * The "Paste" item.
 * <inlinegraphic fileref="edit-paste.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Do not use an icon. Use label &quot;_Paste&quot;.
 */
#define GTK_STOCK_PASTE            ((GtkStock)"gtk-paste")

/**
 * GTK_STOCK_PREFERENCES:
 *
 * The "Preferences" item.
 * <inlinegraphic fileref="gtk-preferences.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;preferences-system&quot; or the label &quot;_Preferences&quot;.
 */
#define GTK_STOCK_PREFERENCES      ((GtkStock)"gtk-preferences")

/**
 * GTK_STOCK_PRINT:
 *
 * The "Print" item.
 * <inlinegraphic fileref="document-print.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;document-print&quot; or the label &quot;_Print&quot;.
 */
#define GTK_STOCK_PRINT            ((GtkStock)"gtk-print")

/**
 * GTK_STOCK_PRINT_ERROR:
 *
 * The "Print Error" icon.
 * <inlinegraphic fileref="printer-error.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.14
 *
 * Deprecated: 3.10: Use named icon &quot;printer-error&quot;.
 */
#define GTK_STOCK_PRINT_ERROR      ((GtkStock)"gtk-print-error")

/**
 * GTK_STOCK_PRINT_PAUSED:
 *
 * The "Print Paused" icon.
 * <inlinegraphic fileref="printer-paused.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.14
 *
 * Deprecated: 3.10
 */
#define GTK_STOCK_PRINT_PAUSED     ((GtkStock)"gtk-print-paused")

/**
 * GTK_STOCK_PRINT_PREVIEW:
 *
 * The "Print Preview" item.
 * <inlinegraphic fileref="document-print-preview.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use label &quot;Pre_view&quot;.
 */
#define GTK_STOCK_PRINT_PREVIEW    ((GtkStock)"gtk-print-preview")

/**
 * GTK_STOCK_PRINT_REPORT:
 *
 * The "Print Report" icon.
 * <inlinegraphic fileref="printer-info.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.14
 *
 * Deprecated: 3.10
 */
#define GTK_STOCK_PRINT_REPORT     ((GtkStock)"gtk-print-report")


/**
 * GTK_STOCK_PRINT_WARNING:
 *
 * The "Print Warning" icon.
 * <inlinegraphic fileref="printer-warning.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.14
 *
 * Deprecated: 3.10
 */
#define GTK_STOCK_PRINT_WARNING    ((GtkStock)"gtk-print-warning")

/**
 * GTK_STOCK_PROPERTIES:
 *
 * The "Properties" item.
 * <inlinegraphic fileref="document-properties.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;document-properties&quot; or the label &quot;_Properties&quot;.
 */
#define GTK_STOCK_PROPERTIES       ((GtkStock)"gtk-properties")

/**
 * GTK_STOCK_QUIT:
 *
 * The "Quit" item.
 * <inlinegraphic fileref="application-exit.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;application-exit&quot; or the label &quot;_Quit&quot;.
 */
#define GTK_STOCK_QUIT             ((GtkStock)"gtk-quit")

/**
 * GTK_STOCK_REDO:
 *
 * The "Redo" item.
 * <inlinegraphic fileref="edit-redo-ltr.png" format="PNG"></inlinegraphic>
 * RTL variant
 * <inlinegraphic fileref="edit-redo-rtl.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;edit-redo&quot; or the label &quot;_Redo&quot;.
 */
#define GTK_STOCK_REDO             ((GtkStock)"gtk-redo")

/**
 * GTK_STOCK_REFRESH:
 *
 * The "Refresh" item.
 * <inlinegraphic fileref="view-refresh.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;view-refresh&quot; or the label &quot;_Refresh&quot;.
 */
#define GTK_STOCK_REFRESH          ((GtkStock)"gtk-refresh")

/**
 * GTK_STOCK_REMOVE:
 *
 * The "Remove" item.
 * <inlinegraphic fileref="list-remove.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;list-remove&quot; or the label &quot;_Remove&quot;.
 */
#define GTK_STOCK_REMOVE           ((GtkStock)"gtk-remove")

/**
 * GTK_STOCK_REVERT_TO_SAVED:
 *
 * The "Revert" item.
 * <inlinegraphic fileref="document-revert-ltr.png" format="PNG"></inlinegraphic>
 * RTL variant
 * <inlinegraphic fileref="document-revert-rtl.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;document-revert&quot; or the label &quot;_Revert&quot;.
 */
#define GTK_STOCK_REVERT_TO_SAVED  ((GtkStock)"gtk-revert-to-saved")

/**
 * GTK_STOCK_SAVE:
 *
 * The "Save" item.
 * <inlinegraphic fileref="document-save.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;document-save&quot; or the label &quot;_Save&quot;.
 */
#define GTK_STOCK_SAVE             ((GtkStock)"gtk-save")

/**
 * GTK_STOCK_SAVE_AS:
 *
 * The "Save As" item.
 * <inlinegraphic fileref="document-save-as.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;document-save-as&quot; or the label &quot;Save _As&quot;.
 */
#define GTK_STOCK_SAVE_AS          ((GtkStock)"gtk-save-as")

/**
 * GTK_STOCK_SELECT_ALL:
 *
 * The "Select All" item.
 * <inlinegraphic fileref="edit-select-all.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.10
 *
 * Deprecated: 3.10: Use named icon &quot;edit-select-all&quot; or the label &quot;Select _All&quot;.
 */
#define GTK_STOCK_SELECT_ALL       ((GtkStock)"gtk-select-all")

/**
 * GTK_STOCK_SELECT_COLOR:
 *
 * The "Color" item.
 * <inlinegraphic fileref="gtk-select-color.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10
 */
#define GTK_STOCK_SELECT_COLOR     ((GtkStock)"gtk-select-color")

/**
 * GTK_STOCK_SELECT_FONT:
 *
 * The "Font" item.
 * <inlinegraphic fileref="gtk-font.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10
 */
#define GTK_STOCK_SELECT_FONT      ((GtkStock)"gtk-select-font")

/**
 * GTK_STOCK_SORT_ASCENDING:
 *
 * The "Ascending" item.
 * <inlinegraphic fileref="view-sort-ascending.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;view-sort-ascending&quot;.
 */
#define GTK_STOCK_SORT_ASCENDING   ((GtkStock)"gtk-sort-ascending")

/**
 * GTK_STOCK_SORT_DESCENDING:
 *
 * The "Descending" item.
 * <inlinegraphic fileref="view-sort-descending.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;view-sort-descending&quot;.
 */
#define GTK_STOCK_SORT_DESCENDING  ((GtkStock)"gtk-sort-descending")

/**
 * GTK_STOCK_SPELL_CHECK:
 *
 * The "Spell Check" item.
 * <inlinegraphic fileref="tools-check-spelling.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;tools-check-spelling&quot;.
 */
#define GTK_STOCK_SPELL_CHECK      ((GtkStock)"gtk-spell-check")

/**
 * GTK_STOCK_STOP:
 *
 * The "Stop" item.
 * <inlinegraphic fileref="process-stop.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;process-stop&quot; or the label &quot;_Stop&quot;.
 */
#define GTK_STOCK_STOP             ((GtkStock)"gtk-stop")

/**
 * GTK_STOCK_STRIKETHROUGH:
 *
 * The "Strikethrough" item.
 * <inlinegraphic fileref="format-text-strikethrough.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;format-text-strikethrough&quot; or the label &quot;_Strikethrough&quot;.
 */
#define GTK_STOCK_STRIKETHROUGH    ((GtkStock)"gtk-strikethrough")

/**
 * GTK_STOCK_UNDELETE:
 *
 * The "Undelete" item.
 * <inlinegraphic fileref="gtk-undelete-ltr.png" format="PNG"></inlinegraphic>
 * RTL variant
 * <inlinegraphic fileref="gtk-undelete-rtl.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10
 */
#define GTK_STOCK_UNDELETE         ((GtkStock)"gtk-undelete")

/**
 * GTK_STOCK_UNDERLINE:
 *
 * The "Underline" item.
 * <inlinegraphic fileref="format-text-underline.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;format-text-underline&quot; or the label &quot;_Underline&quot;.
 */
#define GTK_STOCK_UNDERLINE        ((GtkStock)"gtk-underline")

/**
 * GTK_STOCK_UNDO:
 *
 * The "Undo" item.
 * <inlinegraphic fileref="edit-undo-ltr.png" format="PNG"></inlinegraphic>
 * RTL variant
 * <inlinegraphic fileref="edit-undo-rtl.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;edit-undo&quot; or the label &quot;_Undo&quot;.
 */
#define GTK_STOCK_UNDO             ((GtkStock)"gtk-undo")

/**
 * GTK_STOCK_UNINDENT:
 *
 * The "Unindent" item.
 * <inlinegraphic fileref="format-indent-less-ltr.png" format="PNG"></inlinegraphic>
 * RTL variant
 * <inlinegraphic fileref="format-indent-less-rtl.png" format="PNG"></inlinegraphic>
 *
 * Since: 2.4
 *
 * Deprecated: 3.10: Use named icon &quot;format-indent-less&quot;.
 */
#define GTK_STOCK_UNINDENT         ((GtkStock)"gtk-unindent")

/**
 * GTK_STOCK_YES:
 *
 * The "Yes" item.
 * <inlinegraphic fileref="gtk-yes.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10
 */
#define GTK_STOCK_YES              ((GtkStock)"gtk-yes")

/**
 * GTK_STOCK_ZOOM_100:
 *
 * The "Zoom 100%" item.
 * <inlinegraphic fileref="zoom-original.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;zoom-original&quot; or the label &quot;_Normal Size&quot;.
 */
#define GTK_STOCK_ZOOM_100         ((GtkStock)"gtk-zoom-100")

/**
 * GTK_STOCK_ZOOM_FIT:
 *
 * The "Zoom to Fit" item.
 * <inlinegraphic fileref="zoom-fit-best.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;zoom-fit-best&quot; or the label &quot;Best _Fit&quot;.
 */
#define GTK_STOCK_ZOOM_FIT         ((GtkStock)"gtk-zoom-fit")

/**
 * GTK_STOCK_ZOOM_IN:
 *
 * The "Zoom In" item.
 * <inlinegraphic fileref="zoom-in.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;zoom-in&quot; or the label &quot;Zoom _In&quot;.
 */
#define GTK_STOCK_ZOOM_IN          ((GtkStock)"gtk-zoom-in")

/**
 * GTK_STOCK_ZOOM_OUT:
 *
 * The "Zoom Out" item.
 * <inlinegraphic fileref="zoom-out.png" format="PNG"></inlinegraphic>
 *
 * Deprecated: 3.10: Use named icon &quot;zoom-out&quot; or the label &quot;Zoom _Out&quot;.
 */
#define GTK_STOCK_ZOOM_OUT         ((GtkStock)"gtk-zoom-out")

G_END_DECLS

#endif /* __GTK_STOCK_H__ */
