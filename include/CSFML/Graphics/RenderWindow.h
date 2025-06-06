////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2024 Laurent Gomila (laurent@sfml-dev.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <CSFML/Graphics/Export.h>

#include <CSFML/Graphics/Color.h>
#include <CSFML/Graphics/PrimitiveType.h>
#include <CSFML/Graphics/Rect.h>
#include <CSFML/Graphics/RenderStates.h>
#include <CSFML/Graphics/StencilMode.h>
#include <CSFML/Graphics/Types.h>
#include <CSFML/Graphics/Vertex.h>
#include <CSFML/System/Time.h>
#include <CSFML/System/Vector2.h>
#include <CSFML/Window/Event.h>
#include <CSFML/Window/VideoMode.h>
#include <CSFML/Window/Window.h>
#include <CSFML/Window/WindowHandle.h>

#include <stddef.h>


////////////////////////////////////////////////////////////
/// \brief Construct a new render window
///
/// \param mode     Video mode to use
/// \param title    Title of the window
/// \param style    Window style
/// \param state    Window state
/// \param settings Creation settings (pass NULL to use default values)
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfRenderWindow* sfRenderWindow_create(
    sfVideoMode              mode,
    const char*              title,
    uint32_t                 style,
    sfWindowState            state,
    const sfContextSettings* settings);

////////////////////////////////////////////////////////////
/// \brief Construct a new render window (with a UTF-32 title)
///
/// \param mode     Video mode to use
/// \param title    Title of the window (UTF-32)
/// \param style    Window style
/// \param state    Window state
/// \param settings Creation settings (pass NULL to use default values)
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfRenderWindow* sfRenderWindow_createUnicode(
    sfVideoMode              mode,
    const sfChar32*          title,
    uint32_t                 style,
    sfWindowState            state,
    const sfContextSettings* settings);

////////////////////////////////////////////////////////////
/// \brief Construct a render window from an existing control
///
/// \param handle   Platform-specific handle of the control
/// \param settings Creation settings (pass NULL to use default values)
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfRenderWindow* sfRenderWindow_createFromHandle(sfWindowHandle handle, const sfContextSettings* settings);

////////////////////////////////////////////////////////////
/// \brief Destroy an existing render window
///
/// \param renderWindow Render window to destroy
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderWindow_destroy(const sfRenderWindow* renderWindow);

////////////////////////////////////////////////////////////
/// \brief Close a render window (but doesn't destroy the internal data)
///
/// \param renderWindow Render window to close
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderWindow_close(sfRenderWindow* renderWindow);

////////////////////////////////////////////////////////////
/// \brief Tell whether or not a render window is opened
///
/// \param renderWindow Render window object
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API bool sfRenderWindow_isOpen(const sfRenderWindow* renderWindow);

////////////////////////////////////////////////////////////
/// \brief Get the creation settings of a render window
///
/// \param renderWindow Render window object
///
/// \return Settings used to create the window
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfContextSettings sfRenderWindow_getSettings(const sfRenderWindow* renderWindow);

////////////////////////////////////////////////////////////
/// \brief Pop the event on top of event queue, if any, and return it
///
/// This function is not blocking: if there's no pending event then
/// it will return false and leave \a event unmodified.
/// Note that more than one event may be present in the event queue,
/// thus you should always call this function in a loop
/// to make sure that you process every pending event.
///
/// \param renderWindow Render window object
/// \param event        Event to fill, if any
///
/// \return true if an event was returned, or false if the event queue was empty
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API bool sfRenderWindow_pollEvent(sfRenderWindow* renderWindow, sfEvent* event);

////////////////////////////////////////////////////////////
/// \brief Wait for an event and return it
///
/// This function is blocking: if there's no pending event then
/// it will wait until an event is received or until the provided
/// timeout elapses. Only if an error or a timeout occurs the
/// function returns `false`.
/// This function is typically used when you have a thread that is
/// dedicated to events handling: you want to make this thread sleep
/// as long as no new event is received.
/// \code
/// while (sfRenderWindow_waitEvent(renderWindow, timeout, &event))
/// {
///    // process event...
/// }
/// \endcode
///
/// \param renderWindow Render window object
/// \param timeout      Maximum time to wait (`sfTime_Zero` for infinite)
/// \param event        Event to fill, if any
///
/// \return true if an event was returned, false if event queue was empty or function timed out
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API bool sfRenderWindow_waitEvent(sfRenderWindow* renderWindow, sfTime timeout, sfEvent* event);

