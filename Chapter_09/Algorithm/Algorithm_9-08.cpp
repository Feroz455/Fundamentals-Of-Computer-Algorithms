/*
Page 452
Algorithm 9.8 Recursive fast fourier transform

Algorithm FFT(N, a(x), w, A)
//N = 2^m, a(x) = aN-1x^N-1+ . . . .+ . . + a0 and w is a
//primitive Nth root of unity A[):N-1] is set to the values
//a(w^3), 0 <= j <= N - 1;
{
    //b and c are polynomials
    //BC and wp are complex arrays
    if (N == 1 )
        A[0] = a0;
    else
    {
        n = N / 2;
        b(x) = a[N-2]x^n-1 + ....... + a[2]x + a[0];
        c(x) = a[N-2]x^n-1 + ....... + a[2]x + a[0];
        FFT (n , b(x), w^2, B);
        FFT(n, c(x), w^2, C);
        wp[-1] = 1 / w;
        for(j = 0 to n -1 do)
        {
            wp[j] = w * wp[j -1];
            A[j] = B[j] + wp[j] * C[j];
            A[j+n] = B[j] - wp [j] * C[j];
        }
    }

}
*/
/*****************************************************************************/
/*!
reference:  http://www.deepakchennakkadan.com/recursive-fast-fourier-transform.html
\Name   Recursive Fast Fourier Transform
\Author Deepak Chennakkadan
\Input  <N> <FILENAME>
        <N>: Number of input Complex Numbers
        <FILENAME>: Text file containing the Complex Numbers
\Output Prints the FFT Output
*/
/*****************************************************************************/

#include <fstream>
#include <complex>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <sys/time.h>

using namespace std;

const double PI = 4.0f * atan(1.0f);
const double TWOPI = 2.0f * PI;

/***************************************************************************/
/*!
\Brief  Overloaded operator to format Complex Number output
*/
/***************************************************************************/
ostream &operator<<(ostream &out, complex<double> c)
{
    if (c.imag() < 0)
    {
        out << c.real() << c.imag() << "i";
    }
    else
    {
        out << c.real() << "+" << c.imag() << "i";
    }
    return out;
}

/***************************************************************************/
/*!
\Brief  Function to calculate elapsed program time
*/
/***************************************************************************/
float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

/***************************************************************************/
/*!
\Brief  Function to calculate the FFT for given N samples
*/
/***************************************************************************/
void fft(complex<double> *input, complex<double> *output, int N, int step)
{
    if (step < N)
    {
        // Recursive Functionality
        fft(output, input, N, step * 2);
        fft(output + step, input + step, N, step * 2);

        // For loop for k cycles
        for (int k = 0; k < N; k += 2 * step)
        {
            double angle = -PI * k / N;
            double realPart, imagPart;

            // Calculating the Complex Sum
            realPart = output[k + step].real() * cos(angle) - output[k + step].imag() * sin(angle);
            imagPart = output[k + step].real() * sin(angle) + output[k + step].imag() * cos(angle);

            complex<double> out(realPart, imagPart);

            input[k / 2] = output[k] + out;
            input[(k + N) / 2] = output[k] - out;
        }
    }
}

/***************************************************************************/
/*!
\Brief  Main Function
*/
/***************************************************************************/
int main(int argc, char *argv[])
{
    struct timeval t0;
    struct timeval t1;
    float elapsed;

    gettimeofday(&t0, 0);

    int N;
    sscanf(argv[1], "%d", &N);

    complex<double> *buffer;
    buffer = new complex<double>[N];

    complex<double> *outputs;
    outputs = new complex<double>[N];

    ifstream f1(argv[2]);

    // For loop to read in Complex Number Samples
    for (int i = 0; i < N; i++)
    {
        if (f1)
        {
            char buf[50];
            f1.getline(buf, 50);
            double d1 = 0, d2 = 0;
            sscanf(buf, "%lf %lf", &d1, &d2);
            complex<double> c1(d1, d2);
            buffer[i] = c1;
        }
    }

    cout << setprecision(4);

    for (int i = 0; i < N; i++)
    {
        outputs[i] = buffer[i];
    }

    // Calculate FFT
    fft(buffer, outputs, N, 1);

    // Print out the output
    for (int i = 0; i < N; i++)
    {
        std::cout << buffer[i] << std::endl;
    }

    delete[] buffer;

    // Time Stuff
    gettimeofday(&t1, 0);
    elapsed = timedifference_msec(t0, t1);
    printf("\nCode executed in %f milliseconds.\n", elapsed);

    return 0;
}