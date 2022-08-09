#include<po13.h>

#include <pico/stdlib.h>

void test_pattern_0();
void test_pattern_1();

int main(int argc, char *argv[])
{
    //po13_demo();
    sleep_ms(100);
    po13_init();

    //test_pattern_0();
    test_pattern_1();

    while(1);
}

void test_pattern_0()
{
    struct po13_device *dev = po13_device_default();
    struct po13_ctx *render = dev->ctx;

    render->font->id = PO13_FONT_24;

    po13_draw_text(render, (struct po13_point2d){.x=0,.y=0},"BALLS");

    po13_display_update(dev);
}

void test_pattern_1()
{
    struct po13_device *dev = po13_device_default();
    struct po13_ctx *render = dev->ctx;

    render->font->id = PO13_FONT_24;

    struct po13_point2d origin = {.x=0,.y=0};

    while(1) {
        po13_draw_text(render, origin,"BALLS");

        po13_display_update(dev);
        sleep_ms(400);

        po13_draw_clear(render);
        po13_display_update(dev);
        sleep_ms(200);

        origin.y += 20;
        if(origin.y >= 44) {
            origin.y = 0;
        }
    }
}
