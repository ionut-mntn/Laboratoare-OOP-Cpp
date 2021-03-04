//
// Created by User on 3/5/2020.
//

#ifndef LAB2_COMPLEX_H
#define LAB2_COMPLEX_H

class Complex{
private:
    double re;
    double im;

public:

    /*
     * Constructor
     */
    Complex(double re, double im);

    /*
     * Returns the real part of the complex number.
     */
    double show_real();

    /*
     * Returns the imaginary part of the complex number
     */
    double show_im();
}
#endif //LAB2_COMPLEX_H
