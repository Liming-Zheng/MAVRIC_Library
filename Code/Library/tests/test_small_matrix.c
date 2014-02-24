#include "test_small_matrix.h"

#include "small_matrix.h"
#include "linear_algebra.h"
#include "print_util.h"

bool run_matrix_tests(void) {
	
	matrix_2x2_t m2={.v={{1, 2},{7,13},{3,2}}};
	print_matrix(get_debug_stream(), m2.v, 2, 2, 2); dbg_print("\n");
	
	matrix_2x2_t m2t=trans2(m2);
	print_matrix(get_debug_stream(), m2t.v, 2, 2, 2); dbg_print("\n");
	
	matrix_2x2_t m2i=inv2(m2);
	print_matrix(get_debug_stream(), m2i.v, 2, 2, 2); dbg_print("\n");
	print_matrix(get_debug_stream(), madd2(m2, m2t).v, 2, 2, 2); dbg_print("\n");
	
	matrix_2x2_t m2_=mmul2(m2, m2i);
	print_matrix(get_debug_stream(), m2_.v, 2, 2, 2); dbg_print("\n");

	
	matrix_3x3_t m3={.v={{1, 2, 4},{2,4,2},{4,2,1}}};
	
	print_matrix(get_debug_stream(), m3.v, 3, 3, 2); dbg_print("\n");
	
	matrix_3x3_t m3d=diag_3x3(row3(m3, 0));
	print_matrix(get_debug_stream(), m3d.v, 3, 3, 2); dbg_print("\n");
	
	matrix_3x3_t m3t=trans3(m3);
	print_matrix(get_debug_stream(), m3t.v, 3, 3, 2); dbg_print("\n");
	
	matrix_3x3_t m3i=inv3(m3);
	print_matrix(get_debug_stream(), m3i.v, 3, 3, 2); dbg_print("\n");
	
	matrix_3x3_t m3_=mmul3(m3, m3i);
	m3_=mmul3(m3, inv3(m3));
	print_matrix(get_debug_stream(), m3_.v, 3, 3, 2); dbg_print("\n");
	
	
	matrix_4x4_t m4={.v={{1, 2, 3, 4},{2,4,2, 4},{4,3,2,1}, {5,6,7,5}}};
	print_matrix(get_debug_stream(), m4.v, 4, 4, 2); dbg_print("\n");
	
	matrix_4x4_t m4t=trans4(m4);
	print_matrix(get_debug_stream(), m4t.v, 4, 4, 2); dbg_print("\n");
	
	matrix_4x4_t m4i=inv4(m4);
	print_matrix(get_debug_stream(), m4i.v, 4, 4, 2); dbg_print("\n");
	
	matrix_4x4_t m4_=mmul4(m4, m4i);
	print_matrix(get_debug_stream(), m4_.v, 4, 4, 2); dbg_print("\n");
	
	
	vector_3_t v1={.v={2,4,7}};
	print_matrix(get_debug_stream(), v1.v, 1, 3, 2); dbg_print("\n");
//	print_matrix(get_debug_stream(), mvmul3(ident_3x3, v1).v, 1, 3, 2); dbg_print("\n");
//	print_matrix(get_debug_stream(), tp3(v1, v1).v, 3, 3, 2); dbg_print("\n");
	
	dbg_print("squared Norm m3:  "); dbg_putfloat(sqr_f_norm3(m3), 4);dbg_print("\n");
	dbg_print("trace m3:         "); dbg_putfloat(trace3(m3), 4);dbg_print("\n");
	dbg_print("residual |MxM^{-1} - I| "); dbg_putfloat(sqr_f_norm3(msub3(mmul3(m3, inv3(m3)), ident_3x3)), 10);dbg_print("\n");
	
	
	return true;
}