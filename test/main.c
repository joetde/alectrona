
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h> // sleep
#include <alectrona/alectrona.h>

#define DEFINE_MONTECARLO(func_name) \
    int func_name##_dist(void) \
    { \
        bool match = false; \
        int rx; \
        while (!match) { \
            rx = rand() % 100; \
            int ry = rand() % 100; \
            if (ry <= func_name(rx)) { \
                match = true; \
            } \
        } \
        return rx; \
    } \

int gaussian(int x) {
    double c = 17;
    return 100 * exp(- (x - 50) * (x - 50) / (2 * c * c));
}

int linear(int x) { return x; }

DEFINE_MONTECARLO(gaussian)
DEFINE_MONTECARLO(linear)

int main(void)
{
    alectrona_start_display();
    for (int i=0; i<1000000; i++) { alectrona_feed_one(gaussian_dist()); usleep(5); }
    usleep(1000000);
    alectrona_finish();

    /*for (int i=0; i<100; i++) {
        printf("%d -> %d\n", i, gaussian(i));
    }*/
    return 0;
}