////////////////////////////////////////////////////////////
/// \brief Get the position of a render window
///
/// \param renderWindow Render window object
///
/// \return Position in pixels
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfVector2i sfRenderWindow_getPosition(const sfRenderWindow* renderWindow);

////////////////////////////////////////////////////////////
/// \brief Change the position of a render window on screen
///
/// Only works for top-level windows
///
/// \param renderWindow Render window object
/// \param position     New position, in pixels
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderWindow_setPosition(sfRenderWindow* renderWindow, sfVector2i position);

////////////////////////////////////////////////////////////
/// \brief Get the size of the rendering region of a render window
///
/// \param renderWindow Render window object
///
/// \return Size in pixels
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfVector2u sfRenderWindow_getSize(const sfRenderWindow* renderWindow);

////////////////////////////////////////////////////////////
/// \brief Tell if the render window will use sRGB encoding when drawing on it
///
/// \param renderWindow Render window object
///
/// \return true if the render window use sRGB encoding, false otherwise
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API bool sfRenderWindow_isSrgb(const sfRenderWindow* renderWindow);

////////////////////////////////////////////////////////////
/// \brief Change the size of the rendering region of a render window
///
/// \param renderWindow Render window object
/// \param size         New size, in pixels
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderWindow_setSize(sfRenderWindow* renderWindow, sfVector2u size);

////////////////////////////////////////////////////////////
/// \brief Set the minimum window rendering region size
///
/// Pass a `NULL` vector to unset the minimum size
///
/// \param renderWindow Render window object
/// \param minimumSize  New minimum size, in pixels
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderWindow_setMinimumSize(sfRenderWindow* renderWindow, const sfVector2u* minimumSize);

////////////////////////////////////////////////////////////
/// \brief Set the maximum window rendering region size
///
/// Pass a `NULL` vector to unset the maximum size
///
/// \param renderWindow Render window object
/// \param maximumSize  New maximum size, in pixels
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderWindow_setMaximumSize(sfRenderWindow* renderWindow, const sfVector2u* maximumSize);

////////////////////////////////////////////////////////////
/// \brief Change the title of a render window
///
/// \param renderWindow Render window object
/// \param title        New title
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderWindow_setTitle(sfRenderWindow* renderWindow, const char* title);

////////////////////////////////////////////////////////////
/// \brief Change the title of a render window (with a UTF-32 string)
///
/// \param renderWindow Render window object
/// \param title        New title
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderWindow_setUnicodeTitle(sfRenderWindow* renderWindow, const sfChar32* title);

////////////////////////////////////////////////////////////
/// \brief Change a render window's icon
///
/// \param renderWindow Render window object
/// \param size         Icon's size, in pixels
/// \param pixels       Pointer to the pixels in memory, format must be RGBA 32 bits
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderWindow_setIcon(sfRenderWindow* renderWindow, sfVector2u size, const uint8_t* pixels);

////////////////////////////////////////////////////////////
/// \brief Show or hide a render window
///
/// \param renderWindow Render window object
/// \param visible      true to show the window, false to hide it
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderWindow_setVisible(sfRenderWindow* renderWindow, bool visible);

////////////////////////////////////////////////////////////
/// \brief Enable / disable vertical synchronization on a render window
///
/// \param renderWindow Render window object
/// \param enabled      true to enable v-sync, false to deactivate
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderWindow_setVerticalSyncEnabled(sfRenderWindow* renderWindow, bool enabled);

////////////////////////////////////////////////////////////
/// \brief Show or hide the mouse cursor on a render window
///
/// \param renderWindow Render window object
/// \param show         true to show, false to hide
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderWindow_setMouseCursorVisible(sfRenderWindow* renderWindow, bool show);

////////////////////////////////////////////////////////////
/// \brief Grab or release the mouse cursor
///
/// If set, grabs the mouse cursor inside this window's client
/// area so it may no longer be moved outside its bounds.
/// Note that grabbing is only active while the window has
/// focus and calling this function for fullscreen windows
/// won't have any effect (fullscreen windows always grab the
/// cursor).
///
/// \param renderWindow Render window object
/// \param grabbed      true to enable, false to disable
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderWindow_setMouseCursorGrabbed(sfRenderWindow* renderWindow, bool grabbed);

////////////////////////////////////////////////////////////
/// \brief Set the displayed cursor to a native system cursor
///
/// Upon window creation, the arrow cursor is used by default.
///
/// \warning The cursor must not be destroyed while in use by
///          the window.
///
/// \warning Features related to Cursor are not supported on
///          iOS and Android.
///
/// \param renderWindow Render window object
/// \param cursor       Native system cursor type to display
///
/// \see sfCursor_createFromSystem
/// \see sfCursor_createFromPixels
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderWindow_setMouseCursor(sfRenderWindow* renderWindow, const sfCursor* cursor);

