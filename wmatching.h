/**Maximum weighted matching based on lemon c++
 * 
 * to use this file, please build and install lemon c++ library first!!
 *
 */

#ifdef __cplusplus
extern "C" {
#endif
int wmatch_gbp_int(int n, int m, int** weights, int *mate);
double wmatch_gbp_double(int n, int m, double** weights, int *mate);
int wmatch_sbp_int(int n, int** weights, int *mate);
double wmatch_sbp_double(int n, double** weights, int *mate);
#ifdef __cplusplus
}
#endif