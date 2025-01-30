/* A program to compute the greatest common divisor (GCD)
   using Euclid's algorithm */

int gcd(int u, int v)
{
    if (v == 0)
        return u;
    else
        return gcd(v, u % v);
}

void main(void)
{
    int x, y;
    x = input();
    y = input();
    output(gcd(x, y));
}

