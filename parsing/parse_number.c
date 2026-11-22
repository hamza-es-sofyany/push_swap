
#include "../push_swap.h"

static unsigned long long get_limit(int sign)
{
    if (sign == -1)
        return ((unsigned long long)(-(long long)INT_MIN));
    return ((unsigned long long)INT_MAX);
}

static int check_overflow(const char *str, int i,
        unsigned long long limit)
{
    unsigned long long value;
    int digit;

    value = 0;
    while (str[i] >= '0' && str[i] <= '9')
    {
        digit = str[i] - '0';
        if (value > (limit - digit) / 10)
            return (0);
        value = value * 10 + digit;
        i++;
    }
    if (str[i] != '\0')
        return (0);
    return (1);
}

int parse_number(const char *str, int *number)
{
    int i;
    int sign;
    unsigned long long limit;

    if (!str || !number)
        return (0);
    i = 0;
    sign = 1;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    if (!str[i])
        return (0);
    limit = get_limit(sign);
    if (!check_overflow(str, i, limit))
        return (0);
    *number = ft_atoi(str);
    return (1);
}
