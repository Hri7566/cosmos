#ifndef _COSMOS_SCREEN_H
#define _COSMOS_SCREEN_H

#include "../flanterm/flanterm.h"
#include "../util/limine.h"

void screen_draw(struct limine_framebuffer *framebuffer, struct flanterm_context *ft_ctx);

#endif
