#include "screen.h"

static size_t color = 0xffffff;

void screen_draw_bg(struct limine_framebuffer *framebuffer, struct flanterm_context *ft_ctx) {
    for (size_t y = 0; y < framebuffer->height; y++) {
        for (size_t x = 0; x < framebuffer->width; x++) {
            volatile uint32_t *fb_ptr = framebuffer->address;
            size_t width = framebuffer->pitch / 4;
            fb_ptr[y * width + x] = color;
         }
    }

    color = !color;
}

void screen_draw(struct limine_framebuffer *framebuffer, struct flanterm_context *ft_ctx) {
    screen_draw_bg(framebuffer, ft_ctx);

    const char msg[] = "beans\n";
    flanterm_write(ft_ctx, msg, sizeof(msg));

    // Note: we assume the framebuffer model is RGB with 32-bit pixels.
    /*
    for (size_t i = 0; i < 768; i++) {
        volatile uint32_t *fb_ptr = framebuffer->address;
        fb_ptr[i * (framebuffer->pitch / 4) + i] = 0x8d3f50;
    }
    */
}
