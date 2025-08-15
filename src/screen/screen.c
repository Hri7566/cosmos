#include "screen.h"
#include "../util/memutil.h"

typedef struct flanterm_context flanterm_context;

void screen_init(struct limine_framebuffer *framebuffer) {
    struct flanterm_context *ctx = flanterm_fb_init(
            NULL,
            NULL,
            framebuffer->address, framebuffer->width, framebuffer->height, framebuffer->pitch,
            framebuffer->red_mask_size, framebuffer->red_mask_shift,
            framebuffer->green_mask_size, framebuffer->green_mask_shift,
            framebuffer->blue_mask_size, framebuffer->blue_mask_shift,
            NULL,
            NULL, NULL,
            NULL, NULL,
            NULL, NULL,
            NULL, 0, 0, 1,
            0, 0,
            0
        );

    // i think flanterm breaks here because the context is gone when we leave the function
    ft_ctx = ctx;
}

struct flanterm_context *get_context(struct limine_framebuffer *framebuffer) {
    return flanterm_fb_init(
            NULL,
            NULL,
            framebuffer->address, framebuffer->width, framebuffer->height, framebuffer->pitch,
            framebuffer->red_mask_size, framebuffer->red_mask_shift,
            framebuffer->green_mask_size, framebuffer->green_mask_shift,
            framebuffer->blue_mask_size, framebuffer->blue_mask_shift,
            NULL,
            NULL, NULL,
            NULL, NULL,
            NULL, NULL,
            NULL, 0, 0, 1,
            0, 0,
            0
        );
}

/*
static size_t color = 0x8d3f50;

void screen_draw_bg(struct limine_framebuffer *framebuffer, struct flanterm_context *ft_ctx) {
    for (size_t y = 0; y < framebuffer->height; y++) {
        for (size_t x = 0; x < framebuffer->width; x++) {
            volatile uint32_t *fb_ptr = framebuffer->address;
            size_t width = framebuffer->pitch / 4;
            fb_ptr[y * width + x] = color;
         }
    }
}

void screen_draw(struct limine_framebuffer *framebuffer, struct flanterm_context *ft_ctx) {
    screen_draw_bg(framebuffer, ft_ctx);

    const char msg[] = "beans\n";
    flanterm_write(ft_ctx, msg, sizeof(msg));
    flanterm_flush(ft_ctx);
}
*/