////////////////////////////////////////////////////////////
/// \brief Enable or disable automatic key-repeat for keydown events
///
/// Automatic key-repeat is enabled by default
///
/// \param renderWindow Render window object
/// \param enabled      true to enable, false to disable
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderWindow_setKeyRepeatEnabled(sfRenderWindow* renderWindow, bool enabled);

////////////////////////////////////////////////////////////
/// \brief Limit the framerate to a maximum fixed frequency for a render window
///
/// \param renderWindow Render window object
/// \param limit        Framerate limit, in frames per seconds (use 0 to disable limit)
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderWindow_setFramerateLimit(sfRenderWindow* renderWindow, unsigned int limit);

////////////////////////////////////////////////////////////
/// \brief Change the joystick threshold, ie. the value below which no move event will be generated
///
/// \param renderWindow Render window object
/// \param threshold    New threshold, in range [0, 100]
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderWindow_setJoystickThreshold(sfRenderWindow* renderWindow, float threshold);

////////////////////////////////////////////////////////////
/// \brief Activate or deactivate a render window as the current target for rendering
///
/// \param renderWindow Render window object
/// \param active       true to activate, false to deactivate
///
/// \return True if operation was successful, false otherwise
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API bool sfRenderWindow_setActive(sfRenderWindow* renderWindow, bool active);

///////////////////////////////////////////////////////////
/// \brief Request the current render window to be made the active
/// foreground window
///
/// At any given time, only one window may have the input focus
/// to receive input events such as keystrokes or mouse events.
/// If a window requests focus, it only hints to the operating
/// system, that it would like to be focused. The operating system
/// is free to deny the request.
/// This is not to be confused with sfWindow_setActive().
///
///////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderWindow_requestFocus(sfRenderWindow* renderWindow);

////////////////////////////////////////////////////////////
/// \brief Check whether the render window has the input focus
///
/// At any given time, only one window may have the input focus
/// to receive input events such as keystrokes or most mouse
/// events.
///
/// \return True if window has focus, false otherwise
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API bool sfRenderWindow_hasFocus(const sfRenderWindow* renderWindow);

////////////////////////////////////////////////////////////
/// \brief Display a render window on screen
///
/// \param renderWindow Render window object
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderWindow_display(sfRenderWindow* renderWindow);

////////////////////////////////////////////////////////////
/// \brief Retrieve the OS-specific handle of a render window
///
/// \param renderWindow Render window object
///
/// \return Window handle
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfWindowHandle sfRenderWindow_getNativeHandle(const sfRenderWindow* renderWindow);

////////////////////////////////////////////////////////////
/// \brief Clear a render window with the given color
///
/// \param renderWindow Render window object
/// \param color        Fill color
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderWindow_clear(sfRenderWindow* renderWindow, sfColor color);

////////////////////////////////////////////////////////////
/// \brief Clear the stencil buffer to a specific value
///
/// The specified value is truncated to the bit width of
/// the current stencil buffer.
///
/// \param renderWindow Render window object
/// \param stencilValue Stencil value to clear to
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderWindow_clearStencil(sfRenderWindow* renderWindow, sfStencilValue stencilValue);

////////////////////////////////////////////////////////////
/// \brief Clear the entire target with a single color and stencil value
///
/// The specified stencil value is truncated to the bit
/// width of the current stencil buffer.
///
/// \param renderWindow Render window object
/// \param color        Fill color to use to clear the render target
/// \param stencilValue Stencil value to clear to
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderWindow_clearColorAndStencil(sfRenderWindow* renderWindow, sfColor color, sfStencilValue stencilValue);

////////////////////////////////////////////////////////////
/// \brief Change the current active view of a render window
///
/// \param renderWindow Render window object
/// \param view         Pointer to the new view
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderWindow_setView(sfRenderWindow* renderWindow, const sfView* view);

////////////////////////////////////////////////////////////
/// \brief Get the current active view of a render window
///
/// \param renderWindow Render window object
///
/// \return Current active view
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API const sfView* sfRenderWindow_getView(const sfRenderWindow* renderWindow);

////////////////////////////////////////////////////////////
/// \brief Get the default view of a render window
///
/// \param renderWindow Render window object
///
/// \return Default view of the render window
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API const sfView* sfRenderWindow_getDefaultView(const sfRenderWindow* renderWindow);

