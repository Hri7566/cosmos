#ifndef _COSMOS_SCREEN_H
#define _COSMOS_SCREEN_H

#include "../util/limine.h"
#include "../flanterm/flanterm.h"
#include "../flanterm/flanterm_backends/fb.h"

static struct flanterm_context *ft_ctx;

void screen_init(struct limine_framebuffer *framebuffer);
struct flanterm_context *get_context(struct limine_framebuffer *framebuffer);

#endif
