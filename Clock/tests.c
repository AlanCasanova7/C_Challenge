#define SDL_MAIN_HANDLED
#include "aiv_unit_tests.h"
#include "math.h"

TEST(rotate)
{
    vector_2d_t *v = malloc(sizeof(vector_2d_t));
    v->x = 1;
    v->y = 0;

    RotateVector(v, (double)90);

	ASSERT_THAT((int)round(v->y) == 1);
}

TEST(rotate_around_point)
{
    vector_2d_t *v = malloc(sizeof(vector_2d_t));
    v->x = 1;
    v->y = 0;

    vector_2d_t *p = malloc(sizeof(vector_2d_t));
    p->x = 0;
    p->y = 0;

    RotateVectorAroundPoint(p, v, (double)90);

	ASSERT_THAT((int)round(v->y) == 1);
}

int main(int argc, char **argv)
{	
	RUN_TEST(rotate);
    RUN_TEST(rotate_around_point);
	PRINT_TEST_RESULTS();
	return 0;
}