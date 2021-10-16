// Autor: J. F. Jimenez Barrera.
#define N 10
int array[N] = {7,34,62,73,94,104,305,693,843,961};

int dec_bin(int quotient, int remainder, int position, int binary)
{
    int aux;
    while (remainder >= 2)
    {
        remainder = remainder - 2;
        quotient++;
    }
    aux = remainder;
    for (int count = 0; count < position - 1; count++)
    {
        remainder = remainder + aux;
    }
    binary = binary + remainder;
    if (quotient != 0)
    {
        remainder = quotient;
        quotient = 0;
        aux = position;
        for (int count = 0; count < 9; count++)
        {
            position = position + aux;
        }
        binary = dec_bin(quotient, remainder, position, binary);
    }
    return binary;
}

int main()
{
    int quotient, remainder, binary, position;
    for (int i = 0; i < N; i++)
    {
        quotient = 0;
        remainder = array[i];
        position = 1;
        binary = 0;
        array[i] = dec_bin(quotient, remainder, position, binary);
    }
    return 0;
}