////////////////////////////////////////////////////////////
/// \brief Get the viewport of a view applied to this target
///
/// \param renderWindow Render window object
/// \param view         Target view
///
/// \return Viewport rectangle, expressed in pixels in the current target
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfIntRect sfRenderWindow_getViewport(const sfRenderWindow* renderWindow, const sfView* view);

////////////////////////////////////////////////////////////
/// \brief Get the scissor rectangle of a view, applied to this render target
///
/// The scissor rectangle is defined in the view as a ratio. This
/// function simply applies this ratio to the current dimensions
/// of the render target to calculate the pixels rectangle
/// that the scissor rectangle actually covers in the target.
///
/// \param renderWindow Render window object
/// \param view         The view for which we want to compute the scissor rectangle
///
/// \return Scissor rectangle, expressed in pixels
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfIntRect sfRenderWindow_getScissor(const sfRenderWindow* renderWindow, const sfView* view);

////////////////////////////////////////////////////////////
/// \brief Convert a point from window coordinates to world coordinates
///
/// This function finds the 2D position that matches the
/// given pixel of the render-window. In other words, it does
/// the inverse of what the graphics card does, to find the
/// initial position of a rendered pixel.
///
/// Initially, both coordinate systems (world units and target pixels)
/// match perfectly. But if you define a custom view or resize your
/// render-window, this assertion is not true anymore, ie. a point
/// located at (10, 50) in your render-window may map to the point
/// (150, 75) in your 2D world -- if the view is translated by (140, 25).
///
/// This function is typically used to find which point (or object) is
/// located below the mouse cursor.
///
/// This version uses a custom view for calculations, see the other
/// overload of the function if you want to use the current view of the
/// render-window.
///
/// \param renderWindow Render window object
/// \param point Pixel to convert
/// \param view The view to use for converting the point
///
/// \return The converted point, in "world" units
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfVector2f
    sfRenderWindow_mapPixelToCoords(const sfRenderWindow* renderWindow, sfVector2i point, const sfView* view);

////////////////////////////////////////////////////////////
/// \brief Convert a point from world coordinates to window coordinates
///
/// This function finds the pixel of the render-window that matches
/// the given 2D point. In other words, it goes through the same process
/// as the graphics card, to compute the final position of a rendered point.
///
/// Initially, both coordinate systems (world units and target pixels)
/// match perfectly. But if you define a custom view or resize your
/// render-window, this assertion is not true anymore, ie. a point
/// located at (150, 75) in your 2D world may map to the pixel
/// (10, 50) of your render-window -- if the view is translated by (140, 25).
///
/// This version uses a custom view for calculations, see the other
/// overload of the function if you want to use the current view of the
/// render-window.
///
/// \param renderWindow Render window object
/// \param point Point to convert
/// \param view The view to use for converting the point
///
/// \return The converted point, in target coordinates (pixels)
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfVector2i
    sfRenderWindow_mapCoordsToPixel(const sfRenderWindow* renderWindow, sfVector2f point, const sfView* view);

////////////////////////////////////////////////////////////
/// \brief Draw a drawable object to the render-target
///
/// \param renderWindow render window object
/// \param object       Object to draw
/// \param states       Render states to use for drawing (NULL to use the default states)
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderWindow_drawSprite(sfRenderWindow*       renderWindow,
                                                  const sfSprite*       object,
                                                  const sfRenderStates* states);
CSFML_GRAPHICS_API void sfRenderWindow_drawText(sfRenderWindow* renderWindow, const sfText* object, const sfRenderStates* states);
CSFML_GRAPHICS_API void sfRenderWindow_drawShape(sfRenderWindow* renderWindow, const sfShape* object, const sfRenderStates* states);
CSFML_GRAPHICS_API void sfRenderWindow_drawCircleShape(sfRenderWindow*       renderWindow,
                                                       const sfCircleShape*  object,
                                                       const sfRenderStates* states);
CSFML_GRAPHICS_API void sfRenderWindow_drawConvexShape(sfRenderWindow*       renderWindow,
                                                       const sfConvexShape*  object,
                                                       const sfRenderStates* states);
CSFML_GRAPHICS_API void sfRenderWindow_drawRectangleShape(sfRenderWindow*         renderWindow,
                                                          const sfRectangleShape* object,
                                                          const sfRenderStates*   states);
CSFML_GRAPHICS_API void sfRenderWindow_drawVertexArray(sfRenderWindow*       renderWindow,
                                                       const sfVertexArray*  object,
                                                       const sfRenderStates* states);
CSFML_GRAPHICS_API void sfRenderWindow_drawVertexBuffer(sfRenderWindow*       renderWindow,
                                                        const sfVertexBuffer* object,
                                                        const sfRenderStates* states);

