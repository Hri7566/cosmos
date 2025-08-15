#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include "util/limine.h"
#include "util/limine_attr.h"

#include "screen/screen.h"
#include "util/print.h"

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
    //screen_init(framebuffer);

    print_ft_ctx = get_context(framebuffer);

    const char msg[] = "i am a penguin imposter\n";
    print(msg);
    //flanterm_write(print_ft_ctx, msg, sizeof(msg));

    // We're done, just hang...
    hcf();
}
