#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include "util/limine.h"
#include "util/limine_attr.h"
#include "flanterm/flanterm.h"
#include "flanterm/flanterm_backends/fb.h"

#include "screen/screen.h"

// Halt and catch fire function.
static void hcf(void) {
    for (;;) {
        __asm__("hlt");
    }
}

// The following will be our kernel's entry point.
// If renaming kmain() to something else, make sure to change the
// linker script accordingly.
void kmain(void) {
    // Ensure the bootloader actually understands our base revision (see spec).
    if (LIMINE_BASE_REVISION_SUPPORTED == false) {
        hcf();
    }

    // Ensure we got a framebuffer.
    if (framebuffer_request.response == NULL
     || framebuffer_request.response->framebuffer_count < 1) {
        hcf();
    }

    // Fetch the first framebuffer.
    struct limine_framebuffer *framebuffer = framebuffer_request.response->framebuffers[0];

    struct flanterm_context *ft_ctx = flanterm_fb_init(
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

    screen_draw(framebuffer, ft_ctx);

    // We're done, just hang...
    hcf();
}
