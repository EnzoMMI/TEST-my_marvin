/*
** EPITECH PROJECT, 2022
** B-CPE-100-STG-1-1-cpoolday04-enzo.tiroumalle
** File description:
** my_getnbr
*/

int my_getnbr(char const *str)
{
    int sign = 1;
    int i = 0;
    long long int result = 0;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            sign = -sign;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10;
        result += str[i] - '0';
        i++;
    }
    if (result * sign > 2147483647 || result * sign < -2147483648)
        return 0;
    return (int)result * sign;
}
