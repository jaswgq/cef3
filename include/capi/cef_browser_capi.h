// Copyright (c) 2014 Marshall A. Greenblatt. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//    * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//    * Neither the name of Google Inc. nor the name Chromium Embedded
// Framework nor the names of its contributors may be used to endorse
// or promote products derived from this software without specific prior
// written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool and should not edited
// by hand. See the translator.README.txt file in the tools directory for
// more information.
//

#ifndef CEF_INCLUDE_CAPI_CEF_BROWSER_CAPI_H_
#define CEF_INCLUDE_CAPI_CEF_BROWSER_CAPI_H_
#pragma once

#include "include/capi/cef_base_capi.h"
#include "include/capi/cef_frame_capi.h"
#include "include/capi/cef_process_message_capi.h"
#include "include/capi/cef_request_context_capi.h"

#ifdef __cplusplus
extern "C" {
#endif

struct _cef_browser_host_t;
struct _cef_client_t;

///
// Structure used to represent a browser window. When used in the browser
// process the functions of this structure may be called on any thread unless
// otherwise indicated in the comments. When used in the render process the
// functions of this structure may only be called on the main thread.
///
typedef struct _cef_browser_t {
  ///
  // Base structure.
  ///
  cef_base_t base;

  ///
  // Returns the browser host object. This function can only be called in the
  // browser process.
  ///
  struct _cef_browser_host_t* (CEF_CALLBACK *get_host)(
      struct _cef_browser_t* self);

  ///
  // Returns true (1) if the browser can navigate backwards.
  ///
  int (CEF_CALLBACK *can_go_back)(struct _cef_browser_t* self);

  ///
  // Navigate backwards.
  ///
  void (CEF_CALLBACK *go_back)(struct _cef_browser_t* self);

  ///
  // Returns true (1) if the browser can navigate forwards.
  ///
  int (CEF_CALLBACK *can_go_forward)(struct _cef_browser_t* self);

  ///
  // Navigate forwards.
  ///
  void (CEF_CALLBACK *go_forward)(struct _cef_browser_t* self);

  ///
  // Returns true (1) if the browser is currently loading.
  ///
  int (CEF_CALLBACK *is_loading)(struct _cef_browser_t* self);

  ///
  // Reload the current page.
  ///
  void (CEF_CALLBACK *reload)(struct _cef_browser_t* self);

  ///
  // Reload the current page ignoring any cached data.
  ///
  void (CEF_CALLBACK *reload_ignore_cache)(struct _cef_browser_t* self);

  ///
  // Stop loading the page.
  ///
  void (CEF_CALLBACK *stop_load)(struct _cef_browser_t* self);

  ///
  // Returns the globally unique identifier for this browser.
  ///
  int (CEF_CALLBACK *get_identifier)(struct _cef_browser_t* self);

  ///
  // Returns true (1) if this object is pointing to the same handle as |that|
  // object.
  ///
  int (CEF_CALLBACK *is_same)(struct _cef_browser_t* self,
      struct _cef_browser_t* that);

  ///
  // Returns true (1) if the window is a popup window.
  ///
  int (CEF_CALLBACK *is_popup)(struct _cef_browser_t* self);

  ///
  // Returns true (1) if a document has been loaded in the browser.
  ///
  int (CEF_CALLBACK *has_document)(struct _cef_browser_t* self);

  ///
  // Returns the main (top-level) frame for the browser window.
  ///
  struct _cef_frame_t* (CEF_CALLBACK *get_main_frame)(
      struct _cef_browser_t* self);

  ///
  // Returns the focused frame for the browser window.
  ///
  struct _cef_frame_t* (CEF_CALLBACK *get_focused_frame)(
      struct _cef_browser_t* self);

  ///
  // Returns the frame with the specified identifier, or NULL if not found.
  ///
  struct _cef_frame_t* (CEF_CALLBACK *get_frame_byident)(
      struct _cef_browser_t* self, int64 identifier);

  ///
  // Returns the frame with the specified name, or NULL if not found.
  ///
  struct _cef_frame_t* (CEF_CALLBACK *get_frame)(struct _cef_browser_t* self,
      const cef_string_t* name);

  ///
  // Returns the number of frames that currently exist.
  ///
  size_t (CEF_CALLBACK *get_frame_count)(struct _cef_browser_t* self);

  ///
  // Returns the identifiers of all existing frames.
  ///
  void (CEF_CALLBACK *get_frame_identifiers)(struct _cef_browser_t* self,
      size_t* identifiersCount, int64* identifiers);

  ///
  // Returns the names of all existing frames.
  ///
  void (CEF_CALLBACK *get_frame_names)(struct _cef_browser_t* self,
      cef_string_list_t names);

  //
  // Send a message to the specified |target_process|. Returns true (1) if the
  // message was sent successfully.
  ///
  int (CEF_CALLBACK *send_process_message)(struct _cef_browser_t* self,
      cef_process_id_t target_process,
      struct _cef_process_message_t* message);
} cef_browser_t;


///
// Callback structure for cef_browser_host_t::RunFileDialog. The functions of
// this structure will be called on the browser process UI thread.
///
typedef struct _cef_run_file_dialog_callback_t {
  ///
  // Base structure.
  ///
  cef_base_t base;

  ///
  // Called asynchronously after the file dialog is dismissed. If the selection
  // was successful |file_paths| will be a single value or a list of values
  // depending on the dialog mode. If the selection was cancelled |file_paths|
  // will be NULL.
  ///
  void (CEF_CALLBACK *cont)(struct _cef_run_file_dialog_callback_t* self,
      struct _cef_browser_host_t* browser_host, cef_string_list_t file_paths);
} cef_run_file_dialog_callback_t;


///
// Structure used to represent the browser process aspects of a browser window.
// The functions of this structure can only be called in the browser process.
// They may be called on any thread in that process unless otherwise indicated
// in the comments.
///
typedef struct _cef_browser_host_t {
  ///
  // Base structure.
  ///
  cef_base_t base;

  ///
  // Returns the hosted browser object.
  ///
  struct _cef_browser_t* (CEF_CALLBACK *get_browser)(
      struct _cef_browser_host_t* self);

  ///
  // Call this function before destroying a contained browser window. This
  // function performs any internal cleanup that may be needed before the
  // browser window is destroyed. See cef_life_span_handler_t::do_close()
  // documentation for additional usage information.
  ///
  void (CEF_CALLBACK *parent_window_will_close)(
      struct _cef_browser_host_t* self);

  ///
  // Request that the browser close. The JavaScript 'onbeforeunload' event will
  // be fired. If |force_close| is false (0) the event handler, if any, will be
  // allowed to prompt the user and the user can optionally cancel the close. If
  // |force_close| is true (1) the prompt will not be displayed and the close
  // will proceed. Results in a call to cef_life_span_handler_t::do_close() if
  // the event handler allows the close or if |force_close| is true (1). See
  // cef_life_span_handler_t::do_close() documentation for additional usage
  // information.
  ///
  void (CEF_CALLBACK *close_browser)(struct _cef_browser_host_t* self,
      int force_close);

  ///
  // Set focus for the browser window. If |enable| is true (1) focus will be set
  // to the window. Otherwise, focus will be removed.
  ///
  void (CEF_CALLBACK *set_focus)(struct _cef_browser_host_t* self, int enable);

  ///
  // Retrieve the window handle for this browser.
  ///
  cef_window_handle_t (CEF_CALLBACK *get_window_handle)(
      struct _cef_browser_host_t* self);

  ///
  // Retrieve the window handle of the browser that opened this browser. Will
  // return NULL for non-popup windows. This function can be used in combination
  // with custom handling of modal windows.
  ///
  cef_window_handle_t (CEF_CALLBACK *get_opener_window_handle)(
      struct _cef_browser_host_t* self);

  ///
  // Returns the client for this browser.
  ///
  struct _cef_client_t* (CEF_CALLBACK *get_client)(
      struct _cef_browser_host_t* self);

  ///
  // Returns the request context for this browser.
  ///
  struct _cef_request_context_t* (CEF_CALLBACK *get_request_context)(
      struct _cef_browser_host_t* self);

  ///
  // Get the current zoom level. The default zoom level is 0.0. This function
  // can only be called on the UI thread.
  ///
  double (CEF_CALLBACK *get_zoom_level)(struct _cef_browser_host_t* self);

  ///
  // Change the zoom level to the specified value. Specify 0.0 to reset the zoom
  // level. If called on the UI thread the change will be applied immediately.
  // Otherwise, the change will be applied asynchronously on the UI thread.
  ///
  void (CEF_CALLBACK *set_zoom_level)(struct _cef_browser_host_t* self,
      double zoomLevel);

  ///
  // Call to run a file chooser dialog. Only a single file chooser dialog may be
  // pending at any given time. |mode| represents the type of dialog to display.
  // |title| to the title to be used for the dialog and may be NULL to show the
  // default title ("Open" or "Save" depending on the mode). |default_file_name|
  // is the default file name to select in the dialog. |accept_types| is a list
  // of valid lower-cased MIME types or file extensions specified in an input
  // element and is used to restrict selectable files to such types. |callback|
  // will be executed after the dialog is dismissed or immediately if another
  // dialog is already pending. The dialog will be initiated asynchronously on
  // the UI thread.
  ///
  void (CEF_CALLBACK *run_file_dialog)(struct _cef_browser_host_t* self,
      cef_file_dialog_mode_t mode, const cef_string_t* title,
      const cef_string_t* default_file_name, cef_string_list_t accept_types,
      struct _cef_run_file_dialog_callback_t* callback);

  ///
  // Download the file at |url| using cef_download_handler_t.
  ///
  void (CEF_CALLBACK *start_download)(struct _cef_browser_host_t* self,
      const cef_string_t* url);

  ///
  // Print the current browser contents.
  ///
  void (CEF_CALLBACK *print)(struct _cef_browser_host_t* self);

  ///
  // Search for |searchText|. |identifier| can be used to have multiple searches
  // running simultaniously. |forward| indicates whether to search forward or
  // backward within the page. |matchCase| indicates whether the search should
  // be case-sensitive. |findNext| indicates whether this is the first request
  // or a follow-up.
  ///
  void (CEF_CALLBACK *find)(struct _cef_browser_host_t* self, int identifier,
      const cef_string_t* searchText, int forward, int matchCase,
      int findNext);

  ///
  // Cancel all searches that are currently going on.
  ///
  void (CEF_CALLBACK *stop_finding)(struct _cef_browser_host_t* self,
      int clearSelection);

  ///
  // Open developer tools in its own window.
  ///
  void (CEF_CALLBACK *show_dev_tools)(struct _cef_browser_host_t* self,
      const struct _cef_window_info_t* windowInfo,
      struct _cef_client_t* client,
      const struct _cef_browser_settings_t* settings);

  ///
  // Explicitly close the developer tools window if one exists for this browser
  // instance.
  ///
  void (CEF_CALLBACK *close_dev_tools)(struct _cef_browser_host_t* self);

  ///
  // Set whether mouse cursor change is disabled.
  ///
  void (CEF_CALLBACK *set_mouse_cursor_change_disabled)(
      struct _cef_browser_host_t* self, int disabled);

  ///
  // Returns true (1) if mouse cursor change is disabled.
  ///
  int (CEF_CALLBACK *is_mouse_cursor_change_disabled)(
      struct _cef_browser_host_t* self);

  ///
  // Returns true (1) if window rendering is disabled.
  ///
  int (CEF_CALLBACK *is_window_rendering_disabled)(
      struct _cef_browser_host_t* self);

  ///
  // Notify the browser that the widget has been resized. The browser will first
  // call cef_render_handler_t::GetViewRect to get the new size and then call
  // cef_render_handler_t::OnPaint asynchronously with the updated regions. This
  // function is only used when window rendering is disabled.
  ///
  void (CEF_CALLBACK *was_resized)(struct _cef_browser_host_t* self);

  ///
  // Notify the browser that it has been hidden or shown. Layouting and
  // cef_render_handler_t::OnPaint notification will stop when the browser is
  // hidden. This function is only used when window rendering is disabled.
  ///
  void (CEF_CALLBACK *was_hidden)(struct _cef_browser_host_t* self, int hidden);

  ///
  // Send a notification to the browser that the screen info has changed. The
  // browser will then call cef_render_handler_t::GetScreenInfo to update the
  // screen information with the new values. This simulates moving the webview
  // window from one display to another, or changing the properties of the
  // current display. This function is only used when window rendering is
  // disabled.
  ///
  void (CEF_CALLBACK *notify_screen_info_changed)(
      struct _cef_browser_host_t* self);

  ///
  // Invalidate the |dirtyRect| region of the view. The browser will call
  // cef_render_handler_t::OnPaint asynchronously with the updated regions. This
  // function is only used when window rendering is disabled.
  ///
  void (CEF_CALLBACK *invalidate)(struct _cef_browser_host_t* self,
      const cef_rect_t* dirtyRect, cef_paint_element_type_t type);

  ///
  // Send a key event to the browser.
  ///
  void (CEF_CALLBACK *send_key_event)(struct _cef_browser_host_t* self,
      const struct _cef_key_event_t* event);

  ///
  // Send a mouse click event to the browser. The |x| and |y| coordinates are
  // relative to the upper-left corner of the view.
  ///
  void (CEF_CALLBACK *send_mouse_click_event)(struct _cef_browser_host_t* self,
      const struct _cef_mouse_event_t* event, cef_mouse_button_type_t type,
      int mouseUp, int clickCount);

  ///
  // Send a mouse move event to the browser. The |x| and |y| coordinates are
  // relative to the upper-left corner of the view.
  ///
  void (CEF_CALLBACK *send_mouse_move_event)(struct _cef_browser_host_t* self,
      const struct _cef_mouse_event_t* event, int mouseLeave);

  ///
  // Send a mouse wheel event to the browser. The |x| and |y| coordinates are
  // relative to the upper-left corner of the view. The |deltaX| and |deltaY|
  // values represent the movement delta in the X and Y directions respectively.
  // In order to scroll inside select popups with window rendering disabled
  // cef_render_handler_t::GetScreenPoint should be implemented properly.
  ///
  void (CEF_CALLBACK *send_mouse_wheel_event)(struct _cef_browser_host_t* self,
      const struct _cef_mouse_event_t* event, int deltaX, int deltaY);

  ///
  // Send a focus event to the browser.
  ///
  void (CEF_CALLBACK *send_focus_event)(struct _cef_browser_host_t* self,
      int setFocus);

  ///
  // Send a capture lost event to the browser.
  ///
  void (CEF_CALLBACK *send_capture_lost_event)(
      struct _cef_browser_host_t* self);

  ///
  // Get the NSTextInputContext implementation for enabling IME on Mac when
  // window rendering is disabled.
  ///
  cef_text_input_context_t (CEF_CALLBACK *get_nstext_input_context)(
      struct _cef_browser_host_t* self);

  ///
  // Handles a keyDown event prior to passing it through the NSTextInputClient
  // machinery.
  ///
  void (CEF_CALLBACK *handle_key_event_before_text_input_client)(
      struct _cef_browser_host_t* self, cef_event_handle_t keyEvent);

  ///
  // Performs any additional actions after NSTextInputClient handles the event.
  ///
  void (CEF_CALLBACK *handle_key_event_after_text_input_client)(
      struct _cef_browser_host_t* self, cef_event_handle_t keyEvent);
} cef_browser_host_t;


///
// Create a new browser window using the window parameters specified by
// |windowInfo|. All values will be copied internally and the actual window will
// be created on the UI thread. If |request_context| is NULL the global request
// context will be used. This function can be called on any browser process
// thread and will not block.
///
CEF_EXPORT int cef_browser_host_create_browser(
    const cef_window_info_t* windowInfo, struct _cef_client_t* client,
    const cef_string_t* url, const struct _cef_browser_settings_t* settings,
    struct _cef_request_context_t* request_context);

///
// Create a new browser window using the window parameters specified by
// |windowInfo|. If |request_context| is NULL the global request context will be
// used. This function can only be called on the browser process UI thread.
///
CEF_EXPORT cef_browser_t* cef_browser_host_create_browser_sync(
    const cef_window_info_t* windowInfo, struct _cef_client_t* client,
    const cef_string_t* url, const struct _cef_browser_settings_t* settings,
    struct _cef_request_context_t* request_context);


#ifdef __cplusplus
}
#endif

#endif  // CEF_INCLUDE_CAPI_CEF_BROWSER_CAPI_H_
