#include "../includes/push_swap.h"

int *transform(int argc, char **argv)
{
    int *data;
    int *data2;

    data = (int *)malloc(sizeof(int) * (argc - 1));
    if (!data)
        return NULL;

    data2 = (int *)malloc(sizeof(int) * (argc - 1));
    if (!data2)
    {
        free(data);
        return NULL;
    }

    fillDataArray(argc, argv, data);
    calculateNewDataArray(data, data2, argc - 1);

    free(data);

    return data2;
}
