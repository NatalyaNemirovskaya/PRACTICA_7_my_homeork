#include <iostream>
#include "export.h"


//2 вариант, когда нет заголовочного файла
/*
#ifdef MATH_DOUBLE_PREC_DEFINE
typedef double real;
#else
typedef double real;
#endif 
*/

typedef double real;

struct Matrix;

#ifdef __cplusplus
extern "C"
{
#endif

extern Matrix*  MATRIXLIB_EXPORT math_createMatrix(int, int);
extern void MATRIXLIB_EXPORT math_set(Matrix* M, int, int, double);
extern real MATRIXLIB_EXPORT math_get(const Matrix* M, int row, int col);
extern void  MATRIXLIB_EXPORT  math_print(Matrix*);
extern void  MATRIXLIB_EXPORT math_deleteMatrix(Matrix*);
extern Matrix* MATRIXLIB_EXPORT math_add_assign(Matrix* A, const Matrix* M);
extern Matrix* MATRIXLIB_EXPORT math_sub_assign(Matrix* A, const Matrix* M);
extern Matrix* MATRIXLIB_EXPORT math_mul_assign(Matrix* A, const Matrix* M);
extern int MATRIXLIB_EXPORT get_n_cols(const Matrix*  A) ;
extern int MATRIXLIB_EXPORT  get_n_rows(const Matrix*  A) ;

extern std::ostream&  MATRIXLIB_EXPORT  math_output(std::ostream& os, const Matrix* M);


extern std::istream& MATRIXLIB_EXPORT math_input(std::istream& in, Matrix* M,int row, int col);



#ifdef __cplusplus
}
#endif




int main()
{
  
    Matrix* m= math_createMatrix(3, 3);
    math_set(m, 0, 0, 1.0);
    math_set(m, 1 ,1, 1);
    std::cout << "Matrix m is " << std::endl;
    math_print(m);
    
    Matrix* m1= math_createMatrix(3, 3);
    math_set(m1, 0, 0, 1);
    math_set(m1, 1 ,1, 2);   

    std::cout << "Matrix m1 is " << std::endl;
    math_print(m1);

     std::cout << "Matrix m= m+=m1 is " << std::endl;
    math_add_assign(m,m1);
    math_print(m);


    math_sub_assign(m,m1);
     std::cout << "Matrix m-=m1 is " << std::endl;
     math_print(m);
    
    math_mul_assign(m,m1);
     std::cout << "Matrix m*=m1 is " << std::endl;
     math_print(m);

     int j=get_n_rows(m);
     std::cout << "number of lines in m is " <<  j <<std::endl;

     j=get_n_cols(m);
     std::cout << "number of columns in m is " <<  j <<std::endl;

    math_output(std::cout, m);

    math_input(std::cin, m, 2,2);
    int d =math_get(m, 2, 2);
    std::cout << "Matrix m(2,2) is " << d << std::endl;

    math_output(std::cout, m);

    std::cout <<  math_get(m, 1, 1);

    Matrix* m2= math_createMatrix(3, 3);
    math_set(m2, 0, 0, 1);
    math_set(m2, 1 ,1, 3);
    std::cout << "Matrix m2 is " << std::endl;
    math_print(m2);
    
    math_add_assign(m,m1);
    std::cout << "Matrix m+=m1 is " << std::endl;
    math_print(m);



    math_deleteMatrix(m); 
    math_deleteMatrix(m1); 
    math_deleteMatrix(m2); 

    return 0;
}