////////////////////////////////////////////////////////////
/// \brief Draw primitives defined by a vertex buffer.
///
/// \param renderWindow Render window object
/// \param object       Vertex buffer object to draw
/// \param firstVertex  Index of the first vertex to render
/// \param vertexCount  Number of vertices to render
/// \param states       Render states to use for drawing
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderWindow_drawVertexBufferRange(
    sfRenderWindow*       renderWindow,
    const sfVertexBuffer* object,
    size_t                firstVertex,
    size_t                vertexCount,
    const sfRenderStates* states);

////////////////////////////////////////////////////////////
/// \brief Draw primitives defined by an array of vertices to a render window
///
/// \param renderWindow render window object
/// \param vertices     Pointer to the vertices
/// \param vertexCount  Number of vertices in the array
/// \param type         Type of primitives to draw
/// \param states       Render states to use for drawing (NULL to use the default states)
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderWindow_drawPrimitives(
    sfRenderWindow*       renderWindow,
    const sfVertex*       vertices,
    size_t                vertexCount,
    sfPrimitiveType       type,
    const sfRenderStates* states);

////////////////////////////////////////////////////////////
/// \brief Save the current OpenGL render states and matrices
///
/// This function can be used when you mix SFML drawing
/// and direct OpenGL rendering. Combined with popGLStates,
/// it ensures that:
/// \li SFML's internal states are not messed up by your OpenGL code
/// \li your OpenGL states are not modified by a call to a SFML function
///
/// Note that this function is quite expensive: it saves all the
/// possible OpenGL states and matrices, even the ones you
/// don't care about. Therefore it should be used wisely.
/// It is provided for convenience, but the best results will
/// be achieved if you handle OpenGL states yourself (because
/// you know which states have really changed, and need to be
/// saved and restored). Take a look at the resetGLStates
/// function if you do so.
///
/// \param renderWindow render window object
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderWindow_pushGLStates(sfRenderWindow* renderWindow);

////////////////////////////////////////////////////////////
/// \brief Restore the previously saved OpenGL render states and matrices
///
/// See the description of pushGLStates to get a detailed
/// description of these functions.
///
/// \param renderWindow render window object
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderWindow_popGLStates(sfRenderWindow* renderWindow);

////////////////////////////////////////////////////////////
/// \brief Reset the internal OpenGL states so that the target is ready for drawing
///
/// This function can be used when you mix SFML drawing
/// and direct OpenGL rendering, if you choose not to use
/// pushGLStates/popGLStates. It makes sure that all OpenGL
/// states needed by SFML are set, so that subsequent sfRenderWindow_draw*()
/// calls will work as expected.
///
/// \param renderWindow render window object
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfRenderWindow_resetGLStates(sfRenderWindow* renderWindow);

////////////////////////////////////////////////////////////
/// \brief Get the current position of the mouse relative to a render-window
///
/// This function returns the current position of the mouse
/// cursor relative to the given render-window, or desktop if NULL is passed.
///
/// \param relativeTo Reference window
///
/// \return Position of the mouse cursor, relative to the given render window
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfVector2i sfMouse_getPositionRenderWindow(const sfRenderWindow* relativeTo);

////////////////////////////////////////////////////////////
/// \brief Set the current position of the mouse relative to a render window
///
/// This function sets the current position of the mouse
/// cursor relative to the given render-window, or desktop if NULL is passed.
///
/// \param position   New position of the mouse
/// \param relativeTo Reference window
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfMouse_setPositionRenderWindow(sfVector2i position, const sfRenderWindow* relativeTo);

////////////////////////////////////////////////////////////
/// \brief Get the current position of a touch in window coordinates
///
/// This function returns the current touch position
/// relative to the given render window, or desktop if NULL is passed.
///
/// \param finger Finger index
/// \param relativeTo Reference window
///
/// \return Current position of \a finger, or undefined if it's not down
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfVector2i sfTouch_getPositionRenderWindow(unsigned int finger, const sfRenderWindow* relativeTo);

////////////////////////////////////////////////////////////
/// \brief Create a Vulkan rendering surface
///
/// \param renderWindow RenderWindow object
/// \param instance     Vulkan instance
/// \param surface      Created surface
/// \param allocator    Allocator to use
///
/// \return True if surface creation was successful, false otherwise
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API bool sfRenderWindow_createVulkanSurface(
    sfRenderWindow*              renderWindow,
    const VkInstance*            instance,
    VkSurfaceKHR*                surface,
    const VkAllocationCallbacks* allocator);
