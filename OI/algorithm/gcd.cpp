int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int exgcd(int a, int b, int &d, int &x, int &y)
{
    if (b == 0)
    {
        d = a;
        x = 1;
        y = 0;
    }
    else
    {
        exgcd(b, a % b, d, y, x);
        y -= x * (a / b);
    }
}